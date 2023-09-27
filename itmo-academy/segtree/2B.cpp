#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Segtree {
    int n; vi v;
    vector<ll> seg;

    Segtree(vi v): v(v) {
        n = v.size();
        seg = vector<ll>(4*n);
        build(1, 0, n-1);
    }

    ll build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    ll update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    ll update(int i, int x) { v[i] = x; return update(i, x, 1, 0, n-1); }

    int lower_bound(int i, ll &sum, int p, int l, int r) {
        if (r < i) return n;
        if (i <= l and seg[p] < sum) {
            sum -= seg[p];
            return n;
        }
        if (l == r) return l;
        int m = (l+r)/2;
        int x = lower_bound(i, sum, 2*p, l, m);
        if (x != n) return x;
        return lower_bound(i, sum, 2*p+1, m+1, r);
    }

    int lower_bound(int i, ll& sum) { return lower_bound(i, sum, 1, 0, n-1); }
};

int main () {
    int n, m; cin >> n >> m;
    vi a(n); for (auto& x : a) cin >> x;

    auto seg = Segtree(a);
    while(m--) {
        int x; cin >> x;
        if (x == 1){
            int i; cin >> i;
            seg.update(i, 1 - seg.v[i]);
        }
        else {
            ll k; cin >> k; k++;
            cout << seg.lower_bound(0, k) << endl;
        }
    }
}