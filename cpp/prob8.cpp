#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	string nums("");
	ifstream in("prob8.in");
	string buff("");
	while(getline(in,buff))nums += buff;
	int max;
	for(string::iterator it = nums.begin();it<nums.end();it++)
	{
		int buff = 1;
		for(string::iterator i = it; i < it+5 && i < nums.end(); i++)
		{
			buff*= *i - 48;
		}
		if(buff > max) max = buff;
	}
	cout << max << endl;

	return 0;
}
