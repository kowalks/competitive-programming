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

    int negatives = 0;
    for (int i=0; i < n; i++) if (a[i] < 0) negatives++;

    if (negatives == 0) {
        int g = 0;
        for (int i=0; i < n; i++) g = max(g, a[i]);
        cout << g << endl;
    }
    else {
        int g = 0;
        for (int i=0; i < n; i++) g = min(g, a[i]);
        cout << g << endl;
    }
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}