#include <bits/stdc++.h>
#define MAXN 100005
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int v[MAXN];
ll seg[4*MAXN];

ll build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r) {
    // cout << "query(" << a << ", " << b << ", " << p << ", " << l << ", " << r << ")" << endl;
    if (b < l or r < a) return 0;
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

ll update(int i, int x, int p, int l, int r) {
    // cout << "update(" << i << ", " << x << ", " << p << ", " << l << ", " << r << ")" << endl;
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
}

void print(){
    for (int i=1; i < 10; i++)
        cout << "seg[" << i << "] = " << seg[i] << endl;
}

int32_t main () {
    int n, m; cin >> n >> m;
    for (int i=0; i < n; i++)
        cin >> v[i];

    build(1, 0, n-1);
    // print();

    while (m--){
        int q, x, y; cin >> q >> x >> y;
        
        if (q == 1) { // update
            update(x, y, 1, 0, n-1);
            // print();
        } else if (q == 2) { // query
            y--;
            ll ans = query(x, y, 1, 0, n-1);
            cout << ans << endl;
        }
    }

}