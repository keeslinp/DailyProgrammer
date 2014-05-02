#include <iostream>

using namespace std;
int main()
{
	int birth;
	cout << "Year of birth: ";
	cin >> birth;
	int curr;
	cout << "Current Year: ";
	cin >> curr;
	int res = curr - birth;
	cout << "Your age: " << res+(res < 0?100:0)<<endl;
	return 0;
}
