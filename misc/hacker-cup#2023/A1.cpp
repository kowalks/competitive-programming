#include<bits/stdc++.h>

using namespace std;

void solve(int t) {
    int s, d, k; cin >> s >> d >> k;
    int b = 2*(s+d);
    int p = s + 2*d;
    cout << "Case #" << t << ": ";
    if (p >= k && b >= k+1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main () {
    int t; cin >> t;
    for (int i=1; i<=t; i++)
        solve(i);
}