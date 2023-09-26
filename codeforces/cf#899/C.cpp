#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAX = 100005;

void solve(){
    int n; cin >> n;
    vi a(n); for (auto& e : a) cin >> e;
    
    ll s_pos = 0;
    for (auto aa : a) if (aa > 0) s_pos += aa;

    if (s_pos == 0) {
        cout << s_pos << endl;
        return;
    }

    int ptr = 0;
    for (ptr=0; ptr < n; ptr++)
        if (a[ptr] >= 0) break;
    
    if (ptr%2 == 0 || a[1] <= 0) {
        cout << s_pos << endl;
        return;
    }

    if (a[0] + a[1] >= 0)
        cout << s_pos + a[0] << endl;
    else
        cout << s_pos - a[1] << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}