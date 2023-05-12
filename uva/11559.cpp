#include<stdio.h>


int main () {
	int n, b, h, w, p, a;

	while (scanf("%d %d %d %d", &n, &b, &h, &w) > 0) {
		int price = 1000000;
		while(h--) {
			scanf("%d",&p);
			for (int i = 0; i < w; i++) {
				scanf("%d", &a);
				if (n*p <= b && a >=n)
					price = (price < n*p) ? price : n*p;
			}
		}

		if (price == 1000000)
			printf("stay home\n");
		else
			printf("%d\n", price);
	}
}