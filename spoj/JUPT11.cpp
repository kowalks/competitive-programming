#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

ll bit [MAXN];
ll p, b;

void update (ll pos, ll val) {
	while (pos < MAXN) {
		bit[pos] = (bit[pos] + val) % p;
		pos += pos&-pos;
	}
}

ll query (ll pos) {
	ll val = 0;
	while (pos > 0) {
		val = (val + bit[pos]) % p;
		pos -= pos&-pos;
	}
	return val;
}

ll query (ll l, ll r) {
	ll resp = (query(r) - query(l-1));
	resp = (p  + (resp % p)) %p;
	return resp;
}

ll pow (ll exp) {
	exp %= p-1;
	if (exp == 0) return 1;
	ll val = pow (exp/2);
	val = (val*val) % p;
	if (exp&1) return (b*val) % p;
	return val;
}

void solve (ll l, ll n) {
	memset(bit, 0, sizeof(bit));
	while (n--) {
		char ch;
		scanf(" %c", &ch);
		if (ch == 'E') {
			ll i, v;
			scanf("%lld %lld", &i, &v);
			update(i, -query(i, i));
			update(i, (v*pow(l-i))%p);
		} else if (ch == 'H') {
			ll i, j;
			scanf("%lld %lld", &i, &j);
			ll q = query(i, j);
			ll exp = (p-1 + ((j - l)%(p-1)))%(p-1);
			q = (pow(exp) * q) % p;
			printf("%lld\n", (q + p) % p);
		}
	}
}

int main () {
	ll l, n;
	scanf("%lld %lld %lld %lld", &b, &p, &l, &n);
	while (b || p || l || n) {
		solve(l, n);
		printf("-\n");
		scanf("%lld %lld %lld %lld", &b, &p, &l, &n);
	}
}