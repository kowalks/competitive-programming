#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef vector<long long> vi;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for (auto& aa : a) cin >> aa;
    for (auto& bb : b) cin >> bb;

    ll sa = 0, sb = 0;
    ll ma = a[0], mb = b[0];
    for (int i=0; i < n; i++) {
        sa += a[i]; sb += b[i];
        ma = min(ma, a[i]); mb = min(mb, b[i]);
    }

    cout << min(n*ma + sb, n*mb + sa) << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}