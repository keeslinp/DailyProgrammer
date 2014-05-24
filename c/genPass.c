#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contains(int pass[7], int num)
{
	for(int i= 0;i < 7;i++)
		if(num==pass[i])return 0;
	return 1;
}

int main()
{
	srand(time(NULL));
	int pass[7] = {rand()%9 + 1};
	for(int* digit = pass; digit < pass+7;digit++)
	{
		int allowed[7]={0};
		int* a = allowed;
		for(int i =0 ; i < 9;i++)
		{
			if(!contains(pass, i))continue;
			if(*(digit-1)+1!=i)*(a++)=i;
		}
		*digit = allowed[rand()%(a-allowed)];
	}
	for(int i = 0; i < 7;i++)
		printf("%i",pass[i]);
	puts("");

	return 0;
}
