#include<bits/stdc++.h>
#define MAXN 10000007
#define int long long
using namespace std;

int bit[MAXN];

void update (int pos, int val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

int query (int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= pos&-pos;
	}
	return sum;
}

int query (int l, int r) {
	return query(r) - query(l-1);
}

void solve() {
	int n, sum = 0, val;
	scanf("%lld", &n);
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &val);
		sum += query(val, MAXN);
		update(val, 1);
	}
	printf("%lld\n", sum);
}

main () {
	int t;
	scanf("%lld", &t);
	while (t--)
		solve();
}