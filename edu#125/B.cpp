#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int a=0, s=0;
    while(n--) {
        if (a+x <= b)
            a += x;
        else
            a -= y;
        s += a;
    }
    cout << s << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}