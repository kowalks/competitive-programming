#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    string s;
    cin >> s;

    string resp = "NO";
    for (int i=1; i < s.length()/2; i++)
        if (s[i] != s[0])
            resp = "YES";
    cout << resp << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}