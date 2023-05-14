#include<stdio.h>

int main () {
	int n;
	int nota[10010];
	int soma, comp, media;
	
	while (scanf("%d", &n) == 1) {
		soma = 0;
		comp= 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &nota[i]);
			soma += nota[i];
		}
		
		if (soma % n == 0) {
			media = soma/n;
			for (int i = 0; i < n; i++)
				comp += (media - nota[i] > 0) ? media - nota[i] : nota[i] - media;
			printf("%d\n", comp/2 + 1);
		} else
			printf("-1\n");
		
	}
	
	
	return 0;
}
