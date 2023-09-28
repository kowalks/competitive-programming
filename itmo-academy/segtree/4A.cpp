#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Segtree {
    int n; vi v;
    vector<ll> seg;

    Segtree(vi v): v(v) {
        n = v.size();
        seg.resize(4*n);
        build(1, 0, n-1);
    }

    ll build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l] * ((l%2) ? 1 : -1);
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    ll update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x * ((i%2) ? 1 : -1);
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    ll update(int i, int x) { return update(i, x, 1, 0, n-1); }

    ll query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    ll query(int a, int b) { return query(a, b, 1, 0, n-1)*((a%2) ? 1 : -1); }
};

int main () {
    int n; cin >> n;
    vi a(n); for (auto& x : a) cin >> x;

    auto seg = Segtree(a);
    int m; cin >> m;
    while(m--) {
        int x; cin >> x;
        if (x == 1) {
            int l, r; cin >> l >> r;
            cout << seg.query(l-1, r-1) << endl;
        } else if (x == 0) {
            int i, j; cin >> i >> j; i--;
            seg.update(i, j);
        }
    }
}
