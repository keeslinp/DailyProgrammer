#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
   string message = argv[1];
   char *vowels = new char[strlen(argv[1])];
   char *v = vowels;
   char *consonants = new char[strlen(argv[1])];
   char *co = consonants;
   for(string::iterator i = message.begin();i<message.end();i++)
   {
       if(*i==' ')continue;
       if(*i == 'a' || *i == 'e' || *i == 'i' || *i =='o' || *i =='u')
       {
           *v = *i;
           v++;
       }else
       {
           *co = *i;
           co++;
       }
   }
   cout << consonants << endl;
   cout << vowels << endl;
   delete[] vowels;
   delete[] consonants;
   return 0;
}
