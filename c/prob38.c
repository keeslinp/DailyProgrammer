#include <stdio.h>
#include <math.h>
#include <stdbool.h>

unsigned long long combine(unsigned long long a, unsigned long long b)
{
	return (a*pow(10,floor(log10(b)+1)) + b);
}

bool is_pandigital(unsigned long long n)
{
	if(floor(log10(n)+1) > 9)return false;
	if(n%9 !=0)return false;
	int buff = 0;
	while(n>0)
	{
		buff |= 1<< n%10;
		n/=10;
	}
	return (buff==1022);
}

unsigned long long test(unsigned long long n)
{
	unsigned long long sum = n;
	for(int i = 2;i<=floor(log10(n)+1);i++)
	{
		sum = combine(sum,i*n);
		if(is_pandigital(sum))return sum;
	}
	return 0;
}

int main(void) {
	int max = 0;
	for(int i = 0; i < 10000;i++)
	{
		int buff;
		if((buff = test(i)))max = (max>buff?max:buff);
	}
	printf("%d\n",max);
	return 0;
}
