#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
   int num,rev, buff;
   stringstream(argv[1]) >> num;
   buff = num;
   for(int i= 0; i < ceil(log10(num));i++)
    {
        rev = rev * 10 + (buff % 10);
        buff /=10;
    }
    cout << ((rev == num) ? "" : "Not a") << "Palindrome" << endl;
   return 0;
}
