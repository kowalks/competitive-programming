#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int k, n;
    string s;
    cin >> n >> k;
    vector<int> b(n);
    vector<int> ans(n);

    cin >> s;

    for (int i = 0; i < n; i++)
        b[i] = s[i] - '0';
    
    if (k%2) {
        for (int i = 0; i < n; i++)
        b[i] = 1 - b[i];
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == 0 && k > 0) {
            k--;
            ans[i] += 1;
            b[i] = 1;
        }
    }

    ans[n-1] += k;
    if (k%2)
        b[n-1] = 1 - b[n-1];

    for (int i = 0; i < n; i++)
        cout << b[i];
    cout << endl;
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    
    cout << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}