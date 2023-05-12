#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

long long bit[MAXN];

void update (int val, int pos) {
	pos++;
	while (pos < MAXN) {
		bit[pos] += val;
		pos += pos&-pos;
	}
}

long long query (int pos) {
	pos++;
	int val = 0;
	while (pos > 0) {
		val += bit[pos];
		pos -= pos&-pos;
	}
	return val;
}

long long query (int l, int r) {
	return query(r) - query(l-1);
}

struct tree {
	int x, y, val;
};

struct tree tree[MAXN];

bool comp (struct tree a, struct tree b) {
	return a.x < b.x;
}

struct query {
	int xi, xf, yi, yf, sum;
};

bool comp (struct query a, struct query b) {
	return (a.xf < b.xf);
}

struct query query[MAXN];

void solve () {
	int n, r;
	scanf("%d", &n);
	memset(bit, 0, sizeof(bit));
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", tree[i].x, tree[i].y, tree[i].val);
	scanf("%d", &r);
	for (int i = 0 ; i < r; i++)
		scanf("%d %d %d %d", query[i].xi, query[i].yi, query[i].xf, query[i].yf);

	sort(tree, tree+n, comp);
	sort(query, query+r, comp);

	int ptr = 0;
	for(int i = 0; i < n; i++) {
		if (tree[i].x != tree[ptr].x) {

			while (tree[i].x != tree[ptr].x) {
				update(tree[ptr].y, -tree[ptr].val);
				ptr++;
			}
		}
		update(tree[i].y, tree[i].val);
	}

}

int main () {
	int t;
	scanf("%d", &t);
	while(t--) 
		solve();
}