#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Segtree {
    int n; vi seg, v;

    Segtree(int n): n(n) {
        seg = vi(4*n);
        v = vi(n);
    }

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    int update(int i, int x) { v[i] = x; return update(i, x, 1, 0, n-1); }

    int query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    int query(int a, int b) { return query(a, b, 1, 0, n-1); }
};

int main () {
    int n; cin >> n;
    vi a(2*n); for (int& x : a) cin >> x;
    for (int& x : a) x--;

    auto seg = Segtree(2*n);

    vi l(n);
    for (int i=2*n-1 ; i>=0; i--)
        l[a[i]] = i;

    vi ans(n);
    for (int i=0; i < 2*n; i++) {
        if (l[a[i]] != i) { // right
            ans[a[i]] = seg.query(l[a[i]], i);
            seg.update(l[a[i]], 1);
        }
    }

    for (auto a : ans) cout << a << " "; cout << endl;
}