#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;

void solve() {
    int a,b,c; cin >> a >> b >> c;

    int enh = (a + b + c)/9;

    if ((a + b + c) % 9 == 0 && a >= enh && b >= enh && c >= enh) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main () {
    int t; cin >> t;

    while(t--)
        solve();
}