#include<stdio.h>

int main ()
{
	int a, b, h;
	scanf("%d %d", &a, &b);
	
	if (a < b)
		h = b-a;
	else
		h = 24 + b - a;
	
	printf("O JOGO DUROU %d HORA(S)\n", h);
	
	return 0;
}
