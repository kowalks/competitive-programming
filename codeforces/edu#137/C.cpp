#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    vector<int> a(n), c(n);
    char in;
    int sum = 0;
    for (int i=0; i < n; i++) {
        cin >> in;
        if (in == '1')
            c[i] = 1;
        else 
            c[i] = 0;
    }

    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (c[i])
            sum += a[i];
    }

    int i = 0;
    while (i < n && c[i] == 1) i++; 

    while (i < n) {
        // a[i] = 0
        while(i < n && c[i] == 0) i++;

        // a[i] = 1
        // a[i-1] = 0
        int val = a[i-1];
        sum += val;
        while (i < n && c[i] == 1) {
            if (a[i] < val)
                val = a[i];
            i++;
        }

        sum -= val;
    }

    cout << sum << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}