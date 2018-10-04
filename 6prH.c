#include<stdio.h>
int main()
{
	char line[1000];
	char *ptr;
	int k = 0;
	
	printf("Введите строку: ");
	fgets(line, 1000, stdin);
	
	for( ptr = line;*(ptr+1); ptr++)
	{
		k = ((*ptr == 'b') && (*(ptr+1) == 'c'))? k+1:k;
	}
	
	printf("Колличество ''bc'' в строке = %d", k);
	getchar();
	return 0;
}