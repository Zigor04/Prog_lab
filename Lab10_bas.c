#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAXLINE 100
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	setlocale(LC_ALL, "Rus");

	FILE *ptrf_in, *ptrf_out;//файловые указатели
	char line[MAXLINE];//текущая строка
	char **str_ptr = NULL; //указатель на динамический массив указателей
	char *ptr = NULL;// указатель на текущую строку
	int i = 0;// номер строки
	int len;// длинна строки
	int flag = 0;
	int j;

	// открытие файловых потоков, проверка на успшность
	fopen_s(&ptrf_in, "INPUT10.txt", "rt");
	if (ptrf_in == NULL)
	{
		printf("Ошибка открытия файла\n");
		system("pause");
		return 1;
	}

	fopen_s(&ptrf_out, "OUTPUT10.txt", "wt");
	if (ptrf_in == NULL)
	{
		printf("Ошибка создания файла\n");
		system("pause");
		return 1;
	}

	while (!feof(ptrf_in))//если файл не исчерпан
	{
		ptr = fgets(line, MAXLINE, ptrf_in);//получить новую строку

		if (ptr != NULL)//если новая строка не пустая
		{
			//если ранее не встречались такие строк(для первой строки flag = 0 изначально, т.к. первая строка ранее точно не встречалась)
			for (j = 0; j < i; j++)
			{
				if (strcmp(*(str_ptr + j), ptr) == 0) // если одна из предыдущих строк   повторяется то flag = 1
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)//если строка ранее не встречалась
			{
				len = strlen(ptr);// получить длинну строки
				str_ptr = (char **) realloc(str_ptr, (i + 1) * sizeof(char *));//выделение динамической памяти для i эллемента динамического массива указателей
				*(str_ptr + i) = (char *) malloc((len + 1) * sizeof(char));//выделение памяти для строки
				strcpy_s( *(str_ptr + i),len+1, ptr);// копирование строки в выделеную память
				fputs(ptr, ptrf_out);//вывод строки, т.к. раньше она не встречалась
				i++;
			}
			flag = 0;
		}

	}
	//oсвобождение памяти, которую загнимал двумерный динамический массив

	for (j = 0; j < i; j++)
	{
		if(*(str_ptr + j) != NULL)
		{
			free(*(str_ptr + j));
			*(str_ptr + j) = NULL;
		}
	}
	if(str_ptr != NULL)
	{
		free(str_ptr);
		str_ptr = NULL;
	}
	
	fclose(ptrf_in);
	fclose(ptrf_out);
	return 0;
}
