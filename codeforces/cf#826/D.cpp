#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int check(vi& a, int i, int j, int val){ 
    // cout << "check(i=" << i << ", j=" << j << ", val=" << val << ")\n";

    int m = (i+j)/2;
    int s = (j-i)/2;
    if (j == i+1) {
        if (a[i] == val)
            return 0;
        else return -1;
    }

    if (a[i] < val + s) {
        int a1 = check(a, i, m, val);
        int a2 = check(a, m, j, val+s);
        if (a1 == -1 || a2 == -1)
            return -1;
        else return a1+a2;
    }
    else {
        int a1 = check(a, i, m, val+s);
        int a2 = check(a, m, j, val);
        if (a1 == -1 || a2 == -1)
            return -1;
        else return a1 + a2 + 1;
    }
}

void solve(){
    int n; cin >> n;
    vi a(n);
    
    for (int i=0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    cout << check(a, 0, n, 0) << endl; 
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}