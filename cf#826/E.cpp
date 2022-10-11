#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool check(vi& a, int i) {
    if (i == a.size())
        return true;
    else if (i > a.size())
        return false;
    
    if (check(a, a[i] + i + 1))
        return true;
    
    for (int j=i+1; j < a.size(); j++) {
        if (a[j] == j-i)
            if (check(a, j+1)) return true;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];
    
    if (check(a, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}