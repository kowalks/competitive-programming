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
int seg[4*MAXN];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r) {
    if (b < l or r < a) return INF;
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return min(query(a,b,2*p,l,m), query(a,b,2*p+1,m+1,r));
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l==r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = min(update(i,x,2*p,l,m), update(i,x,2*p+1,m+1,r));
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
            cout << query(x, y-1, 1, 0, n-1) << endl;
        }
    }
}