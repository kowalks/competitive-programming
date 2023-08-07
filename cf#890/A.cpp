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
    vector<int> v(n);

    int m = -INF;
    for (int i=0; i < n; i++) {
        cin >> v[i];
    }

    int i = v.size()-1;
    while (i > 0 && v[i-1] <= v[i]) i--;

    if (i == 0){
        cout << 0 << endl;
        return;
    }

    for (int k=0; k <= i; k++)
        m = max(m, v[k]);

    cout << m << endl;


}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}