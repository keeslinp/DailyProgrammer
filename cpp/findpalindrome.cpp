#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
	string::iterator fwd = str.begin();
	for(string::reverse_iterator bkwd = str.rbegin();bkwd < str.rend();bkwd++)
	{
		if(*fwd != *bkwd)return false;
		fwd ++;
	}
	return true;
}

int main(int argc, char* argv[])
{
	string max("");
	for(char* c = argv[1]; c < argv[1] + strlen(argv[1]);c++)
	{
		string buff("");
		for(char* d = c; d < argv[1] + strlen(argv[1]);d++)
		{
			buff += *d;
			if(isPalindrome(buff) && buff.size() > max.size()) max = buff;
			
		}
		buff.clear();
	}
	cout << max << endl;
	return 0;
}
