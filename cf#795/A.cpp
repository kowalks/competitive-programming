#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;


void solve() {
    int n; cin >> n;
    int a; int cnt=0, cnt2=0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a&1) cnt++;
        else cnt2++;
    }

    cout << min(cnt,cnt2) << endl;
}

int32_t main () {
    int t; cin >> t;

    while(t--)
        solve();
}