#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAX = 100005;

int v[MAX];
int seg[4*MAX];

int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    return seg[p] = max(build(2*p,l,m), build(2*p+1,m+1,r));
}

int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = max(update(i,x,2*p,l,m), update(i,x,2*p+1,m+1,r));
}

int find(int i, int x, int p, int l, int r) {
    // cout << "find(" << i << ", " << x << ", " << p << ", " << l << ", " << r << ")" << endl;
    if (x > seg[p]) return -1;
    if (r < i) return -1;
    if (l == r) return l;
    
    int m = (l+r)/2;
    int idx = find(i,x,2*p,l,m);
    if (idx > -1) return idx;
    return find(i,x,2*p+1,m+1,r);
}

void print() {
    for (int i=1; i < 10; i++) {
        cout << "seg[" << i << "]=" << seg[i] << endl;
    }
}

int32_t main () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++) cin >> v[i];

    build(1,0,n-1);
    // print();

    while(m--){
        int q; cin >> q;
        if (q == 1) {
            int i, v; cin >> i >> v;
            update(i,v,1,0,n-1);
        } else if (q == 2) {
            int x, l; cin >> x >> l;
            cout << find(l,x,1,0,n-1) << endl;
        }
    }
}