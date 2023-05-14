#include<stdio.h>

int main ()
{
	int n;
	int cont = 0;
	
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		if (n%2 == 0)
			cont++;
	}
	
	printf("%d valores pares\n", cont);
	
	return 0;
}
