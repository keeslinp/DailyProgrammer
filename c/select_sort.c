#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* nums, int len)
{
	int min = 0;
	for(int i = 0;i<len;i++)
		min = (nums[min]<nums[i]?min:i);
	int buff = nums[0];
	nums[0] = nums[min];
	nums[min] = buff;
	if(len>1)sort(nums+1,len-1);
}

int main(int argc, char* argv[])
{
	int ary[argc-1];
	for(int i = 1;i<argc;i++)
		ary[i-1] = atoi(argv[i]);
	sort(ary,sizeof(ary)/sizeof(int));
	for(int* i = ary;i <ary + sizeof(ary)/sizeof(int);i++)
		printf("%d\n",*i);
	return 0;
}
