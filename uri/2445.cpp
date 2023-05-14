#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAXN 100010

int main () {
	int n;
	int lado[MAXN];
	bool acionou;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &lado[i]);
	sort(&lado[0], &lado[n]);
	
	int soma = 0;
	for (int i = 0; i < n; i++)
		soma += lado[i];
	
	acionou = false;
	int k;
	for (k = n-1; k >= 2; k--) {
		soma -= lado[k];
		if (lado[k] < soma) {
			acionou = true;
			break;
		}
	}
	if (acionou)
		printf("%d\n", k+1);
	else
		printf("0\n");
	
	return 0;
}
