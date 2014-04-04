#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool is_pandigital(unsigned long long n)
{
    if(floor(log10(n))+1 !=9)return false;
    int count[10] = {0};
    while(n >0)
    {
        count[n%10]++;
        n/=10;
    }
    if(count[0]!=0)return false;
    for(int* i = count+1;i < count + sizeof(count)/sizeof(int);i++)
    {
        if(*i !=1)return false;
    }
    return true;
}

unsigned long long combine(unsigned long long a,unsigned long long b)
{
    return a*pow(10,floor(log10(b)+1))+b;
}

bool contains(int* ary,int length, int n)
{
    for(int* i = ary;i<ary+length;i++)
    {
        if(n==*i) return true;
    }
    return false;
}

int main()
{
    int sums[50] = {0};
    int* s = sums;
    int sum =0;
    unsigned long long i;
    for(i = 1; i<10000;i++)
    {
        for(unsigned long long j = i;j<10000/i;j++)
        {
            if(is_pandigital(combine(combine(i,j),i*j)))
            {
                if(!contains(sums,50,i*j))
                {
                    sum+=i*j;
                    *s = i*j;
                    s++;
                }
            }
        }
    }
    printf("%d\n",sum);
   return 0;
}
