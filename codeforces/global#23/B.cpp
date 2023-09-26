#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];

    bool inv = false;
    for (int i=1; i < n; i++)
        if (a[i] < a[i-1])
            inv = true;
    
    if (inv) {
        int sum = 0;
        for (int i=0; i < n; i++)
            sum += a[i];

        int l = sum;
        int r = 0;
        int resp = max(l,r);
        for (int i=n-1; i >= 0; i--) {
            if (a[i] == 0)
                r++;
            else l--;
            resp = min(resp, max(l,r));
        }
        cout << resp << endl;

    } else {
        cout << 0 << endl;
    }
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}