#include <stdio.h>

int main()
{
	int answer =0;
	for(int a = 1;a<1000;a++)
	{
		for(int b = a;b<1000;b++)
		{
			int c = 1000-a-b;
			if(a*a+b*b==c*c)
			{
				answer = a*b*c;
				a = 1000;
				b = 1000;
			}
		}
	}
	printf("%d\n",answer);
}
