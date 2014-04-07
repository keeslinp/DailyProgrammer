#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int primes[] = {2,3,5,7,11,13,17};

int combine(int a, int b)
{
	return (a * pow(10,floor(log10(b)+1))+b);
}
bool test(unsigned long long n)
{
	int digits[10];
	for(int i = 9; i >=0;i--)
	{
		digits[i] = n%10;
		n/=10;
	}
	bool flag = true;
	for(int i =1;i <8;i++)
	{
		int buff = 0;
		for(int d = 0;d<3;d++)
		{
			buff = combine(buff,digits[i+d]);
		}
		if(buff%primes[i-1]!=0){flag = false;break;}
	}
	return flag;
}

bool is_pandigital(unsigned long long n)
{
	int buff = 1;
	while(n>0)
	{
		buff |= 1<<n%10;
		n/=10;
	}
	return (buff == 1023);
}
int main()
{
	int sum = 0;
	for(int i = 1023456789; i < 9876543220;i++)
	{
		if(!is_pandigital(i))continue;
		if(test(i))sum+=i;
	}
	printf("%d\n",sum);
	return 0;
}
