#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f = fopen("prob18.in","r");
	int nums[5050];
	char str[3];
	int* num = nums;
	while(fscanf(f,"%s",str)!=EOF)
	{
		*num = atoi(str);
		num++;
	}
	int row = 100;
	int i = 5049;
	while(i>0)
	{
		for(int r = row;r>1;r--)
		{
			nums[i-row] += (nums[i]>nums[i-1]?nums[i]:nums[i-1]);
			i--;
		}
		row--;
		i--;
	}
	printf("%d\n",nums[0]);

	return 0;
}
