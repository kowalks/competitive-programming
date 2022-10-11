#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int cnt=0;
    for (int i=0; i < n; i++){
        cin >> a[i];
        cnt += a[i];
    }
    cnt = cnt + *max_element(a.begin(), a.end());
    cnt = cnt - *min_element(a.begin(), a.end());
    cnt += n;
    if (cnt <= m)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}