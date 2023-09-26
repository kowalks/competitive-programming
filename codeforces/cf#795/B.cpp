#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> s(n), p(n);
    for (int i=0; i < n; i++)
        cin >> s[i];
    
    int bk = 0;
    for (int i=0; i<n; i++) {
        if (i < n-1 && s[i] == s[i+1])
            p[i] = i+1;
        else {
            p[i] = bk;
            bk = i+1;
        }
    }

    for (int i =0; i < n; i++)
        if (p[i] == i) {
            cout << -1 << endl;
            return;
        }
    
    for (int i=0; i < n; i++)
        cout << p[i] + 1 << " ";
    cout << endl;

}

int32_t main () {
    int t; cin >> t;

    while(t--)
        solve();
}