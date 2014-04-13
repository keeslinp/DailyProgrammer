#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



bool is_abundant(int VALUE)
{
	int lim = VALUE/2+1;
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
				prime[i*(j++ - 1)] = false;
		}
	}
	int buff = VALUE;
	int prime_factors[VALUE];
	int multiplicity[VALUE];
	int curr_prime = 0;
	int count =0;
	while(buff>1)
	{
		if(primes[curr_prime]==0)return false;
		if(buff%primes[curr_prime]==0)
		{
			prime_factors[count] = 0;
			multiplicity[count] = 0;
			while(primes[curr_prime]!=0&&buff % primes[curr_prime]==0)
			{
				buff/=primes[curr_prime];
				prime_factors[count] = primes[curr_prime];
				multiplicity[count]++;
			}
			count++;
		}
		curr_prime++;
	}
	int product = 1;
	while(count-->0)
		product *= (pow(prime_factors[count],multiplicity[count]+1)-1)/(prime_factors[count]-1);
	return (product-VALUE > VALUE);
}

int main(int argc,char* argv[])
{
	clock_t begin, end;
	double time_spent;
	
	begin= clock();
	
	int abundants[10000] = {0};
	int* a = abundants-1;
	bool summable[28123]= {false};

	for(int i =0; i < 28123;i++)
		if(is_abundant(i)){*(a++)=i;}
	for(int i = 0; i <= a-abundants;i++)
	{
		for(int j = i; j<= a-abundants;j++)
		{
			if(abundants[i]+abundants[j] > 28123)break;
			summable[abundants[i]+abundants[j]]=true;
		}
	}
	int sum = 0;
	for(int i =0;i < 28123;i++)
		if(!summable[i])
			sum+=i;
	printf("%d\n",sum);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken: %f\n",time_spent);		
	return 0;
}
