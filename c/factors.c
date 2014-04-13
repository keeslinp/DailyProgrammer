#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int dtob(int i)
{
	int num =1 ;
	int buff = i;
	while(buff>0)
	{
		num = num*10 + buff%2;
		buff /=2;
	}
	int resp =1;
	while(num>1)
	{
		resp = resp * 10 + num%10;
		num/=10;
	}
	resp -= pow(10,floor(log10(resp)));
	return resp;
}

bool contains(int* start, int* end, int value)
{
	for(int* i = start;i <end;i++)
		if(*i==value)return true;
	return false;
}

void factors(int VALUE)
{
//generate primes
	int num = VALUE;
	int lim = num/2+1;
	bool prime[lim];
	int primes[lim/2];
	int* p = primes;
	for(bool* b = prime;b<prime+lim; b++)
		*b = true;
	for(int i = 2; i < lim;i++)
	{
		if(prime[i])
		{
			*p = i;
			p++;
			*p = 0;
			int j =1;
			while(i*j<lim)
			{
				prime[i*j] = false;
				j++;
			}
		}
	}
//prime factors
	int buff = num;
	int prime_factors[num];
	int curr_prime = 0;
	int count =0;
	while(buff>1)
	{
		if(primes[curr_prime]==0){printf("%d\n",VALUE);return;}
		if(buff%primes[curr_prime]==0)
		{
			prime_factors[count] = 0;
			while(primes[curr_prime]!=0&&buff % primes[curr_prime]==0)
			{
				buff/=primes[curr_prime];
				prime_factors[count] = primes[curr_prime];
				count++;
			}
		}
		curr_prime++;
	}

//All proper divisors
	int divisors[num];
	memset(divisors,0,num*sizeof(int));
	int* d = divisors;
	for(int i = 1;i <= pow(2,count)-2;i++)
	{
		int parts = dtob(i);
		int product = 1;
		int count = 0;
		while(parts > 0)
		{
			if(parts%10)product*=prime_factors[count];
			parts/=10;
			count++;
		}
		if(!contains(divisors,divisors+num,product))
		{
			*d = product;
			d++;
		}
	}
	d--;
	while(d >= divisors)
	{
		printf("%d\n",*d);
		d--;
	}
}

int main(int argc,char* argv[])
{
	clock_t begin, end;
	double time_spent;
	
	begin= clock();

	factors(atoi(argv[1]));

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken: %f\n",time_spent);
				
	return 0;
}
