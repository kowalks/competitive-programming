#include<stdio.h>

int main () {
	long long n;
	
	scanf("%lld", &n);
	
	while (n > 0) {
		printf("1");
		for (long long i = 2, quad = 4; quad <= n; ) {
			printf("% lld", quad);
			i++;
			quad = i*i;
		}
		printf("\n");
		scanf("%lld", &n);
	}
}
