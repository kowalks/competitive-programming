#include<stdio.h>

int main ()
{
	int code1, units1, code2, units2;
	double price1, price2;
	
	scanf("%d %d %lf", &code1, &units1, &price1);
	scanf("%d %d %lf", &code2, &units2, &price2);
	
	printf("VALOR A PAGAR: R$ %.2lf\n", units1*price1+units2*price2);
	
	return 0;
}
