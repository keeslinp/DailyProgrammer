#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream in("credit.in");
	ofstream cout("credit.out");
	string buff("");
	getline(in,buff);
	int count;
	stringstream(buff) >> count;
	for(int a = 0; a < count; a++)
	{
		cout << "Case #" << a+1 << ": ";
		getline(in,buff);
		int credit;
		stringstream(buff) >> credit;
		getline(in,buff);
		int itemc;
		stringstream(buff) >> itemc;
		vector<int> items(itemc);
		getline(in,buff);
		string::iterator it = buff.begin();
		for(int j = 0;j<itemc;j++)
		{
			string b = "";
			while(*it != ' ')
			{
				b += *it;
				it++;
			}
			it++;
			stringstream(b) >> items[j];
			b= "";
		}
		int j = 0;
		int i = 0;
		bool flag = false;
		for(j=0;j < itemc && !flag;j++)
			for(i=j+1;i<itemc;i++)
			{
				if(items[j] + items[i] == credit)
				{
					flag = true;
					break;
				}
			}
		cout << j << " "  << i + 1 << endl;
	}

	return 0;
}
