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
    
    ll s1 = 0;
    ll s2 =  0;
    for (int i=0; i < n; i++) {
        int k; cin >> k;
        s1 += k;
        s2 += (k > 1) ? 1 : 2;
    }

    if (n == 1){
        cout << "NO" << endl;
        return;
    }

    if (s1 < s2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}