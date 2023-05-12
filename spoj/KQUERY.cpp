#include<bits/stdc++.h>
#define MAXN 200010

using namespace std;
typedef struct value value;
typedef struct qu qu;

int bit [MAXN];

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

struct value {
	int val, pos;
};

struct qu {
	int i, j, k, pos;
};

bool comp1 (value a, value b) {
	return a.val < b.val;
}

bool comp2 (qu a, qu b) {
	return a.k < b.k;
}

value vet[MAXN];
qu q[MAXN];
int resp[MAXN];

int main () {
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &vet[i].val);
		vet[i].pos = i+1;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &q[i].i, &q[i].j, &q[i].k);
		q[i].pos = i;
	}

	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}

	sort(vet, vet+n, comp1);
	sort(q, q+k, comp2);

	int ptrvet = 0;
	int prevresp = -1;
	for (int ptrk = 0; ptrk < k; ptrk++) {
		while (vet[ptrvet].val <= q[ptrk].k && ptrvet < n) {
			update(vet[ptrvet].pos, -1);
			ptrvet++;
		}
		resp[q[ptrk].pos] = query(q[ptrk].i, q[ptrk].j);
	}

	for (int i = 0; i < k; i++) {
		printf("%d\n", resp[i]);
	}
}