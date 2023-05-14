#include<stdio.h>

int main ()
{
	int a, b, c, x, y, z;
	scanf("%d %d %d", &a, &b, &c);
	
	if (a >= b && b >= c)
	{
		x = c;
		y = b;
		z = a;
	}
	else if (a <= b && b <= c)
	{
		x = a;
		y = b;
		z = c;
	}
	else if (a >= c && c >= b)
	{
		x = b;
		y = c;
		z = a;
	}
	else if (a <=c && c <= b)
	{
		x = a;
		y = c;
		z = b;
	}
	else if (b >= a && a >= c)
	{
		x = c;
		y = a;
		z = b;
	}
	else if(b <= a && a <= c)
	{
		x = b;
		y = a;
		z = c;
	}
	
	printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", x, y, z, a, b, c);
	
	
	return 0;
}
