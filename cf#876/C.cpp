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
    int n; cin >> n;
    vi a(n); for (int i=0; i < n; i++) cin >> a[i];

    if (a[n-1] == 1) {
        cout << "NO" << endl; return;
    }

    cout << "YES" << endl;

    int i = n-1;
    int p = 0;
    while (i >= 0) {
        if (a[i] == 0 and (i == 0 or a[i-1] == 0)) {
            cout << "0 "; i--; continue;
        }

        i--;

        int k = i;
        while (i >= 0 and a[i] == 1){
            i--;
            cout << "0 ";
        }
        cout << k - i << " ";
    }
    cout << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}