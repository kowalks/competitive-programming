#include<bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, ans = 0;
    cin >> x >> y;

    if (x == 0 && y == 0) {
        ans=0;
    } else if (x == 0 || y == 0) {
        ans=1;
    } else {
        int sq = sqrt(x*x + y*y);
        if (sq*sq == x*x + y*y) {
            ans=1;
        } else {
            ans=2;
        }
    }

    cout << ans << endl;
}

int main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}