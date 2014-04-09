#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int* ary, int size)
{
	int buff[size];
	int* b = buff;
	for(int* i = ary+size-1;i>=ary;i--)
	{
		*b = *i;
		b++;
	}
	memcpy(ary,buff,size*sizeof(int));
}

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*) b);
}

void psort(int* nums, int size)
{
	qsort(nums,size,sizeof(int),compare);
	int d = (size%2==0?0:1);
	int first[size/2+d];
	int second[size/2];
	for(int i = 0;i <size;i++)
	{
		first[i/2] = nums[i];
		i++;
		if(i>=size)break;
		second[i/2] = nums[i];
	}
	memcpy(nums,first,sizeof(first));
	reverse(second,sizeof(second)/sizeof(int));
	memcpy(nums+sizeof(first)/sizeof(int),second,sizeof(second));
}
int main(int argc, char* argv[])
{
	int count = 1;
	for(char* c = argv[1];c<argv[1]+strlen(argv[1]);c++)
	{
		if(*c==',') count++;
	}
	int ary[count];
	int* p = ary;
	int buff = 0;
	for(char* c = argv[1];c<argv[1]+strlen(argv[1]);c++)
	{
		if(*c >=48 && *c<=57)
		{
			buff = buff * 10 + (*c-48);
		}else if(*c ==',')
		{
			*p = buff;
			p++;
			buff = 0;
		}
	}
	*p = buff;
	psort(ary,sizeof(ary)/sizeof(int));
	char out[10*sizeof(ary)/sizeof(int)];
	sprintf(out,"[");
	for(int* i = ary; i < ary + sizeof(ary)/sizeof(int);i++)
	{
		char buff[11];
		sprintf(buff,"%d,",*i);
		strncat(out,buff,10);
	}
	int len = strlen(out);
	out[len-1] = ']';
	printf("%s\n",out);
	return 0;
}
