#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ary[argc-1];
	for(int i =0;i < argc-1;i++)
		ary[i] = atoi(argv[i+1]);

	for(int* tail = ary;tail < ary + sizeof(ary)/sizeof(int);tail++)
	{
		for(int i =0;i < sizeof(ary)/sizeof(int) - (tail - ary);i++)
		{
			int item = tail[i];
			int index = i;
			int parent = (i-1)/2;
			while(i>0 && tail[parent] < item)
			{
				tail[i] = tail[parent];
				i = parent;
				parent = (i-1)/2;
			}
			tail[i] = item;
		}
	}

	for(int i = 0;i < sizeof(ary)/sizeof(int);i++)
		printf("%d\n",ary[i]);

	return 0;
}
