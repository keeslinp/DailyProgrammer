#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

string brackets_start("({[");
string brackets_end(")}]");
ofstream out ("log");
string parse(string input)
{
	out << input << endl;
	string::iterator c = input.begin();
	out << *c << endl;
	int open = find(brackets_start.begin(),brackets_start.end(),*c) - brackets_start.begin();
	out << open << endl;
	c++;
	string interior("");
	string part("");
	while(c < input.end())
	{
		out << *c << endl;
		if(any_of(brackets_start.begin(),brackets_start.end(),[=](char i){return i ==*c;}))
		{
			string buff("");
			while((find(brackets_end.begin(),brackets_end.end(),*c) - brackets_end.begin())!=open)
			{
				out << find(brackets_end.begin(),brackets_end.end(),*c) - brackets_end.begin() << "=" << open<< endl;
				out << *c << endl;
				buff+=*c;
				c++;
			}
			//buff += *c;
//			buff.erase(buff.size()-1);
			interior = parse(buff);
		}else{
			//if(!any_of(brackets_end.begin(),brackets_end.end(),[=](char i){return i==*c;}))part += *c;
			part += *c;
			c++;
		}
	}
	cout << part << endl;
	//if(interior[0] ==' ')interior.erase(0,1);
	return interior + part;// + (part.back()==' '? "" :" ");
}
int main()
{
	string input;
	ifstream in("brackets.in");
	
	getline(in,input);
	cout << parse(input) << endl;


	return 0;
}
