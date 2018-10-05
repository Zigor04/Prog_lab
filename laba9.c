//Скопировать содержимое текстового файла, заменив все цифры на их словесный эквивалент
#include<stdio.h>


int main()
{
	char line[1000];
	FILE *filein, *fileout;
	char *ptr;
	
	
	if ( (filein = fopen("in.txt","rt")) == NULL) return 1;
	if ( (fileout = fopen("out.txt","wt")) == NULL) return 1;
	
	while( !feof(filein))
	{
		ptr = fgets(line, 100, filein);
		if (ptr == NULL) break;
		
		//копирует в файл out строку, с заменёнными цифрами
		do
		{
			//если левый и правый элемент не буква, т.е. является разделителем и не цифра, то есть *ptr является цифрой, а не разрядом числа
			if ((((*(ptr+1)<'0') || (*(ptr+1)>'9')) && ((*(ptr+1) < 'a') || (*(ptr+1) >'z')) && ((*(ptr+1) < 'A') || (*(ptr+1) > 'Z' ))) && 
			(((*(ptr-1)<'0') || (*(ptr-1)>'9')) && ((*(ptr-1) < 'a') || (*(ptr-1) >'z')) && ((*(ptr-1) < 'A') || (*(ptr-1) > 'Z' ))))
			{
		
				switch(*ptr){
					case '0': fprintf(fileout,"ziro"); break;//ziro
					case '1': fprintf(fileout,"one"); break;//one
					case '2': fprintf(fileout,"two"); break;//two
					case '3': fprintf(fileout,"three"); break;//three
					case '4': fprintf(fileout,"four"); break;//four
					case '5': fprintf(fileout,"five"); break;//five
					case '6': fprintf(fileout,"six"); break;//six
					case '7': fprintf(fileout,"seven"); break;//seven
					case '8': fprintf(fileout,"eight"); break;//eight
					case '9' : fprintf(fileout,"nine"); break;//nine
					default : fputc(*ptr, fileout); break;
				}
				ptr++;
			}
			else
			{
				fputc(*ptr, fileout);
				ptr++;
			}
			
		}while(*ptr);		
	}
	
	fclose(filein);
	fclose(fileout);
	
	return 0;
}