#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1; i <= n; i++)
        cin >> a[i];

    // for (int i=1; i <= n; i++)
    //     cout << "a[" << i << "]=" << a[i] << endl;

    vector<int> resp(n+1);
    for (int i=1; i <= n; i++)
        resp[a[i]] = (i%n) + 1;

    for (int i=1; i <=n; i++)
        cout << resp[i] << " ";
    cout << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}