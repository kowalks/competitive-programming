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
    int n, k, x; cin >> n >> k >> x;  // MEX = k,  ai <= x

    if (k > x+1) {
        cout << -1 << endl;
        return;
    }

    if (n < k) {
        cout << -1 << endl;
        return;
    }

    int s = ((k-1)*k)/2;
    s += (n-k)* ((x == k) ? (k-1) : x);
    cout << s << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}