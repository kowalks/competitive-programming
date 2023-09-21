#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

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
    vi a(n); for (int& aa : a) cin >> aa;
    vi b(m); for (int& bb : b) cin >> bb;

    int bb = 0; int xx = 0; int aa = 0;
    for (int i=0; i < m; i++)
        bb |= b[i];
    for (int i=0; i < n; i++) {
        xx ^= (a[i] | bb);
        aa ^= a[i];
    }

    cout << min(aa, xx) << " " << max(aa, xx) << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}