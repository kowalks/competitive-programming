#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

ll bit1[MAXN], bit2[MAXN];

void update (ll *bit, ll pos, ll val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

ll query (ll *bit, ll pos) {
	ll val = 0;
	while (pos > 0) {
		val += bit[pos];
		pos -= pos&-pos;
	}
	return val;
}

void update (ll p, ll q, ll val) {
	update (bit1, p, val);
	update (bit1, q+1, -val);
	update (bit2, p, val*(p-1));
	update (bit2, q+1, -val*q);
}

ll query (ll p) {
	return p*query(bit1, p) - query(bit2, p);
}

ll query (ll p, ll q) {
	return query(q) - query(p-1);
}

void solve () {
	ll n, c, sw, p, q, v;
	scanf("%lld %lld", &n, &c);
	memset(bit1, 0, sizeof(bit1));
	memset(bit2, 0, sizeof(bit2));
	while (c--) {
		scanf("%lld", &sw);
		if (sw == 0) {
			scanf("%lld %lld %lld", &p, &q, &v);
			update(p, q, v);
		}
		else {
			scanf("%lld %lld", &p, &q);
			printf("%lld\n", query(p, q));
		}
	}
}

int main () {
	ll t;
	scanf("%lld", &t);
	while (t--)
		solve();
}
