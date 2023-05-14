#include<stdio.h>

void swap (double* a, double* b)
{
	double aux = *a;
	*a = *b;
	*b= aux;
}

int main ()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a < b)
		swap(&a, &b);
	if (b < c)
		swap(&b, &c);
	if (a < b)
		swap(&a, &b);
	
	if (a >= b + c)
		printf("NAO FORMA TRIANGULO\n");
	else 
	{
		if (a*a == b*b + c*c)
			printf("TRIANGULO RETANGULO\n");
		else if (a*a > b*b + c*c)
			printf("TRIANGULO OBTUSANGULO\n");
		else
			printf("TRIANGULO ACUTANGULO\n");
		
		if (a==b && b==c)
			printf("TRIANGULO EQUILATERO\n");
		else if (a==b || b==c || c==a)
			printf("TRIANGULO ISOSCELES\n");
	
	}
	
	
	return 0;
}
