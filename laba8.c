#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

void delitelongerword ( char bufer[] );

void main ( void )
{
	char line[MAXLINE];

	printf("Введите строку символов: ");
	gets( line );

	delitelongerword( line );

	puts( line );
}

void delitelongerword ( char bufer[] )
{
	char *buf_ptr;//указатель на адрес обрабатываемого элемента строки
	char *start_ptr;//указатель на адрес элемента начала слова
	char *stop_ptr;//указатель на адрес элемента конца слова
	int flag;
    char *beginmax_ptr;//указатель на адрес элемента начала самого длинного слова
    char *endmax_ptr;//указатель на адрес элемента конца самого длинного слова
	int max;//Разность указателей начала самого длинного слова и конца самого длинного слова

	
	start_ptr = stop_ptr = buf_ptr = bufer;
	max = 0;
	flag = NO;


	do 
	{
		//если втречен разделитель
		if (*buf_ptr ==' ' || *buf_ptr ==',' || *buf_ptr =='.' || *buf_ptr =='!' || *buf_ptr =='?' || *buf_ptr =='\0' || *buf_ptr == '\n')
		{
			if( flag == YES)
			{
				stop_ptr = buf_ptr - 1;
				if (max < ( stop_ptr - start_ptr +1 ))
				{
					max = (stop_ptr - start_ptr + 1);
					beginmax_ptr = start_ptr;
					endmax_ptr = stop_ptr;
				}

				flag = NO;
			}
		}
		else
		{
			if (flag == NO)
			{
				start_ptr = buf_ptr;
				flag = YES;
			}
		}


		buf_ptr++;
	} while( *buf_ptr != '\0');


	//удалить самое длинное слово

	endmax_ptr += 2;
	
	for( ; *beginmax_ptr != '\0'; beginmax_ptr++) 
	{ 
		*beginmax_ptr = *endmax_ptr; 
		endmax_ptr++; 
	} 
	*endmax_ptr = '\0';

}