#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];
    
    if (n==1) {
        cout << 1 << endl;
        return;
    }

    for (int i=0 ; i < n; i++) {
        if (a[i] != a[0]) goto final;
    }

    cout << 1 << endl;
    return;

    final:
    int i=0, j=1, l=a.size();
    for (int j = 1; j+1 < a.size(); j++) {
        if ((a[i] <= a[j] && a[j] <= a[j+1]) or (a[i] >= a[j] && a[j] >= a[j+1])) {
            l--;
        } else {
            i=j;
        }
    }
    
    cout << l << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}