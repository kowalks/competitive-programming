#include<bits/stdc++.h> 

using namespace std;
typedef vector<int> vi;

struct Segtree {
    int n; vi v;
    vi seg;

    Segtree(vi v): v(v) {
        int n = v.size();
        seg = vi(4*n);
        build(1, 0, n-1);
    }

    int build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
    }

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = max(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
    }

    int get_left(int a, int b, int val, int p, int l, int r) {
        if (b < l or r < a or seg[p] < val) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int x = get_left(a, b, val, 2*p, l, m);
        if (x != -1) return x;
        return get_left(a, b, val, 2*p+1, m+1, r);
    }
};

int main () {
    int n, m; cin >> n >> m;
    vi a(n); for (auto& x : a) cin >> x;

    auto seg = Segtree(a);
    while(m--) {
        int x; cin >> x;
        if (x == 1){
            int i, v; cin >> i >> v;
            seg.update(i, v, 1, 0, n-1);
        }
        else {
            int x, l; cin >> x >> l;
            cout << seg.get_left(l, n-1, x, 1, 0, n-1) << endl;
        }
    }
}