#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Segtree {
    int n;
    vi seg;

    Segtree(int n): n(n) {
        seg = vi(4*n);
    }

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    int query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <=l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }
};

int main () {
    int n; cin >> n;
    auto seg = Segtree(n);

    for (int i=0; i < n; i++) {
        int p; cin >> p; p--;
        cout << seg.query(p, n-1, 1, 0, n-1) << " ";
        seg.update(p, 1, 1, 0, n-1);
    }
}