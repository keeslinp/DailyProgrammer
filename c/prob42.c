#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool is_tri(int n)
{
	n = n * 8 +1;
	int temp = sqrt(n);
	return (temp*temp == n);
}

int main()
{
	FILE* f = fopen("prob42.in","r");
	char c;
	int count = 0;
	char buff[20];
	buff[0] = '\0';
	while((c=getc(f))!=EOF)
	{
		
		if(c!='\"' && c!=',')
		{
			int len = strlen(buff);
			buff[len] = c;
			buff[len+1] = '\0';
		}else if(strlen(buff)>0)
		{
			int sum =0;
			for(char* p = buff;p<buff + strlen(buff);p++)
			{
				sum += *p-64;
			}
			if(is_tri(sum))count++;
			buff[0] = '\0';
		}
	}
	printf("%d\n",count);

	return 0;
}	
