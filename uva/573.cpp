#include<stdio.h>


int main () {
	int h, u, d, f;
	double up;
	scanf("%d %d %d %d", &h, &u, &d, &f);
	while(h != 0){
		double altura = 0;
		up = u;
		int i;
		for (i =1; ; i++) {
			if (up > 0) {
				altura += up;
				up -= 1.0*f*u/100;
			}
			
			if (altura > h)
				break;
			altura -= d;
			if (altura < 0)
				break;
		}
		if (altura < 0)
			printf("failure on day %d\n", i);
		else
			printf("success on day %d\n", i);
		scanf("%d %d %d %d", &h, &u, &d, &f);
	}

	return 0;
}