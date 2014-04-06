#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define size 10000

int primes[size]= {2};

bool is_square(int n)
{
	int a = sqrt(n);
	return (a*a==n);
}

bool test(int n)
{
	for(int* p = primes;p< primes + size;p++)
	{
		int a = n-*p;
		if(is_square(a/2))return true;
		if(*p > n)return false;
	}
	return false;
}

void generate_primes()
{
	for(int i =2; i < size;i++)
	{
		int x =0;
		bool flag = true;
		while(primes[x]!=0)
		{
			if(i%primes[x]==0){flag =false;break;}
			x++;
		}
		if(flag)primes[x] = i;
	}
}

int main()
{
	generate_primes();
	int i =0 ;
	for(i = 1; i < size;i+=2)
	{
		if(!test(i))break;
	}
	printf("%d\n",i);
	return 0;
}
