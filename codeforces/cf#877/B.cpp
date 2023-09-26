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
    vi a(n); for(int i=0; i<n; i++) cin >> a[i];

    int p1, p2, pn;
    for (int i=0; i < n; i++) {
        if (a[i] == 1) p1 = i+1;
        if (a[i] == 2) p2 = i+1;
        if (a[i] == n) pn = i+1;
    }

    if (p1 > p2) swap(p1, p2);

    if (p2 > pn and pn > p1) cout << p1 << " " << p2 << endl;
    else if (pn > p2) cout << p2 << " " << pn << endl;
    else if (p1 > pn) cout << pn << " " << p1 << endl;
}

// p1 pn p2
// p2 pn p1

// p1 pn p2
// p1 p2 pn
// pn p1 p2

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}