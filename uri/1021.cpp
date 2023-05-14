#include<stdio.h>

int main ()
{
	double val;
	int n, centavos;
	scanf("%lf", &val);
	n = val;
	centavos = (val-n)*100;
	
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", n/100);
	n %= 100;
	printf("%d nota(s) de R$ 50.00\n", n/50);
	n %= 50;
	printf("%d nota(s) de R$ 20.00\n", n/20);
	n %= 20;
	printf("%d nota(s) de R$ 10.00\n", n/10);
	n %= 10;
	printf("%d nota(s) de R$ 5.00\n", n/5);
	n %= 5;
	printf("%d nota(s) de R$ 2.00\n", n/2);
	n %= 2;
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", n);
	printf("%d moeda(s) de R$ 0.50\n", centavos/50);
	centavos %= 50;
	printf("%d moeda(s) de R$ 0.25\n", centavos/25);
	centavos %= 25;
	printf("%d moeda(s) de R$ 0.10\n", centavos/10);
	centavos %= 10;
	printf("%d moeda(s) de R$ 0.05\n", centavos/5);
	centavos %= 5;
	printf("%d moeda(s) de R$ 0.01\n", centavos);
	
	
	return 0;
}
