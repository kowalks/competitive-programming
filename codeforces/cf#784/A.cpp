#include<bits/stdc++.h>
using namespace std;

void solve() {
    int r;
    cin >> r;
    cout << "Division ";
    if ( r >= 1900)
        cout << "1";
    else if ( r >= 1600)
        cout << "2";
    else if ( r >= 1400)
        cout << "3";
    else
        cout << "4";
    cout << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
