#include<stdio.h>

int main ()
{
	int time, speed;
	scanf("%d %d", &time, &speed);
	printf("%.3lf\n", (double) speed*time/12.0);
	return 0;
}
