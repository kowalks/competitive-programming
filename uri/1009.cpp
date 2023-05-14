#include<stdio.h>

int main ()
{
	char nome[100];
	double salary, sale;
	
	scanf("%s", &nome);
	scanf("%lf %lf", &salary, &sale);
	
	printf("TOTAL = R$ %.2lf\n", salary+0.15*sale);
}
