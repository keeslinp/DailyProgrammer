#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream in ("names.txt");
	vector<string> names;
	string buff;
	while(getline(in,buff,','))
	{
		names.push_back(buff.substr(1,buff.size()-2));
	}
	for(int i = 0;i < names.size();i++)
	{
		int j = i;
		while(j>0 && names[j].compare(names[j-1])<0)
		{
			string buff = names[j];
			names[j] = names[j-1];
			names[j-1] = buff;
			j--;
		}
	}
	int score = 0;
	for(int i =0;i<names.size();i++)
	{
		for(string::iterator it = names[i].begin();it<names[i].end();it++)
		{
			score += (*it-64)*(i+1);
		}
	}
	cout << score << endl;
	return 0;
}
