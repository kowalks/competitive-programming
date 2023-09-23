#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

using namespace std;

ll w, h, n;

bool fit (ll x) {
    return (x/w) * (x/h) >= n;
}

ll find(ll l, ll r) {  // f(l) = false,  f(r) = true
    if (l == r-1)
        return r;
    
    ll m = (l+r)/2;
    if (fit(m))
        return find(l, m);
    return find(m, r);
}

int32_t main () { _
    cin >> w >> h >> n;

    ll x=1;
    while (!fit(x))
        x <<= 1;

    cout << find(0, x) << endl;
}