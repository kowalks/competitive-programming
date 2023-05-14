#include<stdio.h>

int main ()
{
	double salarioAntigo, salarioNovo;
	int perc;
	
	scanf("%lf", &salarioAntigo);
	
	if (salarioAntigo <= 400.00)
		perc = 15;
	else if (salarioAntigo <= 800.00)
		perc = 12;
	else if (salarioAntigo <= 1200.00)
		perc = 10;
	else if (salarioAntigo <= 2000.00)
		perc = 7;
	else
		perc = 4;
	
	salarioNovo = salarioAntigo*(1 + perc/100.00);
	
	printf("Novo salario: %.2lf\n", salarioNovo);
	printf("Reajuste ganho: %.2lf\n", salarioNovo - salarioAntigo);
	printf("Em percentual: %d %%\n", perc);	
		
	return 0;
}
