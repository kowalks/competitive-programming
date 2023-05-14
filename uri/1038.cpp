#include<stdio.h>

int main ()
{
	int code, qtd;
	double total;
	scanf("%d %d", &code, &qtd);
	
	switch(code)
	{
		case 1:
			total = 4.0*qtd;
			break;
		case 2:
			total = 4.5*qtd;
			break;
		case 3:
			total = 5*qtd;
			break;
		case 4:
			total = 2*qtd;
			break;
		case 5:
			total = 1.5*qtd;
			break;
	}
	
	printf("Total: R$ %.2lf\n", total);
	
	return 0;
}
