#include <stdio.h>

typedef struct Point{
	int x;
	int y;
} Point;
const Point Point_Default = {0,0};

int main()
{
	FILE* fp = fopen("maze_ai.in","r");
	int length;
	int width;
	fscanf(fp,"%i %i",&width,&length);
	char buff[500];
	fgets(buff,500,fp);

	int map[length][width];
	Point position = Point_Default;
	Point target = Point_Default;
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
	Point moves[100];
	Point* move = moves;
	int dx;
	int dy;
	for(dx=-1;dx<1;dx++)
		for(dy=-1;dy<1;dy++)
			if(map[position.y+dy][position.x+dx])
			{
				move->x = dx;
				move->y = dy;
			}
	move++;

	while((position.x!=target.x || position.y!=target.y) && move < moves + 100)
	{
		Point direction = *(move-1);

		if(!map[direction.x + position.y][-direction.y + position.x])
		{
			Point right = {-direction.y,direction.x};
			direction = right;
		}else{
			if(map[direction.y + position.y][direction.x + position.x])
			{
				for(;;)
				{
					Point right = {-direction.y,direction.x};
					if(!map[right.y + position.y][right.x + position.x])
					{
						direction = right;
						break;
					}
					if(!map[-right.y + position.y][-right.x + position.x])
					{
						direction.x = -right.x;
						direction.y = -right.y;
						break;
					}
					position.x -=direction.x;
					position.y -=direction.y;
					move--;
					direction = *(move-1);
				}
	
			}
		}
		position.x += direction.x;
		position.y += direction.y;
		*move = direction;
		move++;
	}
	move--;
	map[position.x][position.y] = 2;
	for(;move>moves;move--)
	{
		position.x-=move->x;
		position.y-=move->y;
		map[position.y][position.x] = 2;
	}


	char pieces[3] = " #*";
	for(int i =0;i<length;i++)
	{
		for(int j =0;j<width;j++)
			printf("%c",pieces[map[i][j]]);
		puts("");
	}

	return 0;
}
