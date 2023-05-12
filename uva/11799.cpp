#include<stdio.h>

int main () {
	int t;
	int n, s;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int max = -1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &s);
			max = (max > s) ? max : s;
		}
		
		printf("Case %d: %d\n", i, max);
	}


	return 0;
}