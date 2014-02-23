#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

int* sort(int count, int *ary)
{
	int *buff = new int[count];
	copy(ary, ary+count, buff);
	for(int i = 1; i < count;i++)
	{
		int delta = 0;
		while(buff[i-1-delta]>buff[i-delta]&&delta<i)
		{
			int b = buff[i-1-delta];
			buff[i-1-delta] = buff[i-delta];
			buff[i-delta] = b;
			delta++;
		}
	}
	return buff;
}

int main(int argc, char *argv[])
{
	int ary[argc-1];
	for(int i =1;i<argc;i++)
	{
		stringstream(argv[i]) >> ary[i-1];
	}
	int *sorted = sort(argc-1,ary);
	for(int i = 0;i<argc-1;i++)
	{
		cout << sorted[i] << endl;
	}
	delete[] sorted;
	return 0;
}	
