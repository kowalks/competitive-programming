#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    if (n == 2)
        cout << "2 1\n";
    else if (n == 3)
        cout << "-1\n";
    else {
        if (n%2 == 0) {
            for (int i=n; i > 0; i--)
                cout << i << " ";
            cout << endl;
        } else {
            cout << n << " " << n-1 << " ";
            for (int i=1; i <= n-2; i++)
                cout << i << " ";
            cout << endl;
        }
    }
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}