#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int num,den;
	stringstream(argv[1]) >> num;
	stringstream(argv[2]) >> den;
	cout << round(fma(num,pow(den,log10(0.1)), 0)) << endl;
	return 0;
}
