#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isAbundant(int num)
{
	int sum;
	for(int i = 2;i<=sqrt(num);i++)
	{
		if(num%i==0)sum+=i + num/i;
	}
	return (num < sum);
}

bool contains(vector<int> &ary, int num)
{

	for(int i = 0; i < ary.size();i++)
	{
		if(ary[i] == num) return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	vector<int> abundants;
	vector<int> sums;

	for(int i = 12;i < 15000;i++)
	{
		if(isAbundant(i))abundants.push_back(i);
	}
	
	cout << abundants.size() << endl;

	for(vector<int>::iterator it = abundants.begin();it < abundants.end();it++)
	{
		for(vector<int>::iterator jt = it;*it + *jt < 28123 ;jt++)
		{
			sums.push_back(*it + *jt);
		}
	}

	int sum=0;
	for(int i =0;i < 28123;i++)
	{
		if(!contains(sums,i))sum+= i;
	}
	
	cout << sum << endl;	

	return 0;
}
