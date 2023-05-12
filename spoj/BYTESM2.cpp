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

int h, w;
int chao[MAXN][MAXN];
int dp[MAXN][MAXN];

int computeDP(int i, int j) {
	if (dp[i][j] != 0)
		return dp[i][j];

	if (i < 0 || i >= h || j < 0 || j >= w)
		return 0;

	int max = -1;
	max = max(max, computeDP(i+1,j-1));
	max = max(max, computeDP(i+1,j));
	max = max(max, computeDP(i+1,j+1));

	return dp[i][j] = max + chao[i][j];
}

int main() {
	int t;
	SD(t);

	while(t--) {
		SD2(h, w);

		REP(i, 0, MAXN)
			REP(j, 0, MAXN)
				dp[i][j] = 0;

		REP(i, 0, h)
			REP(j, 0, w)
				SD(chao[i][j]);

		REP(i, 0, w)
			computeDP(0, i);

		int max = -1;
		REP(i, 0, w)
			max = max(max, dp[0][i]);
		PD(max);
	}


	return 0;
}