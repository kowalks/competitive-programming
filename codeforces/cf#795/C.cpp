#include <bits/stdc++.h>
#define MAXN 50
#define int long long 
using namespace std;


void solve() {
    int n,k; cin >> n >> k;
    vector<char> s(n);
    int f=0;
    for (int i=0; i<n; i++){
        cin >> s[i];
        if (s[i] == '1') {
            if (i > 0 && i < n-1)
                f += 11;
            else if (i > 0)
                f += 1;
            else f += 10;
        }
    }

    if (f == 0) {
        cout << f << endl;
        return;
    }

    // for (int i=0; i < n; i++)
    //     cout << "s[" << i << "] = " << s[i] << endl;

    int k1 = 0;
    for (int i=0; i<n;i++) {
        if (s[i] == '1'){
            k1=i;
            break;
        }
    }

    int k2 = n-1;
    for (int i=n-1; i>=0;i--) {
        if (s[i] == '1'){
            k2=i;
            break;
        }
    }
    k2 = n-1 - k2;

    // cout << "f is " << f << endl << "k1 is " << k1 << endl << "k2 is " << k2 << endl;
    
    int p1 = (k1 > 0) ? 1 : 0;
    int p2 = (k2 > 0) ? 10 : 0;

    // cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;

    if (k < min(k1,k2))
        cout << f << endl;
    else if (k >= k1 + k2)
        cout << f - p1 - p2 << endl;
    else if (k >= k1 && k >= k2) {
        if (f-p1 < f-p2)
            cout << f-p1 << endl;
        else cout << f-p2 << endl;
    } else if (k >= k1) {
        cout << f-p1 << endl;
    } else {
        cout << f-p2 << endl;
    }
}

int32_t main () {
    int t; cin >> t;

    while(t--)
        solve();
}