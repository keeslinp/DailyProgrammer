#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

bool is_penta(int n)
{
    double a = (1+sqrt(n * 24 + 1))/6;
    return ((int)a == a);
}

int penta(int n)
{
    return (n*(3*n-1)/2);
}

int main()
{
    int min = INT_MAX;
   for(int i = 1;i<10000;i++)
   {
       for(int j = i+1;j<10000;j++)
        {
            int pi = penta(i);
            int pj = penta(j);
            if(is_penta(pj-pi)&&is_penta(pj+pi))
            {
                min = (min<pj-pi?min:pj-pi);
            }
        }
   }
   printf("%d\n",min);
   return 0;
}
