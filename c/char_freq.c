#include <stdio.h>
#include <string.h>

int compare (const void * a, const void * b)
{
	return(*(int*)a - *(int*)b);
}

int main(int argc, char* argv[])
{
	int frequency[256] = {0};
	for(int i = 0; i < strlen(argv[1]);i++)
	{
		frequency[argv[1][i]] ++;
	}
	int max_i = 0;
	int max = 0;
	do
	{
		max =0;
		for(int i = 0; i < 256;i++)
		{
			if(frequency[i]>max)
			{
				max = frequency[i];
				max_i = i;
			}
		}
		if(frequency[max_i]==0)continue;
		printf("%c ",max_i);
		while(frequency[max_i]>0)
		{
			printf(".");
			frequency[max_i]--;
		}
		printf("\n");
	}while(max>0);
	
	return 0;
}
