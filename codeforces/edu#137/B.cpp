#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    cout << 1 << " ";
    for (int i=n; i>1; i--)
        cout << i << " ";
    cout << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}