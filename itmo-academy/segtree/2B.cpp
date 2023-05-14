#include <bits/stdc++.h>
#define MAXN 100005
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
    return seg[p] = build(2*p,l,m) + build(2*p+1,m+1,r);
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i,x,2*p,l,m) + update(i,x,2*p+1,m+1,r);
}

int find(int i, int p, int l, int r) {
    if (l==r) return l;
    int m = (l+r)/2;
    int s = seg[2*p];
    if (i < s) return find(i,2*p,l,m);
    return find(i-s, 2*p+1, m+1, r);
}


int32_t main () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) cin >> v[i];

    build(1,0,n-1);

    while(m--) {
        int x, y; cin >> x >> y;
        if (x==1) {
            update(y, 1-v[y], 1, 0, n-1);
            v[y] = 1 - v[y];
        } else {
            cout << find(y, 1, 0, n-1) << endl;
        }
            
    }
    
}