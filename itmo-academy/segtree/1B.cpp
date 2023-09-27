#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

struct Segtree {
    int n; vi v;
    vector<ll> seg;

    Segtree(vi v): v(v) {
        n = v.size();
        seg = vector<ll>(4*n, INF);
        build(1, 0, n-1);
    }

    ll build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
    }

    ll query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return INF;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
    }

    ll query(int a, int b) { return query(a, b, 1, 0, n-1); }

    ll update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
    }

    ll update(int i, int x) { return update(i, x, 1, 0, n-1); }
};

int main () {
    int n, m; cin >> n >> m;
    vi a(n); for (auto& x : a) cin >> x;

    auto seg = Segtree(a);
    while(m--) {
        int x; cin >> x;
        if (x == 1) {
            int i, v; cin >> i >> v;
            seg.update(i, v);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r-1) << endl;
        }
    }
}