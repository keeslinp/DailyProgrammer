#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char *argv[])
{
	char *code = new char[strlen(argv[1])];
	for(int i = 0; i< strlen(argv[1]);i++)code[i] = (char) ((argv[2][i%strlen(argv[2])] + argv[1][i]-'A'-'A')%26+'A');
	cout << code << endl;
}
