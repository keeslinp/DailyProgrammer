#include <stdio.h>
#include <string.h>

char* line = "...***--++";

int main()
{
	FILE* fp = fopen("architect.in","r");
	char c;
	char map[230][10];
	int col =0 ;
	while((c=fgetc(fp)) != '\n')
	{
		char output[10] = "";
		char tail[10] = "";
		char head[10] = "";
		if(c < 96)
		{
			while(strlen(tail)<c-48)
			{
				strcat(tail," ");
			}
			c= fgetc(fp);
		}
		strcat(output,line+9-(int)(c-97));
		while(strlen(head) + strlen(output) + strlen(tail)<10)
			strcat(head," ");
		sprintf(map[col],"%s%s%s",head, output,tail);
		col++;
	}
	for(int i = 0; i < 10;i++)
	{
		int buff = -1;
		while(buff++ < col)
			printf("%c",map[buff][i]);
		printf("\n");
	}
	return 0;
}
