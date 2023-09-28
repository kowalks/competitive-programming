#include "template.h"

struct Segtree {
    int n; vi v;
    vector<ll> seg;

    Segtree(vi v): v(v){
        n = v.size();
        seg = vector<ll>(4*n, 0);
        build(1, 0, n-1);
    };

    ll build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    ll query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    ll query(int a, int b) { return query(a, b, 1, 0, n-1); }

    ll update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    ll update(int i, int x) { return update(i, x, 1, 0, n-1); }

    // for sum segtree in non-negative terms, computes largest j such that 
    // v[i] + ... + v[j-1] < sum
    ll lower_bound(int i, ll& val, int p, int l, int r) {
        if (r < i) return n;
        if (i <= l and seg[p] < val) {
            val -= seg[p];
            return n;
        }
        if (l == r) return l;
        int m = (l+r)/2;
        int x = lower_bound(i, val, 2*p, l, m);
        if (x != n) return x;
        return lower_bound(i, val, 2*p+1, m+1, r);
    }

    // for max segtree, computes lowest i in [a,b] st. v[i] >= val
    int get_left(int a, int b, int val, int p, int l, int r) {
        if (b < l or r < a or seg[p] < val) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int x = get_left(a, b, val, 2*p, l, m);
        if (x != -1) return x;
        return get_left(a, b, val, 2*p+1, m+1, r);
    }

    // for max segtree, computes highest i in [a, b] st. v[i] >= val
    int get_right(int a, int b, int val, int p, int l, int r) {
        if (b < l or r < a or seg[p] < val) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int x = get_right(a, b, val, 2*p+1, m+1, r);
        if (x != -1) return x;
        return get_right(a, b, val, 2*p, l, m);
    }
};