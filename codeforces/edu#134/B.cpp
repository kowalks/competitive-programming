#include<bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

void solve() {
    int n, m, sx, sy, d;

    cin >> n >> m >> sx >> sy >> d;


    if (sx - d <= 1 && sx + d >= n) {
        cout << -1 << endl;
        return;
    } else if (sy - d <= 1 && sy + d >= m) {
        cout << -1 << endl;
        return;
    } else if (sy - d <= 1 && sx - d <= 1) {
        cout << -1 << endl;
        return;
    } else if (sx + d >= n && sy + d >= m) {
        cout << -1 << endl;
        return;
    }

    cout << n + m - 2 << endl; 
}

int32_t main (){
    int t;
    cin >> t;
    while(t--)
        solve();
    // solve()
}