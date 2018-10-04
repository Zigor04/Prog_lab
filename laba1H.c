#include<stdio.h>

#define M1 3
#define M2 5

int main()
{
	int array1[M1], array2[M2];//исходные массивы
	
	int array3[M1+M2];//массив, в который будут помещены индексы неотрицательных элементов исходных массивов
	
	int *ptr;
	
	int *ptr3;
	
	int k;//колличество неорицательных элементов в исходных массивах
	
	k = 0;
	
	ptr3 = array3;
	
	for(ptr = array1 ;ptr - array1 < M1; ptr++)
	{
		printf("Введите %d элемент массива array1=", ptr - array1);
		//ввод элемента
		scanf("%d", ptr);
		
		//если текущий элемент массива array1 неотрицательный
		if (*ptr >= 0)
		{
			*ptr3 = ptr - array1;
			ptr3++;
			k++;
		}
	}
	
	for(ptr = array2; ptr - array2 < M2; ptr++)
	{
		printf("Введите %d элемент массива array2=", ptr - array2);
		//ввод элемента
		scanf("%d", ptr);
		
		//если текущий элемент массива array2 неотрицательный
		if (*ptr >= 0)
		{
			*ptr3 = ptr-array2;
			ptr3++;
			k++;
		}
	}
	
	// встречались ли в исходных массивах неотрицательные элементы?
	if (k == 0)
	{
		printf("В исходных миссивах нет неотрицательных элементов!!!");
	}
	else//если встречались, то выводим array3 состоящий из k элементов
	{
		printf("Массив array3: ");
		
		for(ptr = array3;ptr - array3 < k; ptr++)
		{
			printf("%d  ", *ptr);
		}
	}
	
	return 0;
}