#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i=2; i < n; i++)
        if (a[i] == a[i-1] && a[i-1] == a[i-2]) {
            cout << a[i] << endl;
            return;
        }
    cout << -1 << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
