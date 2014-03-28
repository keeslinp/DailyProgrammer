#include <stdio.h>

int main()
{
	int num = 1;
	int last = 1;
	int sum = 0;
	while(num <= 4000000)
	{
		if(num%2==0)sum += num;
		num += last;
		last = num - last;
	}

	printf("%d\n",sum);
}
