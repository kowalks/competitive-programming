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
    vi a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    

    if (n%2 == 0) {
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
        return;
    }

    cout << 4 << endl;
    cout << 1 << " " << n << endl;
    cout << 1 << " " << n-1 << endl;
    cout << n-1 << " " << n << endl;
    cout << n-1 << " " << n << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}