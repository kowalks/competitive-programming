#include<stdio.h>
#define MAXN 1010

int main () {
	int n, h;
	int pino[MAXN];
	int total = 0;
	
	scanf("%d %d", &n, &h);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &pino[i]);
		pino[i] -= h;
	}
	
	if (n == 1) {
		total = (pino[0] > 0) ? pino[0] : -pino[0];
		goto end;
	}
	for (int i = 0; i < n-1; i++) {
		total += (pino[i] > 0) ? pino[i] : -pino[i];
		pino[i+1] -= pino[i];
	}
	
	end:
	printf("%d\n", total);
}
