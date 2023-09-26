#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    for (int i=0; i < n; i++) {
        while(i < n && a[i] == 'W')
            i++;
        if (i == n) break;
        int k = i;

        while(i < n && a[i] == a[k])
            i++;
        if (i == n || a[i] == 'W') {
            cout << "NO" << endl;
            return;
        }

        while(a[i] != 'W' && i < n)
            i++;
    }
    cout << "YES" << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
