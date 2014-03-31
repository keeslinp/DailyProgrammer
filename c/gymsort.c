#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
	return (*(int*)a-*(int*)b);
}

int main(int argc,char* argv[])
{
	int times[15];
	char* token;
	char str[strlen(argv[1])+1];
	strcpy(str,argv[1]);
	char* p = str;
	p++;
	p[strlen(p)-1] = 0;
	token = strtok(p,",");
	int count =0;
	while(token!=NULL)
	{
		times[count] = atoi(token);
		if(times[count] < 12)times[count] += 24;
		count++;
		token= strtok(NULL,",");
	}
	qsort(times,count,sizeof(int),compare);
	char out[400];
	out[0] = '\0';
	for(int* i = times;i<times+ count;i++)
	{
		int delta = 0;
		if(*i>24)delta=24;
		char buff[7];
		sprintf(buff,"%d%s,",*i-delta,(delta!=0?"am":"pm"));
		strcat(out,buff);
	}
	out[strlen(out)-1]=0;
	printf("[%s]\n",out);
	
	return 0;
}
