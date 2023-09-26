#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAX = 100005;

void solve(){
    int n, m; cin >> n >> m;
    if (m==1) {
        cout << 0 << endl;
        for (int i=0; i < n; i++) cout << 0 << endl;
        return;
    }

    if (m > n) {
        cout << n + 1 << endl;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++)
                cout << (m-i+j) % m << " ";
            cout << endl;
        } 
        return;
    }

    cout << m << endl;
    for (int i=0; i < m-1; i++) {
        for (int j=0; j < m; j++)
            cout << (m-i+j) % m << " ";
        cout << endl;
    }

    for (int i=m-1; i < n; i++) {
        for (int j=0; j < m; j++) cout << j << " ";
        cout << endl;
    }
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}