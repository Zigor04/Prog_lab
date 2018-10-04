//поменять в массиве чётные и нечётные эллементы местами
#include<stdio.h>
int main()
{
	char line[1000];
	char *ptr;
	char swap;
	
	printf("Введите строку: ");
	fgets(line, 1000, stdin);
	
	for(ptr = line; *ptr && *(ptr + 1); ptr +=2)
	{
		swap = *ptr;
		*ptr = *(ptr+1);
		*(ptr+1) = swap;
	}
	
	puts(line);
	
	return 0;
}