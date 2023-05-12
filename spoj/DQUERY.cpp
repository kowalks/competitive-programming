#include<bits/stdc++.h>
#define MAXN 30004
#define MAXQ 200010
using namespace std;
typedef struct dquery dquery;
typedef struct value value;

int bit[MAXN];

void update (int pos, int val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

int query (int pos) {
	int val = 0;
	while (pos > 0) {
		val += bit[pos];
		pos -= pos&-pos;
	}
	return val;
}

int query (int p, int q) {
	return query(q) - query(p-1);
}

struct dquery {
	int i, j, pos;
};

struct value {
	int val, pos;
};

value a[MAXQ];
value val[MAXQ];
dquery dq[MAXQ];

bool comp (dquery a, dquery b) {
	return a.i < b.i || (a.i == b.i && a.j < b.j);
}

bool comp2 (value a, value b) {
	return a.val < b.val || (a.val == b.val && a.pos < b.pos);
}


int main () {
	int n, q;
	int resp[MAXQ];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].val);
		val[i+1].val = a[i].val;
		a[i].pos = i+1;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &dq[i].i, &dq[i].j);
		dq[i].pos = i;
	}

	sort(dq, dq+q, comp);
	sort(a, a+n, comp2);

	for (int i = 0; i < n; i++) {
		val[a[i].pos].pos = i;
	}

	int ant = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].val != ant)
			update(a[i].pos, 1);
		ant = a[i].val;
	}
	int ptr = 1;
	for (int i = 0; i < q; i++) {
		while (dq[i].i > ptr && ptr <= n) {
			int kk = val[ptr].pos + 1;
			if (kk < n && a[kk].val == val[ptr].val)
				update(a[kk].pos, 1);
			ptr++;
		}
		resp[dq[i].pos] = query(dq[i].i, dq[i].j);
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", resp[i]);
}