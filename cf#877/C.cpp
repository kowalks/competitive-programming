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
    vi a(n);
    for (int i=0; i < n; i++) {
        if (i < n/2) a[i] = 2*i + 1;
        else a[i] = 2*(i - n/2);
    }

    for (int i=0; i < n; i++) {
        int base = a[i] * m;
        for (int j = 1; j <= m; j++)
            cout << base + j << " ";
        cout << endl;
    }
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}