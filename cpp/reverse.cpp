#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string buff;
	ifstream in("reverse.in");
	getline(in,buff);
	ofstream cout("reverse.out");
	
	int count;
	stringstream(buff) >> count;
	for(int i = 0; i < count; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		string line;
		getline(in,line);
		vector<string> words(50);
		int j = 0;
		for(string::iterator i = line.begin();i<line.end();i++)
		{
			words[j] += *i;
			if(*i == ' ')
			{
				j++;
				if(j>= words.size())words.resize(words.size() + 100);
			}
		}
		words[j] += " ";
		for(vector<string>::reverse_iterator it = words.rbegin();it<words.rend();it++)cout << *it;
		cout << endl;
	}
	return 0;
}
