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
    int n; cin >> n;
    vi c(n); for (int& cc : c) cin >> cc;
    int k; cin >> k;

    vii o(n); for (int i=0; i < n; i++) o[i] = {c[i], i};
    sort(o.begin(), o.end());

    int mn = 0; int i = 0; int bgt = k;
    for (auto [oo, idx] : o) {
        while (idx < i) continue;

        

        }
    }
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}