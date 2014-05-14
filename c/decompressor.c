#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("decompressor.in","r");
	char buff[50];
	fgets(buff,50,fp);
	int count = atoi(buff);
	char dictionary[count][50];
	for(int i =0 ; i < count;i++)
	{
		fgets(dictionary[i],50,fp);
		dictionary[i][strlen(dictionary[i])-1] = '\0';
	}
	char format[500];
	fgets(format,500,fp);
	char* c = format;
	do{
		if(*c =='E')break;
		char block[5] = "";
		while(*c !=' ' && *c != 'E'){
			int size = strlen(block);
			block[size] = *c;
			block[size+1] = '\0';
			c++;
		}
		char out[50] = "";
		char* ch = block;
		if(strlen(block)>0 && *ch >='0' && *ch <='9')
		{

			sprintf(out,"%s",dictionary[atoi(block)]);
			while(*ch >= '0' && *ch <='9')
				ch++;
			switch(*ch){
				case '!':
					for(char* b = out;*b!='\0';b++)
						*b ^= 0x20;
				break;
				case '^':
					*out ^= 0x20;
				break;

					
			}
			if(*(c+1)>='0' && *(c+1) <='9')strncat(out," ",1);	
		}else{
			switch(*ch){
				case 'R':
					strcpy(out,"\n");
				break;
				case '-':
					strcpy(out,"-");
				break;
				default:
					strcpy(out, block);
					strncat(out," ",1);
				break;
			}
		}
		printf("%s",out);
	}while(*(c++) != 'E');
	return 0;
}
