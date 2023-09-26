#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];

    for (int i=2; i < n; i++) {
        if (abs(a[i] - a[i%2])%2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
