#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<pll> vpll;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAX = 100005;

vi p, r;
vi sz, mn, mx; 

void init(int n) {
    p = vi(n+1); 
    r = vi(n+1, 0);
    iota(p.begin(), p.end(), 0);

    sz = vi(n+1, 1);
    mn = vi(n+1); iota(mn.begin(), mn.end(), 0);
    mx = vi(n+1); iota(mx.begin(), mx.end(), 0);
}

int get(int a) {
    if (p[a] == a)
        return a;
    return p[a] = get(p[a]);
}

void une(int a, int b) {
    a = get(a); b = get(b);
    if (a == b)
        return;
    if (r[a] == r[b])
        r[a]++;
    if (r[a] < r[b])
        swap(a, b);
    p[b] = a;

    sz[a] += sz[b];
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
}

void solve(){
    string s; cin >> s;

    if (s == "union") {
        int u, v; cin >> u >> v;
        une(u, v); return;
    } else if (s == "get") {
        int a; cin >> a;
        a = get(a);
        cout << mn[a] << " " << mx[a] << " " << sz[a] << endl;
        return;
    }
}

int32_t main () { _
    int n, q; cin >> n >> q;
    init(n);

    while(q--)
        solve();
}