include <stdio.h>

int main()
{
    FILE* f = fopen("input.txt", "r");
    char c;
    while((c=fgetc(f))!=EOF )
    {
        printf("%c",c-(c=='\n'?0:4));
    }
    
    return 0;
}
