#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAX = 100005;

void solve(){
    int n, k, a, b; cin >> n >> k >> a >> b; a--; b--;
    vii d(n);
    for (auto& [x, y] : d) cin >> x >> y;
    
    ll da = LINF; ll db = LINF;
    auto [xa, ya] = d[a];
    auto [xb, yb] = d[b];
    for (int i=0; i < k; i++) {
        auto [x, y] = d[i];

        da = min(da, abs(x-xa) + abs(y-ya));
        db = min(db, abs(x-xb) + abs(y-yb));
        // cout << i << " " << da << " " << db << endl;
    }

    auto dist = min(da + db, abs(xa - xb) + abs(ya - yb));

    cout << dist << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}