#include <bits/stdc++.h>
#define MAXN 100005
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int v[MAXN];
tuple<ll,ll,ll,ll> seg[4*MAXN]; // segment, pref, suf, sum

tuple<ll,ll,ll,ll> merge(tuple<ll,ll,ll,ll> a, tuple<ll,ll,ll,ll> b) {
    auto [aseg, ap, as, asum] = a;
    auto [bseg, bp, bs, bsum] = b;
    return {max(aseg, max(bseg, as + bp)), max(ap, asum + bp), max(bs, bsum + as), asum + bsum};
}

tuple<ll,ll,ll,ll> build(int p, int l, int r) {
    int val = v[l] > 0 ? v[l] : 0;
    if (l==r) return seg[p] = {val, val, val, v[l]};
    int m = (l+r)/2;
    return seg[p] = merge(build(2*p,l,m), build(2*p+1,m+1,r));
}

// tuple<ll,ll,ll,ll> query(int a, int b, int p, int l, int r) {
//     if (b < l or r < a) return {0,0,0,0};
//     if (a <= l and r <= b) return seg[p];
//     int m = (l+r)/2;
//     return merge(query(a,b,2*p,l,m), query(a,b,2*p+1,m+1,r));
// }

tuple<ll,ll,ll,ll> update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];

    int val = x > 0 ? x : 0;
    if (l == r) return seg[p] = {val, val, val, x};

    int m = (l+r)/2;
    return seg[p] = merge(update(i,x,2*p,l,m), update(i,x,2*p+1,m+1,r));
}

void pt(tuple<ll,ll,ll,ll> t) {
    auto [a,b,c,d] = t;
    cout << "{" << a << ", " << b << ", " << c << ", " << d << "}";
}

void print() {
    for (int i=1; i < 10; i++) {
        cout << "seg[" << i << "] = ";
        pt(seg[i]);
        cout << endl;
    }
}

int32_t main () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) cin >> v[i];

    auto s = build(1,0,n-1);
    cout << get<0>(s) << endl;

    // print();

    while(m--) {
        int i, v; cin >> i >> v;
        s = update(i,v,1,0,n-1);
        cout << get<0>(s) << endl;
    }
}