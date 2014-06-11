#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	

	int list[] = {0,0,32,98,111,116,116,108,101,115,32,111,102,32,98,101,101,114,32,111,110,32,116,104,101,32,119,97,108,108};
	char random_message[28]="";
	for(int i = 3*3;i>=3*0;i--)
	{
		for(int j = 3*3;j>=3*0;j--)
		{
			list[0] = (i==0?-1:i+48);
			list[1] = j+48;

			for(int i =0;i<sizeof(list)/sizeof(int);i++)
			{
				if(list[i]==-1)continue;
				char new;
				while((new=rand()%123)!=list[i]);
				int len = strlen(random_message);
				random_message[len] = new;
				random_message[len+1] = '\0';
			}
			printf("%s\n",random_message);
			random_message[0] = '\0';
		}
	}
	
	return 0;
}
