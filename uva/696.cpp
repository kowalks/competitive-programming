#include<stdio.h>

int main (){
	int m, n, q;
	scanf("%d %d", &m, &n);
	while(m!=0 || n!= 0) {
		if (m>= 3 && n>=3)
			printf("%d", (m*n+1)/2);
		else if (m==1)
			printf("%d", n);
		else if (n==1)
			printf("%d", m);
		else if (m==2) {
			q = n%4;
			if (q==3)
				q = 2;
			printf("%d", n - n%4 + 2*q);
		} else {
			q = m%4;
			if (q==3)
				q = 2;
			printf("%d", m - m%4 + 2*q);
		}

		printf(" knights may be placed on a %d row %d column board.\n", m, n);
		scanf("%d %d", &m, &n);
	}


	return 0;
}