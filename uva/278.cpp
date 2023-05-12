#include<stdio.h>

int main () {
	int n;
	char c;
	int a, b;
	scanf("%d ", &n);
	while(n--) {
		scanf(" %c %d %d ", &c, &a, &b);
		switch(c) {
			case 'Q':
			case 'r': printf("%d\n", (a<b)?a:b); break;
			case 'k': printf("%d\n", ((a*b) + 1)/2); break;
			case 'K': printf("%d\n", ((a+1)/2)*((b+1)/2));
		}
	}

	return 0;
}