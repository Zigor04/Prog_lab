//Сравнить 2 строки а) по длнинне б) по совпадению
#include <stdio.h>
#define MAXLINE 100

 void longer_and_coincidence ( char [], char []);
 
 
 int main()
 {
	char line1[MAXLINE], line2[MAXLINE];
	
	printf("Введите 1 строку: ");
	fgets(line1, MAXLINE, stdin);
	
	printf("Введите 2 строку: ");
	fgets(line2, MAXLINE, stdin);
	
	longer_and_coincidence( line1, line2);
	
	getchar();
	return 0;
 }
 
 void longer_and_coincidence ( char buf1[], char buf2[])
 {
	char *ptr1, *ptr2; 
	int flag = 0, flagb = 1;
	//ля задачи а
	for(ptr1 = buf1, ptr2 = buf2; *ptr1 && *ptr2; ptr1++, ptr2++);
	
	if (*ptr1 == *ptr2)
	{
		flag = 0;
	}
	else
		flag = *ptr1? 1: -1;
	
	if (*ptr1 == *ptr2)
		flag = 0;
	//для забади в
	for(ptr1 = buf1, ptr2 = buf2; *ptr1 && *ptr2; ptr1++, ptr2++)
	{
		if (*ptr1 != *ptr2)
		{
			flagb = -1;
			break;
		}
	}
	//вывод
	if (flag == -1)
	{
		printf("Первая строка короче второй\n");
	}
	else
	{
		if(flag == 1)
		{
			printf("Первая строка длиннее второй\n");
		}
		else printf("Строки равны по длинне \n");
 
	}
	
	(flagb == 1) ? printf("Строки совпадают\n"):printf("Строки не совпадают\n");
	
 }