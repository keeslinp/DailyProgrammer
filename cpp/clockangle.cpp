#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;


int main(int argc, char *argv[])
{
    string buff(argv[1]);
    string hour("");
    string min("");
    string *target = &hour;
    for(string::iterator it = buff.begin();it<buff.end();it++)
    {
        if(*it==':' || *it=='h')
        {
            it++;
            target = &min;
        }
        *target += *it;
    }
     
    float h,m;
    stringstream(hour) >> h;
    stringstream(min) >> m;
     
    int answer = fabs((h/24 - m/60) * 360);
    //if(answer > 180) answer-=180;
    cout << answer;
    return 0;
}
