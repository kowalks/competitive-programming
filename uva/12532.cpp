#include<bits/stdc++.h>
#define MAXN 100005

using namespace std;

int bit[MAXN];
int bitzero[MAXN];

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

void updatezero (int pos, int val) {
	while (pos < MAXN) {
		bitzero[pos] += val;
		pos += pos&-pos;
	}
}

int queryzero (int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += bitzero[pos];
		pos -= pos&-pos;
	}
	return sum;
}

int queryzero (int l, int r) {
	return queryzero(r) - queryzero(l-1);
}

void solve (int n, int k) {
	memset(bitzero, 0, sizeof(bitzero));
	memset(bit, 0, sizeof(bit));
	int val, pos;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		if (val == 0) {
			updatezero(i, 1);
		}
		else if (val < 0)
			update(i, 1);
	}

	while(k--) {
		char ch;
		scanf(" %c", &ch);
		if (ch == 'C') {
			scanf("%d %d", &pos, &val);
			if (val == 0) {
				if (queryzero(pos, pos) == 0) {
					updatezero(pos, 1);
					update(pos, -query(pos, pos));
				}
			} else {
				if (queryzero(pos, pos) == 1) {
					updatezero(pos, -1);
				}
				if (query(pos, pos) == 1 && (val > 0))
					update(pos, -1);
				else if (query(pos, pos) == 0 && val < 0)
					update(pos, 1); 
			}
		} else if (ch == 'P') {
			int l, r;
			scanf("%d %d", &l, &r);
			if (queryzero(l, r) > 0)
				printf("0");
			else if (query(l, r) & 1)
				printf("-");
			else
				printf("+");
		}
	}
	printf("\n");
}

int main () {
	int n, k;
	while (scanf("%d %d", &n, &k) == 2) {
		solve(n, k);
	}


	return 0;
}