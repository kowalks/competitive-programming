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
    vi a(n); for (auto& aa : a)
        cin >> aa;

    int b = 0;
    for (int aa : a) {
        b++;
        if (b == aa) b++;
    }

    cout << b << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}