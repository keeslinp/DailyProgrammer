#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int nums[], int size)
{
	if(size<=1)return;
	int compare = nums[0];
	int less[size];
	int* l = less;
	int more[size];
	int* m = more;
	for(int i =1; i < size;i++)
	{
		if(nums[i] < compare)
		{
			*l = nums[i];
			l++;
		}else{
			*m = nums[i];
			m++;
		}
	}
	sort(less, l-less);
	sort(more, m-more);
	memcpy(nums, less, (l-less) * sizeof(int));
	nums[l-less] = compare;
	memcpy(nums+ (l-less) +1, more, (m-more) * sizeof(int));
}

int main(int argc, char* argv[])
{
	int ary[argc-1];
	for(int i =0; i < argc-1;i++)
		ary[i] = atoi(argv[i+1]);
	
	sort(ary,sizeof(ary)/sizeof(int));

	for(int i = 0;i < sizeof(ary)/sizeof(int);i++)
		printf("%d\n",ary[i]);

	return 0;
}
