#include<bits/stdc++.h>
#define MAXN 10

// BIT iniciada com zero e indexada em 1
int bit1[MAXN], bit2[MAXN];

void update (int* bit, int pos, int val) {
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

int query (int* bit, int pos) {
	int sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= pos&-pos;
	}
	return sum;
}

void update (int l, int r, int val) {
	update(bit1, l, val);
	update(bit1, r+1, -val);
	update(bit2, l, val*(l-1));
	update(bit2, r+1, -val*r);
}

int query (int pos) {
	return pos*query(bit1, pos) - query(bit2, pos);
}

int query (int l, int r) {
	return query(r) - query(l-1);
}

int main () {
	update(1,1,7);
	update(2,2,9);
	update(3,3,1);
	update(4,4,2);
	update(5,5,0);
	update(3,5,1);

	int i = 2, j = 5;
	printf("soma entre [%d, %d]: %d", i, j, query(i, j));
}