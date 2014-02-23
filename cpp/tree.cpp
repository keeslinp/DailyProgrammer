#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int rows;
	stringstream(argv[1]) >> rows;
	char base = argv[2][0];
	char leaf = argv[3][0];
	for(int i = 0;i < (rows+1)/2;i++)
	{
		cout << setw(i+rows/2+1) << string(i*2+1, leaf)<<endl;
	}
	cout << setw(rows/2+2) << string(3,base) << endl;
	return 0;
}
