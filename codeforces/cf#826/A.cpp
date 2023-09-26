#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    string a, b;
    cin >> a;
    cin >> b;
    
    int na = a.length();
    int nb = b.length();

    if (a[na-1] > b[nb-1])
        cout << "<" << endl;
    else if (a[na-1] < b[nb-1])
        cout << ">" << endl;
    else if (na > nb) {
        if (a[na-1] == 'S')
            cout << "<" << endl;
        else cout << ">" << endl;
    }
    else if (na < nb) {
        if (a[na-1] == 'S')
            cout << ">" << endl;
        else cout << "<" << endl;
    }
    else cout << "=" << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}