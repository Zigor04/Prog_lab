//поменять в строке все "e" на "S"
#include<stdio.h>
int main()
{
	char line[100];
	char *ptr;
	
	printf("Введите строку символов: ");
	fgets(line, 100, stdin);
	
	for(ptr = line; *ptr; ptr++)
	{
		*ptr = ( *ptr == 'e')?'S':*ptr;
	}
	
	puts(line);
	
	return 0;
}