#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	FILE *pf_out;
	int *ptr_array, N, i;

	system("chcp 1251");
	if (fopen_s(&pf_out, "out_9.txt", "wt"))
	{
		printf("Error creating file for write");
		system("pause");
		return 1;
	}

	printf("Введите колличество эллементов массива: ");
	scanf("%d", &N);
	printf("\n");
	ptr_array = (int *)malloc(N * sizeof( int ) );

	for ( i = 0; i < N ; i++)
	{
		printf("Введите %d элемент массива: ", i);
		scanf("%d", ptr_array + i);
		printf("\n");
	}

	
	for (i = 0; ; i++)
	{
		if (*(ptr_array + i) <= 0)
		{
			*(ptr_array + i) = 0 ;
			fputc('\n', pf_out);
		}
		else
		{
			for (int k = 0; k< *(ptr_array+ i); k++)
			{
				fputc('A', pf_out);
			}
			if ((i + 1) == N)
				break;
			fputc('\n', pf_out);
		}
	}
	free(ptr_array);
	fclose(pf_out);
	return 0;
}
