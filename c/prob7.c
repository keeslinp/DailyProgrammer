#include <stdio.h>
#include <stdbool.h>

int main()
{
	int primes[10001] = {2};
	int count = 1;
	int i = 3;
	while(count<10001)
	{
		int* p = primes;
		bool flag = true;
		while(*p != 0)
		{
			if(i%*p==0)flag = false;
			p++;
		}
		if(flag)
		{
			*p = i;
			count ++;
		}
		i+=2;
	}
	printf("%d\n",primes[10000]);
	return 0;
}
