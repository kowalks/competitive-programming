/*******************************
* AUTHOR : GUILHERME KOWALCZUK *
* NICK : KOWALKS               *
* INSTITUTION : ITA            *
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 100005
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



int main() {
	int ini, g1, g2, g3;
	SD2(ini, g1);
	SD2(g2, g3);

	while(ini!=0 || g1 !=0 || g2 != 0 || g3 != 0) {
		//printf("1-> %d\n", ((g1-ini>0)?(g1-ini):(g1-ini+40)));
		//printf("2-> %d\n", ((g1-g2>0)?(g1-g2):(g1-g2+40)));
		//printf("3-> %d\n", (g3-g2>0)?(g3-g2):(g3-g2+40));
		int resp = 720+((ini-g1>0)?(ini-g1):(ini-g1+40))*360/40+360+((g2-g1>0)?(g2-g1):(g2-g1+40))*360/40+((g2-g3>0)?(g2-g3):(g2-g3+40))*360/40;
		PD(resp);
		//printf("\n\n");
		SD2(ini, g1);
		SD2(g2, g3);
	}	

	return 0;
}