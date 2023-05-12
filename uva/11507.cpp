#include<stdio.h>

void positiveRotation (int &a, int &b)
{
	int aux = a;
	a = -b;
	b = aux;
}

int main () {
	int l;
	int x, y, z;
	char sign, axis, linebreaker;
	scanf(" %d ", &l);
	while(l != 0) {
		x = 1;
		y = 0;
		z = 0;
		do {
			scanf("%c%c%c", &sign, &axis, &linebreaker);
			if (axis == 'y')
				if (sign == '+')
					positiveRotation(x, y);
				else
					positiveRotation(y, x);
			else if (axis == 'z')
				if (sign == '+')
					positiveRotation(x, z);
				else
					positiveRotation(z, x);
		} while(linebreaker != '\n');

		if (x > 0 || y > 0 || z > 0)
			printf("+");
		else
			printf("-");
		if (x != 0)
			printf("x");
		else if (y != 0)
			printf("y");
		else
			printf("z");
		printf("\n");
		scanf(" %d ", &l);
	}

	return 0;
}