#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[MAXN], b[MAXN];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    int s = 0;
    for(int i=1; i < n; i++) {
        int s1 = abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]);
        int s2 = abs(a[i] - b[i-1]) + abs(b[i] - a[i-1]);
        if (s1 < s2)
            s += s1;
        else
            s += s2;
    }

    cout << s << endl;
}

main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}