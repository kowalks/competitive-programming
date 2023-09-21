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
    int n, k; cin >> n >> k;
    vi a(n); for (int& aa : a) cin >> aa;

    set<int> s(a.begin(), a.end());

    vi b(n); b[0] = a[0];
    for (int i=1; i < n; i++)
        b[i] = max(a[i], b[i-1]);
    
    vi c(n); c[n-1] = a[n-1];
    for (int i=n-2; i >= 0; i--)
        c[i] = max(a[i], c[i+1]);
    
    int l=0; int r=n-1;
    for (int i=1; i <=k; i++) {
        if (s.count(i)==0) {
            cout << 0 << " ";
            continue;
        }

        while(b[l] < i && l < n-1) l++;
        while(c[r] < i && r > 0) r--;
        cout << 2*(r-l+1) << " ";
    }

    cout << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}