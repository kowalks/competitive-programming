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
const int MAXN = 100005;

int p[MAXN];
ll seg[4*MAXN];

ll update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i,x,2*p,l,m) + update(i,x,2*p+1,m+1,r);
}

ll query(int a, int b, int p, int l, int r) {
    if (r < a or b < l) return 0LL;
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    return query(a,b,2*p,l,m) + query(a,b,2*p+1,m+1,r);
}

int32_t main () {
    int n; cin >> n;
    for (int i=0; i < n; i++) cin >> p[i];

    for (int i=0; i < n; i++) {
        ll resp = query(p[i],n-1,1,0,n-1);
        update(p[i]-1,1,1,0,n-1);
        cout << resp << " ";
    }
    cout << endl;
}