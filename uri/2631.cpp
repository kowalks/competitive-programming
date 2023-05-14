#include<stdio.h>
#define MAXN 10010

int pai[MAXN];

int find (int a){
	if (pai[a] == a) return a;
	return pai[a] = find(pai[a]);
}

bool unir (int a, int b){
	int i = find(a);
	int j = find(b);
	pai[i] = j;
}

int main (){
	int n, m, q, a, b, vez;
	vez = false;
	
	while(scanf("%d %d %d", &n, &m, &q) == 3){
		if (vez) printf("\n");
		vez = true;
		
		for (int i = 1; i <= n; i++){
			pai[i] = i;
		}
		
		for (int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			unir(a, b);
		}
		
		for (int i = 0; i < q; i++){
			scanf("%d %d", &a, &b);
			if (find(a) == find(b))
				printf("S\n");
			else
				printf("N\n");
		}
	}
	
	return 0;
}
