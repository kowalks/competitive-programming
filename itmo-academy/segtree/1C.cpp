#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

struct Segtree {
    int n; vi v;
    vector<ii> seg;     // {min, #min}

    Segtree(vi v): v(v) {
        n = v.size();
        seg = vector<ii>(4*n, {INF, 1});
        build(1, 0, n-1);
    }

    ii comb(ii a, ii b) {
        if (a.first == b.first) 
            return {a.first, a.second + b.second};
        if (a.first < b.first)
            return a;
        return b; 
    }

    ii build(int p, int l, int r) {
        if (l == r) return seg[p] = {v[l], 1};
        int m = (l+r)/2;
        return seg[p] = comb(build(2*p, l, m), build(2*p+1, m+1, r));
    }

    ii query(int a, int b, int p, int l, int r) {
        if (r < a or b < l) return {INF, 1};
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return comb(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
    }

    ii query(int a, int b) { return query(a, b, 1, 0, n-1); }

    ii update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = {x, 1};
        int m = (l+r)/2;
        return seg[p] = comb(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
    }

    ii update(int i, int x) { return update(i, x, 1, 0, n-1); }
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
            auto [min, cnt] = seg.query(l, r-1);
            cout << min << " " << cnt << endl;
        }
    }
}