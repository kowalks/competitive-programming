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
    int n, k; cin >> n >> k;

    int resp = 0;

    for (int i=1; i < n; i++) {
        int ceil1 = (i-1)/k + 1;
        int ceil2 = (n-i-1)/k + 1;
        resp = max(resp, ceil1 + ceil2);
        // cout << ceil1 + ceil2 << " ";
    }
    resp = max(resp, (n-1)/k + 1);
    // cout << endl << resp << endl;
    cout << resp << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}