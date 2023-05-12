#include<bits/stdc++.h>
#define MOD 5000000
#define int long long
#define MAXN 100004
using namespace std;

int bit[MAXN];
int dp[MAXN];

void update(int pos, int val) {
	while (pos < MAXN) {
		bit[pos] = (bit[pos] + val) % MOD;
		pos += pos&-pos;
	}
}

int query (int pos) {
	int val = 0;
	while (pos > 0) {
		val = (val + bit[pos]) % MOD;
		pos -= pos&-pos;
	}
	return val;
}

int query (int p, int q) {
	return (query(q) - query(p-1)) % MOD;
}

struct val {
	int val, pos;
};

bool comp (struct val a, struct val b) {
	return (a.val > b.val) || (a.val == b.val && a.pos < b.pos);
}

main () {
	int n, k, pos;
	struct val a[MAXN];
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].val);
		a[i].pos = i;
	}

	sort (a+1, a+n+1, comp);

	int prev = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i].val != prev) {
			dp[a[i].pos] = 1;
			update(a[i].pos, 1);
		}
		prev = a[i].val;
	}

	for (int i = 2; i <= k; i++) {
		prev = -1;
		for (int j = 1; j <= n; j++) {
			pos = a[j].pos;
			if (a[j].val != prev) {
				update(pos, -dp[pos]);
				dp[pos] = query(pos);
			} else {
				int posant = a[j-1].pos;
				update(pos, -dp[pos]);
				dp[pos] = query(posant+1, pos);
			}

			prev = a[j].val;
		}
		for (int j = 1; j <=n; j++)
			update(j, dp[j]);
	}


	int resp = 0;
	for (int i = 1; i <= n; i++)
		resp = (resp + dp[i]) % MOD;

	printf("%lld\n", (resp > 0) ? resp : (resp+ MOD) % MOD);
}