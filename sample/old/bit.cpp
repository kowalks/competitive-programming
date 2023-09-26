#include<bits/stdc++.h>
#define MAXN 10

// BIT iniciada com zero e indexada em 1
int bit[MAXN];

// faz update pontual
void update (int pos, int val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

// retorna soma entre [1, pos]
int query (int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= pos&-pos;
	}
	return sum;
}

// retorna soma entre [l, r]
int query (int l, int r) {
	return query(r) - query(l-1);
}

int main () {
	update (1, 7);
	update (2, 9);
	update (3, 1);
	update (4, 2);
	update (5, 0);

	int i = 3, j = 3;
	printf("soma entre [%d, %d]: %d \n", i, j, query(i, j));
}