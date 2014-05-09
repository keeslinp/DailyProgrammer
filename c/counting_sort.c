#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void c_sort(int* nums, int size)
{
	int max = 0;
	for(int* n = nums; n < nums+size;n++)
	{
		max = max>*n?max:*n;
	}
	int count[max];
	memset(count, 0,(max+1)*sizeof(int));
	for(int n = 0;n < size;n++)
	{
		count[nums[n]]++;
	}
	int i= 0;
	for(int c = 0;c <= max;c++)
	{
		while(count[c] >0)
		{
			nums[i] =c;
			i++;
			count[c]--;

		}
	}
}

int main(int argc, char* argv[])
{
	int nums[argc-1];
	for(int i = 0 ; i < argc-1;i++)
	{
		nums[i] = atoi(argv[i+1]);
	}
	c_sort(nums,sizeof(nums)/sizeof(int));
	for(int i = 0; i < argc-1;i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");

	return 0;
}
