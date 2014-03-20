#include <iostream>

using namespace std;

int fact(int i)
{
    if(i<=1)return 1;
    return i * fact(i-1);
}

int main()
{
    int total=0;
    for(int num = 3;num < 100000; num ++)
    {
        int buff = num;
        int sum=0;
        while(buff > 0)
        {
            sum += fact(buff % 10);
            buff /= 10;
        }
        if(sum == num)total += num;
    }
    cout << total << endl;
    return 0;
}
