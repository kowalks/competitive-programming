#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Segtree {
    int n;
    vi seg;

    Segtree(int n): n(n+1) {
        seg = vi(4*(n+1));
        build(1, 0, n);
    }

    int build(int p, int l, int r) {
        if (l == r) return seg[p] = p == 1 ? 0 : 1;
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    int update(int i, int x) { return update(i, x, 1, 0, n-1); }

    int lower_bound(int i, int& sum, int p, int l, int r) {
        if (i < l) return -1;
        if (r <= i and seg[p] < sum) {
            sum -= seg[p];
            return -1;
        }
        if (l == r) return l;
        int m = (l+r)/2;
        int x = lower_bound(i, sum, 2*p+1, m+1, r);
        if (x >= 0) return x;
        return lower_bound(i, sum, 2*p, l, m);
    }

    int lower_bound(int sum) { return lower_bound(n-1, sum, 1, 0, n-1); }
};

int main () {
    int n; cin >> n;
    auto seg = Segtree(n);

    vi a(n); for (int& x : a) cin >> x;
    reverse(a.begin(), a.end());

    vi b;
    for (int i=0; i < n; i++) {
        int p = seg.lower_bound(a[i]+1);
        seg.update(p, 0);
        b.push_back(p);
    }

    reverse(b.begin(), b.end());

    for (auto x : b) cout << x << " ";
    cout << endl;
}