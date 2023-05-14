#include<stdio.h>

int abs (float a)
{
	if (a >= 0) return a;
	return -a;
}

int main ()
{
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	
	if (abs(a-b) < c && c < a+b)
		printf("Perimetro = %.1f\n", a+b+c);
	else
		printf("Area = %.1f\n", (a+b)*c/2);
	
	return 0;
}
