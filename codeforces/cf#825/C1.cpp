#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n);
    dp[0] = 1;
    for (int i=1; i < n; i++)
        dp[i] = min(dp[i-1] + 1, a[i]);

    int cnt = 0;
    for (int i=0; i < n; i++)
        cnt += dp[i];

    // for (int i=0; i < n; i++)
    //     cout << dp[i] << " ";
    cout << cnt << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}