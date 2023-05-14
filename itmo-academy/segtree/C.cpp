#include <bits/stdc++.h>
#define MAXN 100005
#define INF 1000000009
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int v[MAXN];
ii seg[4*MAXN];  // {min, #min}

ii combine(ii a, ii b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return {a.first, a.second + b.second};
}

ii build(int p, int l, int r) {
    if (l==r) return seg[p] = {v[l], 1};
    int m = (l+r)/2;
    return seg[p] = combine(build(2*p,l,m), build(2*p+1,m+1,r));
}

ii query(int a, int b, int p, int l, int r) {
    if (b < l or r < a) return {INF, 0};
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return combine(query(a,b,2*p,l,m), query(a,b,2*p+1,m+1,r));
}

ii update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = {x, 1};
    int m = (l+r)/2;
    return seg[p] = combine(update(i,x,2*p,l,m), update(i,x,2*p+1,m+1,r));
}

int32_t main () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) cin >> v[i];
    
    build(1,0,n-1);
    while (m--) {
        int q,x,y; cin >> q >> x >> y;
        if (q == 1) { //update
            update(x, y, 1, 0, n-1);
        } else { // query
            auto [a,b] = query(x, y-1, 1, 0, n-1);
            cout << a << " " << b << endl;
        }
    }
}