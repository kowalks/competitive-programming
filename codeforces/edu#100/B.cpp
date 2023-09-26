#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;

int msb(int k) {
    int i = 0;
    while (k >= (1 << i)) i++;
    return 1 << (i-1);
}

void solve() {
    int n; cin >> n;
    int a;

    for (int i = 0; i < n; i++){
        cin >> a;
        cout << msb(a) << " ";
    }
    cout << endl;
}

int32_t main () {
    int t; cin >> t;

    while(t--)
        solve();
}