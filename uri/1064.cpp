#include<stdio.h>

int main ()
{
	double n;
	double soma = 0;
	int cont = 0;
	for (int i= 0; i < 6; i++)
	{
		scanf("%lf", &n);
		if (n > 0)
		{
			cont++;
			soma += n;
		}
	}
	
	printf("%d valores positivos\n", cont);
	printf("%.1lf\n", soma/cont);
	
	return 0;
}
