#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("conway.in","r");
	int x;
	int y;
	int n;
	fscanf(fp,"%i",&n);
	fscanf(fp,"%i",&x);
	fscanf(fp,"%i",&y);
	int map[y][x+1];
	for(int row =0;row<y;row++)
	{
		char buff [x+1];
		fgets(buff, x+2,fp);
		for(char* c =buff;c<buff+x;c++)
		{
			map[row][c-buff] = (*c=='#');
		}
	}

	int next[y][x+1];
	for(int i =0;i<n;i++)
	{
		for(int row =0;row < y;row++)
		{
			for(int col=0;col<x;col++)
			{
				int neighbors = map[row][col]*-1;
				for(int dr=(row==0?0:-1);dr<=(row==y?0:1);dr++)
					for(int dc=(col==0?0:-1);dc<=(col==x?0:1);dc++)
						neighbors+=map[row+dr][col+dc];
				next[row][col] = ((map[row][col]==1&&neighbors==2)||neighbors==3);
			}
		}
		for(int j = 0; j<10; j++)
		{
			    memcpy(&map[j], &next[j], sizeof(next[0]));
		}

	}

	for(int row = 0;row<y;row++)
	{
		for(int col=0;col<x;col++)
			printf("%c",map[row][col]?'#':'.');
		puts("");
	}

	return 0;
}

