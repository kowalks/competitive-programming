#include<bits/stdc++.h>
#define MAXN 500005
#define INF 10000000
#define int long long
using namespace std;

int bit[MAXN];

void updt(int pos, int value) {
    while(pos < MAXN) {
        bit[pos] = max(bit[pos], value);
        pos += pos&-pos;
    }
}

int query(int pos) {
    int resp = -INF;
    while(pos > 0) {
        resp = max(resp, bit[pos]);
        pos -= pos&-pos;
    }
    return resp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pref(n+1), ord(n+1), dp(n+1);
    pref[0] = 0;

    {
        vector<pair<int,int> > aux(n);
        for (int i = 1; i <= n; i++){
            pref[i] = pref[i-1] + a[i];
            aux[i-1] = {pref[i], -i};
        }
        sort(aux.begin(), aux.end());
        for (int i = 0; i < n; i++)
            ord[-aux[i].second] = i+1;
    }
    
    {
        for (int i=1; i<=n; i++) {
            bit[i]=-INF;
        }

        for (int i=1; i <=n; i++) {
            // 1 long segment
            dp[i] = dp[i-1] +((a[i] < 0) ? -1 : (a[i] > 0) ? 1 : 0);
            dp[i] = max(dp[i], query(ord[i]) + i);
            if (pref[i] > 0) dp[i] = i;
            // cout << "i = " << i << " ord[i] " << ord[i] << "  dp[i] " << dp[i] << endl;
            updt(ord[i], dp[i]-i);
        }
    }

    cout << dp[n] << endl;
    
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}