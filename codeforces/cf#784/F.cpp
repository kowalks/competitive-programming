#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, s=0;
    cin >> n;
    vector<int> a,b,c(n);
    for (int i=0; i < n; i++){
        cin >> c[i];
        s += c[i];
    }

    s = s/2;

    a.push_back(0);

    for (int i = 0; i < n && a[i] <= s; i++) {
        a.push_back(a[i] + c[i]);
   
    }
    a.pop_back();
    b.push_back(0);

    for (int i = 0; i < n && b[i] <= s; i++) {
        b.push_back(b[i] + c[n-i-1]);

    }
    b.pop_back();

    // for (int i = 0; i < a.size(); i++)
    //     cout << a[i] << " ";
    // cout << endl;
    // for (int i = 0; i < b.size(); i++)
    //     cout << b[i] << " ";

    int k;
    while(true) {
        if (a.back() == b.back()) {
            cout << a.size() + b.size() -2 << endl;
            return;
        }
        else if (a.back() > b.back())
            a.pop_back();
        else
            b.pop_back();
    }

}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
