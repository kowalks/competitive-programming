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

// faz update no intervalo [l, r] em +val
void update (int l, int r, int val) {
	update(l, val);
	update(r+1, -val);
}

int main () {
	update (1, 3, 2);
	update (2, 3, 4);
	update (1, 2, 8);

	int i = 3;
	printf("valor na posicao %d: %d \n", i, query(i));
}