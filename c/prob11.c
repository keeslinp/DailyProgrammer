#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f = fopen("prob11.in","r");
	int grid[20][20];
	char str[3];
	for(int y = 0;y<20;y++)
	{
		for(int x = 0;x<20;x++)
		{
			fscanf(f,"%s",str);
			grid[y][x] = atoi(str);
		}
	}
	int max = 0;
	for(int y = 0;y<20;y++)
	{
		for(int x = 0;x<20;x++)
		{
			int buff;
			if(y<17)buff = grid[y][x]*grid[y+1][x]*grid[y+2][x]*grid[y+3][x];
			max = (max>buff?max:buff);
			if(y<17 && x<17)buff = grid[y][x]*grid[y+1][x+1]*grid[y+2][x+2]*grid[y+3][x+3];
			max = (max>buff?max:buff);
			if(x<17)buff = grid[y][x]*grid[y][x+1]*grid[y][x+2]*grid[y][x+3];
			
			max = (max>buff?max:buff);
			if(y<17 && x > 2)buff = grid[y][x]*grid[y+1][x-1]*grid[y+2][x-2]*grid[y+3][x-3];
 			max = (max>buff?max:buff);
					}
	}
	printf("%d\n",max);
	return 0;
}
