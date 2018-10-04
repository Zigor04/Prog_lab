#include<stdio.h>

int main()
{
	char *ptr1, *ptr2, *ptr3;
	int length, i;
	char line[100];
	char lineMAX[120];
	char lineA[5] = "A72";

	
	printf("Введите строку: \n");
	fgets(line, 1000, stdin);
	
	for(length = 0,ptr1 = line ; *ptr1; ptr1++, length++);
	

	
	for( i = 0, ptr1 = line, ptr2 = lineMAX; i < length/2; i++,ptr1++,ptr2++)
	{
		*ptr2 = *ptr1;
	}
	
	for(i = 0, ptr3 = lineA ;i<3; i++,ptr3++,ptr2++)
	{
		*ptr2 = *ptr3;
	}
	

	for( ;*ptr1;ptr1++,ptr2++)
	{
		*ptr2 = *ptr1;
	}
	puts(lineMAX);
	
	getchar();
	
	return 0;
	
}