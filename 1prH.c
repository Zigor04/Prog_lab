#include<stdio.h>

int main()
{
	int a,b;
	
	printf("введите а = ");
	scanf("%d", &a);
	
	printf("введите b = ");
	scanf("%d", &b);
	
	a>b ? printf(" %d", a): printf(" %d", b);
	return 0;
}