#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

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

vi p; vi s;

void init(int n) {
    p = vi(n+1);
    s = vi(n+1);
    for (int i=1; i <= n; i++) {
        p[i] = i;
        s[i] = 0;
    }
}

int get(int a) {
    if (p[a] == a)
        return a;
    return p[a] = get(p[a]);
}

void une(int a, int b) {
    a = get(a);
    b = get(b);
    if (s[a] == s[b])
        s[a]++;
    if (s[a] > s[b])
        swap(a,b);
    p[a] = b;
}

void solve(){
    string op; cin >> op;
    int u, v; cin >> u >> v;

    if (op == "union")
        une(u, v);
    else if (op == "get") {
        if (get(u) == get(v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int32_t main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    init(n);

    while(q--)
        solve();
}