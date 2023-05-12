#include<bits/stdc++.h>
#define MOD 5000000
#define MAXN 10004
using namespace std;

int bit[MAXN];
int dp[MAXN];

void update (int pos, int val) {
	while (pos < MAXN) {
		bit[pos] =  (bit[pos] + val) % MOD;
		pos += pos&-pos;
	}
}

int query (int pos) {
	int val = 0;
	while (pos > 0) {
		val = (val+ bit[pos]) % MOD;
		pos -= pos&-pos;
	}
	return val;
}

struct val {
	int val, pos;
};

bool comp (struct val a, struct val b) {
	return (a.val > b.val) || (a.val == b.val && a.pos < b.pos);
}

int main() {
	int n, k;
	struct val a[MAXN];
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].val);
		a[i].pos = i;
	}

	sort(a+1, a+n+1, comp);

	for (int i = 1; i <= n; i++) {
		update(i, 1);
		dp[i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			int pos = a[j].pos;
			update(pos, -dp[pos]);
			dp[pos] = query(pos);
		}
		for (int j = 1; j <= n; j++)
			update(j, dp[j]);
	}

	int resp = 0;
	for (int i = 1; i <= n; i++)
		resp = (resp + dp[i]) % MOD;

	printf("%d\n", (resp > 0) ? resp : (resp+ MOD) % MOD);
}