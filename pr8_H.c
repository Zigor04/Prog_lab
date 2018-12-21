#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1000
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	FILE *pf_i = NULL, *pf_o = NULL;
	char line1[MAXLINE];
	char line2[MAXLINE];
	char *ptr1, *ptr2;

	system("chcp 1251");

	if (((pf_i = fopen( "IN_8.txt", "rt")) == NULL) || ((pf_o = fopen("OUT_8.txt", "wt")) == NULL))
	{
		printf("Error oppening or creating files");
		system("pause");
		return 1;
	}
	while (!feof(pf_i))
	{
		if ((ptr1 = fgets(line1, MAXLINE, pf_i)) != NULL)
		{
			if ((ptr2 = fgets(line2, MAXLINE, pf_i)) != NULL)
			{
				fputs(ptr2, pf_o);
			}
			fputs(ptr1, pf_o);
		}
	}
	fclose(pf_i);
	fclose(pf_o);
	return 0;
}
