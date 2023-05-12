/*******************************
* AUTHOR : GUILHERME KOWALCZUK *
* NICK : KOWALKS               *
* INSTITUTION : ITA            *
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 105
#define MOD 1000000007
#define PII pair<int, int>
#define VP vector< pii > 
#define DD double
#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define PD(x) printf("%d\n", x)
#define PD2(x,y) printf("%d %d\n", x, y)
#define PLLD(x) printf("%lld\n", x)
#define PLLD2(x,y) printf("%lld %lld\n", x, y)
#define SD(x) scanf("%d", &x)
#define SLLD(x) scanf("%lld", &x)
#define SD2(x,y) scanf("%d %d", &x, &y)
#define SLLD2(x,y) scanf("%lld %lld", &x, &y)

int dp[50005];

int main() {
	int m, n;
	int moeda[MAXN];
	SD(m);
	while(m != 0) {
		REP(i, 0, m+1)
			dp[i] = 10000000;
		SD(n);

		REP(i, 0, n)
			SD(moeda[i]);

		dp[0] = 0;
		REP(i, 0, m+1)
			REP(j, 0, n)
				if (i - moeda[j] >= 0)
					dp[i] = min(dp[i], dp[i - moeda[j]] + 1);

		if (dp[m] < 10000000)
			PD(dp[m]);
		else
			printf("Impossivel\n");


		SD(m);
	}

	return 0;
}