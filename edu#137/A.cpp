#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    int a;
    int cnt = 10;
    while (n--) {
        cin >> a;
        cnt--;
    }

    if (cnt == 0)
        cout << 0;
    else if (cnt == 1)
        cout << 0;
    else
        cout << (cnt*(cnt-1))/2 * 6;
    cout << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}