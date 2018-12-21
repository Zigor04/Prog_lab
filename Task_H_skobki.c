#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *pf_in;
	char line[1000],*ptr;
	int cout = -1;
	char stack[500],*ptr_stack;
	system("chcp 1251");

	ptr_stack = stack;
	fopen_s(&pf_in, "IN_S.txt", "rt");
	if (pf_in == NULL)
	{
		printf("Error oppening file");
		system("pause");
		return 1;
	}
	while(!feof(pf_in))
	{
		if (ptr = fgets(line, 1000, pf_in))
		{
			do
			{
				if ((*ptr == '(') || (*ptr == '[') || (*ptr == '{'))
				{
					cout++;
					*(ptr_stack+cout) = *ptr;
				}

				if (*ptr == ')')
				{
					if (*(ptr_stack + cout) == '(')
					{
						
						cout--;
					}
					else
					{
						printf("Скобки расставлены неправильно!\n");
						system("pause");
						fclose(pf_in);
						return 0;
					}
				}

				if (*ptr == ']')
				{
					if (*(ptr_stack + cout) == '[')
					{
						cout--;
					}
					else
					{
						printf("Скобки расставлены неправильно!\n");
						system("pause");
						fclose(pf_in);
						return 0;
					}
				}

				if (*ptr == '}')
				{
					if (*(ptr_stack + cout) == '{')
					{
						cout--;
					}
					else
					{
						printf("Скобки расставлены неправильно!\n");
						system("pause");
						fclose(pf_in);
						return 0;
					}
				}

				ptr++;
			} while (*ptr != '\0');
		}
	}
	if (cout == -1)
	{
		printf("Скобки расставлены правильно!\n");
	}
	else
	{
		printf("Скобки расставлены неправильно!\n");
	}
	fclose(pf_in);
	system("pause");
	return 0;
}
