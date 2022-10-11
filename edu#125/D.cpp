#include<bits/stdc++.h>
#define int long long
#define INF 1e9

using namespace std;

int32_t main () {
    int n, m, C, cc, dd, hh;
    cin >> n >> C;
    vector<int> c(n), r(n);
    for (int i=0; i<n; i++){
        cin >> c[i] >> dd >> hh;
        r[i] = dd * hh;
    }
    cin >> m;
    for (int i=0; i<m;  i++) {
        int dd, hh;
        cin >> dd >> hh;
        int rr = dd*hh;
        int mn = INF;
        
        for (int j=0;j<n;j++) {
            int cc = c[j]*(rr/r[j]) + 1);
            mn = min(mn, cc);
        }

        if (mn > C) cout << -1 << endl;
        else cout << mn << endl;
    }
}