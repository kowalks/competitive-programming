#include<stdio.h>

int abs(int a)
{
	if (a >= 0) return a;
	return -a;
}

int maior(int a, int b)
{
	return (a+b+abs(a-b))/2;
}

int main ()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d eh o maior\n", maior(a, maior(b,c)));
}
