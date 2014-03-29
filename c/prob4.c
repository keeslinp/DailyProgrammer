#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int reverse(int i)
{
	int response = 0;
	while(i > 0)
	{
		response = response * 10 + i%10;
		i/=10;
	}
	return response;
}

bool isPalindrome(int n)
{
	return n == reverse(n);
}

int main()
{
	int max = 0;
	for(int i = 0; i < 999;i++)
	{
		for(int j = i;j<999;j++)
		{
			if(isPalindrome(i*j))max = (max>i*j?max:i*j);
		}
	}
	printf("%d\n",max);

	return 0;
}
