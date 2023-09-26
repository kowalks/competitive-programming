#include <bits/stdc++.h>

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

#define P 998244353ll

ll mult(ll a, ll b) { return (a*b) % P; }

void solve(){
    string s; cin >> s;
    char p = '2';
    ll ans = 1; ll cnt = 1;
    ll n = 0;
    for (auto c : s) {
        if (c != p) {
            n++;
            p = c;
            ans = mult(ans, cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }

    ans = mult(ans, cnt);

    for (int i=1; i <= s.length() - n; i++)
        ans = mult(ans, i);
    
    cout << s.length() - n << " " << ans << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}