#include <stdio.h>
#include <stdbool.h>

bool contains(int a, int b)
{
	while(a >0)
	{
		if(a%10 ==b)return true;
		a/=10;
	}
	return false;
}
bool is_unique(int n)
{
	int buff = n;
	while(buff >0)
	{
		if(contains(buff/10,buff%10))return false;
		buff /=10;
	}
	return true;
}

bool is_torn(int n)
{
	if(!is_unique(n))return false;
	int sum = n%100 + n/100;
	return (sum*sum == n);
}

int main()
{
	for(int i =1023;i < 9876;i++)
	{
		if(is_torn(i))printf("%d\n",i);
	}

	return 0;
}
