#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;

ll bit1[MAXN], bit2[MAXN];

void update (ll *bit, ll pos, ll val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

ll query (ll *bit, ll pos) {
	ll sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= pos&-pos;
	}
	return sum;
}

void update (ll l, ll r, ll val) {
	update(bit1, l, val);
	update(bit1, r+1, -val);
	update(bit2, l, val*(l-1));
	update(bit2, r+1, -val*r);
}

ll query (ll pos) {
	return pos*query(bit1, pos) - query(bit2, pos);
}

ll query (ll l, ll r) {
	return query(r) - query(l-1); 
}

void solve() {
	ll n, c, p, q, v;
	scanf("%lld %lld", &n, &c);
	memset(bit1, 0, sizeof(bit1));
	memset(bit2, 0, sizeof(bit2));
	while (c--) {
		ll ch;
		scanf("%lld", &ch);
		if (ch == 1) {
			scanf("%lld %lld", &p, &q);
			printf("%lld\n", query(p, q));
		}
		else {
			scanf("%lld %lld %lld", &p, &q, &v);
			update(p, q, v);
		}
	}
}

int main () {
	ll t;
	scanf("%lld", &t);
	while(t--)
		solve();
}