#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll, ll> info;  // seg, pre, suf, sum
typedef vector<int> vi;

info operator+(info a, info b) {
    auto [aseg, apre, asuf, asum] = a;
    auto [bseg, bpre, bsuf, bsum] = b;
    return {max(aseg, max(bseg, asuf + bpre)), max(apre, asum + bpre), max(bsuf, bsum + asuf), asum + bsum};            
}

struct Segtree {
    int n; vi v;
    vector<info> seg;

    Segtree(vi v): v(v) {
        n = v.size();
        seg = vector<info>(4*n);
        build(1, 0, n-1);
    }

    info build(int p, int l, int r) {
        if (l == r) {
            int x = max(v[l], 0);
            return seg[p] = {x, x, x, v[l]};
        }
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    info update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) {
            int k = max(x, 0);
            return seg[p] = {k, k, k, x};
        }
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    info update(int i, int x) { return update(i, x, 1, 0, n-1); }

    ll query() { return get<0>(seg[1]); }
};

int main () {
    int n, m; cin >> n >> m;
    vi a(n); for (auto& x : a) cin >> x;

    auto segtree = Segtree(a);
    cout << segtree.query() << endl;

    while (m--) {
        int i, v; cin >> i >> v;
        segtree.update(i, v);
        cout << segtree.query() << endl;
    }
}