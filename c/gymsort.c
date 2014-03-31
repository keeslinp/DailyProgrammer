#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a-*(int*)b);
}

int main(int argc,char* argv[])
{
	int times[argc-1];
	for(int i =1;i <argc;i++)
	{
		times[i-1] = atoi(argv[i]);
		if(times[i-1] < 12)times[i-1] += 24;
	}
	qsort(times,argc-1,sizeof(int),compare);
	for(int* i = times;i<times+sizeof(times)/sizeof(int);i++)
	{
		if(*i>24)*i-=24;
		printf("%d ",*i);
	}
	printf("\n");
	
	return 0;
}
