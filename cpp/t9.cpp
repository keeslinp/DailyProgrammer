#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<char,int> letters;
    letters['a'] = 2;letters['b'] = 22;letters['c'] = 222;letters['d'] = 3;letters['e'] = 33;letters['f'] = 333;letters['g'] = 4;letters['h'] = 44;letters['i'] = 444;letters['j'] = 5;letters['k'] = 55;letters['l'] = 555;letters['m'] = 6;letters['n'] = 66;letters['o'] = 666;letters['p'] = 7;letters['q'] = 77;letters['r'] = 777;letters['s'] = 7777;letters['t'] = 8;letters['u'] = 88;letters['v'] = 888;letters['w'] = 9;letters['x'] = 99;letters['y'] = 999;letters['z'] = 9999;letters[' '] = 0;
    ifstream in("t9.in");
    ofstream cout("t9.out");
    string buff;
    getline(in,buff);
    int count;
    stringstream(buff) >> count;
    for(int i=0; i < count; i++)
    {
        cout << "Case #" << i+1 << ": ";
        string b;
        getline(in,b);
        for(string::iterator it = b.begin(); it < b.end(); it++)
        {
            if(letters[*(it-1)]%10 == letters[*it]%10)cout << " ";
            cout << letters[*it];
        }
        cout << endl;
    }
    return 0;
}
