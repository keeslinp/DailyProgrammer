#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string a, string b, string alphabet)
{
	string::iterator ait = a.begin();
	string::iterator bit = b.begin();
	while(bit < b.end() || ait < a.end())
	{
		if(bit < b.end())
		{
			if(*bit >=97)*bit -= 32;
			bit++;
		}
		if(ait < a.end())
		{
			if(*ait >=97)*ait -= 32;
			ait++;
		}
	}
	if(a.find(b)!=string::npos)return 1;
	if(b.find(a)!=string::npos)return 0;
	string::iterator c1 = a.begin();
	string::iterator c2 = b.begin();
	while(c1==c2)
	{
	
		c1++;
		c2++;

	}
	for(int i = 0;i<26; i++)
	{
		if(alphabet[i] == *c1)return 0;
		if(alphabet[i] == *c2)return 1;
	}
	return -1;
}

bool check(string Gorellian)
{
	for(string::iterator c = Gorellian.begin();c < Gorellian.end();c++)
	{
		if(*c <=90) *c += 32;
	}
	string English("abcdefghijklmnopqrstuvwxyz");
	vector<char> repeats;
	vector<char> missing;
	for(string::iterator c = English.begin();c < English.end();c++)
	{
		int val = count(Gorellian.begin(),Gorellian.end(),*c);
		if(val >1)repeats.push_back(*c);
		if(val <1)missing.push_back(*c);
	}
	string out;
	bool flag = false;
	if(missing.size() > 0)
	{
		out += "Error! Missing letters: ";
		for(vector<char>::iterator it = missing.begin(); it < missing.end();it++)
		{
			out += *it;
			out += " ";
		}
		out += '\n';
		flag = true;
	}
	if(repeats.size() > 0)
	{
		out += "Error! Duplicate letters found in alphabet: ";
		for(vector<char>::iterator it = repeats.begin(); it < repeats.end();it++)
		{
			out += *it;
			out += " ";
		}
		out += '\n';
		flag = true;
	}
	cout << out;
	return flag;
}

int main(int argc, char* argv[])
{
	int count;
	ifstream in("Gorellian.in");
	in >> count;
	vector<string> words(count);
	string alphabet("");
	in >> alphabet;
	if(check(alphabet))return -1;
	string dump;
	getline(in,dump);


	for(int i =0; i < count;i++)
	{
		getline(in,words[i]);
	}
	
	for(int i = 0; i < count; i++)
	{
		int j = i;
		while(j>0 && compare(words[j],words[j-1],alphabet)==0)
		{
			string buff = words[j];
			words[j] = words[j-1];
			words[j-1] = buff;
			j--;
		}
	}
	
	for(vector<string>::iterator it = words.begin();it<words.end();it++)
	{
		cout << *it<< endl;
	}

	return 0;
}
