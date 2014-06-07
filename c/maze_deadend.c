#include <stdio.h>

int main()
{
	FILE* fp = fopen("maze_ai.in","r");
	int length;
	int width;
	fscanf(fp,"%i %i",&width,&length);
	char buff[length*width];
	fgets(buff,length*width,fp);

	int map[length][width];
	for(int row = 0;row<length;row++)	
	{
		fgets(buff, width+2, fp);
		for(int i = 0;i<width;i++)
			map[row][i] = buff[i];
	}

	int more = 1;
	while(more)
	{
		more = 0;
		for(int row = 0;row<length;row++)
		{
			for(int col=0;col<width;col++)
			{
				int directions = 0;
				for(int dx=-1;dx<=1;dx++)
				{
					for(int dy=-1;dy<=1;dy++)
					{
						if(dx==dy||dx*dy!=0)continue;
						if(map[row][col]==' '&&(map[row+dy][col+dx]!='X'&&map[row+dy][col+dx]!='#'))directions++;
					}
				}
				if(directions==1)
				{
					map[row][col] = 'X';
					more=1;
				}
			}
		}
	}

	for(int row=0;row<length;row++)
	{
		for(int col=0;col<width;col++)
		{
			if(map[row][col]==' ') map[row][col]='*';
			if(map[row][col]=='X') map[row][col]=' ';
		}
	}

	for(int row=0;row<length;row++)
	{
		for(int col=0;col<width;col++)
		{
			printf("%c",map[row][col]);
		}
		puts("");
	}

	return 0;
}
