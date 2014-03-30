#include <stdio.h>
#include <math.h>

int tri(int n)
{
	int sum =0;
	while(n>0)
	{
		sum += n;
		n--;
	}
	return sum;
}

int main()
{
	int divisors = 0;
	int n = 1;
	int num= 0;
	while(divisors <=500)
	{
		num = tri(n);
		divisors = 0;
		for(int i =1;i<sqrt(num);i++)
		{
			if(num%i==0)divisors+=2;
		}
		n++;
	}
	printf("%d\n",num);

	return 0;
}
