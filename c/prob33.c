#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool contains(int* start, int* end, int value)
{
    for(int* i = start;i<end;i++)
    {
        if(*i==value)return true;
    }
    return false;
}

bool test(int a, int b)
{
    int aa[2];
    int* pa = aa;
    int ab[2];
    int* pb = ab;
    int temp = a;
    while(temp>0)
    {
        *pa = temp%10;
        pa++;
        temp/=10;
    }
    temp = b;
    while(temp>0)
    {
        *pb = temp%10;
        pb++;
        temp/=10;
    }
    if(ab[0]==0 && aa[0] == 0)return false;
    bool flag = false;
    for(pa = aa;pa<aa+2;pa++)
    {
        //printf("%i",*pa);
        for(pb = ab;pb < ab+2;pb++)if(*pa == *pb)
        {
        	//printf("%f - %f",(float)*(pa + 2*(aa+1-pa) -1) / (float)*(pb + 2*(ab+1-pb)-1), (float)a/(float)b);
        	if((float)*(pa + 2*(aa+1-pa) -1) / (float)*(pb + 2*(ab+1-pb)-1) == (float)a/(float)b)
        	{
        		flag = true;
	        	break;
        	}
        }
    }
    return flag;
}
int main()
{
	int numerator =1;
	int denominator = 1;
   for(int i = 10; i < 99;i++)
   {
        for(int j = i+1;j< 99;j++)
        {
            if(test(i,j))
            {
            	numerator*=i;
            	denominator*=j;
            }
        }
   }
   for(int n = 2; n <= numerator;n++)
   {
   		while(numerator%n== 0 && denominator%n==0)
   		{
   			numerator/=n;
   			denominator/=n;
   		}
   }
   printf("%d/%d\n",numerator,denominator);
}
