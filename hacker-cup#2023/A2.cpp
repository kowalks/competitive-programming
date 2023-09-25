#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve() {
    ll a, b, c; cin >> a >> b >> c; // a: single, b: double

    ll v1 = c/b - 1;
    c -= a;
    if (b <= a || c < 0)
        return max(v1, 0ll);
    
    ll y = c/b;
    ll x = c/a;
    return max(v1, 2*y + 1);
}

int32_t main () {
    int t; cin >> t;
    for (int i=1; i<=t; i++)
        cout << "Case #" << i << ": " << solve() << endl;
        
}