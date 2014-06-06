#include <stdio.h>

typedef struct point{
	int x;
	int y;
} point;
point Point_Default = {0,0};

int contains(point* visited,int size,point item)
{
	for(int i =0;i <size;i++)
		if(visited[i].x==item.x&&visited[i].y==item.y)return 1;
	return 0;
}

int main()
{
	FILE* fp = fopen("maze_ai.in","r");
	int length;
	int width;
	fscanf(fp,"%i %i",&width,&length);
	char buff[500];
	fgets(buff,500,fp);

	int map[length][width];
	point position = Point_Default;
	point target = Point_Default;
	for(int row = 0;row<length;row++)	
	{
		fgets(buff, width+2, fp);
		for(int i = 0;i<width;i++)
		{
			if(buff[i] == 'S')
			{
				position.x = i;
				position.y = row;
			}
			if(buff[i] == 'E')
			{
				target.x = i;
				target.y = row;
			}
			map[row][i] = buff[i] == '#';
		}
	}

	point stack[length*width];
	point* item = stack;
	*item = position;
	point visited[length*width];
	point* v = visited;
	*(v++) = position;
	while(item >= stack)
	{
		int dx;
		int dy;
		for(dx=-1;dx<=2;dx++)
		{
			if(dx==2)break;
			for(dy=-1;dy<=1;dy++)
			{
				if(dx==dy||dx*dy!=0)continue;
				point next = {item->x+dx,item->y+dy};
				if(!map[next.y][next.x] && !contains(visited,v-visited,next))
				{
					*(++item) = next;
					*(v++) = next;
					goto done;
				}
			}
		}
		done:
		if(dx==2)
		{
			item--;
		}else{
			if(item->x==target.x&&item->y==target.y)break;
		}
	}

	printf("%i,%i\n",item->x,item->y);
	for(;item>stack;item--)
	{
		map[item->y][item->x]=2;
	}
	map[item->y][item->x] = 2;

	char* pieces = " #*";

	for(int row=0;row<length;row++)
	{
		for(int col=0;col<width;col++)
			printf("%c",pieces[map[row][col]]);
		puts("");
	}

	return 0;
}


