#include <iostream>
#include <sstream>

using namespace std;

void qsort(int size, int *ary)
{
	if(size<=1)return;
	int less[size];
	int *l = less;
	int more[size];
	int *m = more;

	for(int i = 1; i< size;i++)
	{
		if(ary[i]<ary[0])
		{
			*l = ary[i];
			l++;
		}else{
			*m = ary[i];
			m++;
		}
	}
	ary[l-less] = ary[0];
	copy(less,less+(l-less),ary);
	copy(more,more+(m-more),ary+(l-less)+1);
	
	qsort(l-less,ary);
	qsort(m-more,ary+(l-less+1));
}

int main (int argc, char *argv[])
{
	int ary[argc-1];
	for(int i=1;i<argc;i++)
	{
		stringstream(argv[i]) >> ary[i-1];
	}
	qsort(argc-1, ary);
	for(int *counter = ary;counter < ary+argc-1;counter++)
	{
		cout << *counter << endl;
	}
	return 0;
}
