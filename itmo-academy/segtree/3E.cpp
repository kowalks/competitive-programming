#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

struct Segtree {
    int n; vi v;
    vector<ll> seg;

    Segtree(int n): n(n) { seg.resize(4*n); }

    ll query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    ll query(int a, int b) { return query(a, b, 1, 0, n-1); }

    ll update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] += x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    ll update(int i, int x) { return update(i, x, 1, 0, n-1); }
};

int main () {
    int n, m; cin >> n >> m;
    auto seg = Segtree(n+1);
    while(m--) {
        int x; cin >> x;
        if (x == 1) {
            int l, r, v; cin >> l >> r >> v;
            seg.update(l, v); seg.update(r, -v);
        } else if (x == 2) {
            int i; cin >> i;
            cout << seg.query(0, i) << endl;
        }
    }
}