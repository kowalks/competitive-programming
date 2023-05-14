#include<stdio.h>

int main ()
{
	int num, h;
	double ph;
	scanf("%d %d %lf", &num, &h, &ph);
	printf("NUMBER = %d\n", num);
	printf("SALARY = U$ %.2lf\n", h*ph);
}
