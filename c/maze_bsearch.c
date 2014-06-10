#include <stdio.h>
#include <stdlib.h>

typedef struct point{
	int x;
	int y;
	struct point* prev;
} point;
point Point_Default = {0,0};

struct queue{
	int start;
	int end;
	int capacity;
	point* array;
};

int contains(point* visited,int size,point item)
{
	for(int i =0;i <size;i++)
		if(visited[i].x==item.x&&visited[i].y==item.y)return 1;
	return 0;
}

void enqueue(struct queue* items, point p)
{
	items->array[items->end] = p;
	items->end = (items->end +1)%items->capacity;
}

point dequeue(struct queue* items)
{
	point* p = items->array+items->start;
	items->start= (items->start+1)%items->capacity;
	return *p;
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
	position.prev = &Point_Default;
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

	point ary[length*width];

	struct queue items = {0,0,length,ary};

	enqueue(&items,position);

	point visited[length * width * 3];
	point* v = visited;
	*(v++) = position;
	point curr;

	do{
		curr = dequeue(&items);
		for(int dx =-1; dx<=1;dx++)
		{
			for(int dy=-1;dy<=1;dy++)
			{
				if(dx==dy||dx*dy!=0)continue;
				point next = {dx+curr.x,dy+curr.y};
				if(!map[next.y][next.x]&&!contains(visited,v-visited,next))
				{
					*(v++) = curr;
					next.prev = v-1;
					enqueue(&items,next);
				}
				*(v++) = next;
			}
		}
		if(curr.x==target.x&&curr.y==target.y)break;
	}while(items.start != items.end);
	
	map[curr.y][curr.x] = 2;
	while(curr.prev->x!=0)
	{
		curr = *curr.prev;
		map[curr.y][curr.x] = 2;
	}

	char* pieces = " #*";

	for(int row = 0;row<length;row++)
	{
		for(int col=0;col<width;col++)
			printf("%c",pieces[map[row][col]]);
		puts("");
	}


	return 0;
}
