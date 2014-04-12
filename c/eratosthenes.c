#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int num = atoi(argv[1]);
	bool prime[num];
	for(bool* b = prime;b<prime+num;b++)
	{
		*b = true;
	}
	char out[num+5];
	out[0] = '\0';
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
			char buff[(int)floor(log10(i)+1)];
			sprintf(buff,"%d,",i);
			strcat(out,buff);
		}
	}
	out[strlen(out)-1] = '\0';
	printf("%s\n",out);
	return 0;
}
