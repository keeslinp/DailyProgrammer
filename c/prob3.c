#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	const unsigned long long NUMBER = 600851475143;
	int num = sqrt(NUMBER);
	bool prime[num];
	int max = 0;
	for(bool* b = prime;b<prime+num;b++)
	{
		*b = true;
	}
	for(int i = 2; i< num;i++)
	{
		if(prime[i])
		{
			int j = 2;
			while(j*i <= num)
			{
				prime[j*i] = false;
				j++;
			}
			if(NUMBER%i==0)max = i;
		}
	}
	printf("%d\n",max);
	return 0;
}
