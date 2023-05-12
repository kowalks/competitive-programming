#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;

int BIT[MAXN];

void updatebit(int pos, int val) {
	while (pos < MAXN) {
		BIT[pos] += val;
		pos += pos&-pos;
	}
}

int querybit(int pos) {
	int soma = 0;
	while (pos > 0) {
		soma += BIT[pos];
		pos -= pos&-pos;
	}
	return soma;
}

void updaterange (int i, int j, int val) {
	updatebit(i, val);
	updatebit(j+1, -val);
}

int querypoint (int pos) {
	return querybit(pos);
}

void solve () {
	int n, u, l, r, val, q, i;
	scanf("%d %d", &n, &u);

	memset(BIT, 0, sizeof(BIT));

	while (u--) {
		scanf("%d %d %d", &l, &r, &val);
		updaterange(l+1, r+1, val);
	}

	scanf("%d", &q);

	while(q--) {
		scanf("%d", &i);
		printf("%d\n", querypoint(i+1));
	}
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}