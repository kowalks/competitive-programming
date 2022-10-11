#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n+1);
    x[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    
    int cap = 0;
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        // capital em c, ult pos em i-1
        // a capital, b conquista
        cost += b*(x[i] - x[cap]);
        if (i < n && a <= b*(n-i)) {
            cost += a*(x[i] - x[cap]);
            cap = i;
        }
    }
    
    cout << cost << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}