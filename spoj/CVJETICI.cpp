#include<bits/stdc++.h>
#define MAXN 100005
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

void update (int l, int r, int val) {
	update(l, val);
	update(r+1, -val);
}

int main () {
	int n, l, r;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &l, &r);
		int ql = query(l);
		int qr = query(r);
		update(l, l, -ql);
		update(r, r, -qr);
		printf("%d\n", ql+qr);
		if (l != r+1)
			update (l+1, r-1, 1);
	}	
}