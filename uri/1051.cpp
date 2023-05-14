#include<stdio.h>

int main ()
{
	double money;
	int tax;
	scanf("%lf", &money);
	
	if (money <= 2000)
		printf("Isento\n");
	else if (money <= 3000.00)
		printf("R$ %.2lf\n",
			8/100.00*(money-2000));
	else if (money <= 4500.00)
		printf("R$ %.2lf\n",
			8/100.00*1000 + 18/100.00*(money-3000));
	else
		printf("R$ %.2lf\n", 
			8/100.00*1000 + 18/100.00*1500 + 28/100.00*(money-4500));
	
	
	return 0;
}
