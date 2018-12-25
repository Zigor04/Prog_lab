/*Задача 11.6
Вывести на экран содержимое файла с программой на языке С, выделяя в строке все
идентификаторы.*/
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	FILE *fp;
	char line[1000], line_id[1000][100], word[100];
	char *ptr;
	int flag_ident = 0, flag_ag = 0, i = 0, j, flag_skob = 0;
	WORD foregroundColor0;
	WORD textAttribute;
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN;

	system("chcp 1251");

	fopen_s(&fp, "IN11.txt", "rt");

	if (fp == NULL)
	{
		printf("Error oppening file");
		system("pause");
		return 1;
	}

	while (!feof(fp))
	{

		if ((ptr = fgets(line, 1000, fp)) != NULL)
		{
			while (*ptr != '\0')
			{
				//игнор комментов
				if (*ptr == '/')
				{
					ptr++;
					if (*ptr == '/')
					{
						while (*ptr != '\0')
							ptr++;
					}
					if (*ptr == '*')
					{
						ptr++;
						while ((*ptr != '*') && (*(ptr + 1) != '/'))
						{
							if (*ptr == '\0')
							{
								ptr = fgets(line, 1000, fp);
							}
							ptr++;
						}
					}
				}
				//

				if ((*ptr == 'i') && (*(ptr + 1) == 'n') && (*(ptr + 2) == 't'))//если встречено описание int
				{
					flag_ident = 1;
					ptr += 3;
				}
				if ((*ptr == 'v') && (*(ptr + 1) == 'o') && (*(ptr + 2) == 'i') && (*(ptr + 3) == 'd'))//если встречено описание int
				{
					flag_ident = 1;
					ptr += 4;
				}
				if ((*ptr == 'c') && (*(ptr + 1) == 'h') && (*(ptr + 2) == 'a') && (*(ptr + 3) == 'r'))//если встречено описание char
				{
					flag_ident = 1;
					ptr += 4;
				}
				if ((*ptr == 'f') && (*(ptr + 1) == 'l') && (*(ptr + 2) == 'o') && (*(ptr + 3) == 'a') && (*(ptr + 4) == 't'))//если встречено описание float
				{
					flag_ident = 1;
					ptr += 5;
				}
				if ((*ptr == 'd') && (*(ptr + 1) == 'o') && (*(ptr + 2) == 'u') && (*(ptr + 3) == 'b') && (*(ptr + 4) == 'l') && (*(ptr + 5) == 'e'))//если встречено описание double
				{
					flag_ident = 1;

					ptr += 6;
				}
				if ((*ptr == 'l') && (*(ptr + 1) == 'o') && (*(ptr + 2) == 'n') && (*(ptr + 3) == 'g') && (*(ptr + 4) == ' ') && (*(ptr + 5) == 'i') && (*(ptr + 6) == 'n') && (*(ptr + 7) == 't'))//если встречено описание long int
				{
					flag_ident = 1;
					ptr += 8;
				}
				if ((*ptr == 's') && (*(ptr + 1) == 'h') && (*(ptr + 2) == 'o') && (*(ptr + 3) == 'r') && (*(ptr + 4) == 't') && (*(ptr + 5) == ' ') && (*(ptr + 6) == 'i') && (*(ptr + 7) == 'n') && (*(ptr + 8) == 't'))//если встречено описание short int
				{
					flag_ident = 1;
					ptr += 9;
				}

				if (flag_ident == 1 || flag_ag == 1)
				{
					flag_ag = 0;
					while ((*ptr == ' ') || (*ptr == '*'))
						ptr++;
					j = 0;
					if ((*ptr == ',') || (*ptr == ' ') || (*ptr == ')') || (*ptr == '['))
					{
						ptr++;
						flag_ident = 0;
						continue;
					}
					while (!((*ptr == ';') || (*ptr == '(') || (*ptr == ')') || (*ptr == '=') || (*ptr == ' ') || (*ptr == ',') || (*ptr == '[')))
					{
						line_id[i][j] = *ptr;
						j++;

						while (*ptr == ' ' || *ptr == '*')
							ptr++;
						ptr++;
						while (*ptr == ' ' || *ptr == '*')
							ptr++;
						if (*ptr == '(')
							flag_skob = 1;
						if (*ptr == ')')
							flag_skob = 0;
					}
					line_id[i][j] = '\0';
					i++;
					flag_ident = 0;
					if (flag_skob == 0)
					{
						if (*ptr == ' ' || *ptr == '=' || *ptr == ',')
						{
							if (*ptr == ',')
							{
								flag_ag = 1;
								ptr++;
								continue;
							}
							else
							{
								while (*ptr == ' ' || *ptr == '=' || ((*ptr >= '0') && (*ptr <= '9')))
									ptr++;
								if (*ptr == ',')
								{
									flag_ag = 1;
									ptr++;
									continue;
								}
							}
						}
					}

				}

				ptr++;
			}
		}
	}
	fclose(fp);
	//Все идентификаторы занесены в массив
	//выделение идентификаторов цветом
	fopen_s(&fp, "IN11.txt", "rt");

	if (fp == NULL)
	{
		printf("Error oppening file");
		system("pause");
		return 1;
	}

	while (!feof(fp))
	{

		if ((ptr = fgets(line, 1000, fp)) != NULL)
		{
			while (*ptr != '\0')
			{
				//игнор комментов
				if (*ptr == '/')
				{
					putc(*ptr, stdout);
					ptr++;
					if (*ptr == '/')
					{
						while (*(ptr+1) != '\0')
						{
							putc(*ptr, stdout);
							ptr++;
						}
					}
					if (*ptr == '*')
					{
						putc(*ptr, stdout);
						ptr++;
						while ((*ptr != '*') && (*(ptr + 1) != '/'))
						{
							if (*ptr == '\0')
							{
								putc(*ptr, stdout);
								ptr = fgets(line, 1000, fp);
							}
							putc(*ptr, stdout);
							ptr++;
						}
					}
				}
				//
				if (((*ptr > 'a') && (*ptr <'z')) || ((*ptr > 'A') && (*ptr < 'Z')))// не разделитель, значит встчечено слово
				{ 
					j = 0;
					while (((*ptr >= 'a') && (*ptr <= 'z')) || ((*ptr >= 'A') && (*ptr <= 'Z')) || (*ptr == '_') || ((*ptr >= '0') && (*ptr <= '9')))//записываем слово в word
					{
						word[j] = *ptr;
						ptr++;
						j++;
					}
					word[j] = '\0';
					flag_ident = 0;
					for (j = 0; j < i; j++)
					{
						if (strcmp(word, *(line_id + j)) == 0)
						{
							flag_ident = 1;
							break;
						}
					}
					if (flag_ident == 1)
					{
						//вывод word в цвете
						textAttribute = foregroundColor0;
						SetConsoleTextAttribute(hStdout, textAttribute);
						printf("%s", word);
						SetConsoleTextAttribute(hStdout, 7);
					}
					else
					{
						printf("%s", word);
					}

				}
				//
				putc(*ptr, stdout);
				ptr++;
			}
		}
	}
	system("pause");
	return 0;
}
