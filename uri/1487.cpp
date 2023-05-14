#include<stdio.h>
#define MAXN 102


struct bq {
	int duracao;
	int pontuacao;
};

struct bq brinquedo[MAXN];

int dp[610];

int main () {
	int n, t, d, p;
	int instancia = 0;
	
	scanf("%d %d", &n, &t);
	
	while (n != 0) {
		instancia++;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &brinquedo[i].duracao, &brinquedo[i].pontuacao);
		
		for (int i = 0; i <= t; i++) {
			dp[i] = 0;
			for (int j = 0; j < n; j++) {
				if (i - brinquedo[j].duracao >= 0)
					if (dp[i - brinquedo[j].duracao] + brinquedo[j].pontuacao > dp[i])
						dp[i] = dp[i - brinquedo[j].duracao] + brinquedo[j].pontuacao;
			}
		}
		
		printf("Instancia %d\n%d\n\n", instancia, dp[t]);
		
		scanf("%d %d", &n, &t);
	}
	
	
	return 0;
}
