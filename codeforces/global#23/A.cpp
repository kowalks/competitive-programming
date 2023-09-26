#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n, k; cin >> n >> k;
    int a;
    bool resp = false;
    while (n--) {
        cin >> a;
        if (a == 1)
            resp = true;
    }

    if (resp)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}