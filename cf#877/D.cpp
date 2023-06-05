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

void solve(int n, vi a){
    vi b(n, 0);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
        b[i] = b[i-1] + a[i];
    
    // for (int i = 0; i < n; i++) cout << (a[i] == 1 ? "(" : ")"); cout << endl;
    // for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;

    if (b[n-1] % 2 == 1) {
        cout << "NO" << endl;
        return;
    } else if (b[n-1] == 0) {
        cout << "YES" << endl;
        return;
    }

    vi c(n, 0);
    int l = INF, r = -INF;
    for (int i = 1; i < n; i++)
        if (a[i] == a[i-1] and a[i] == 1) {
            c[i] = 1;
            l = min(l, i);
        }
        else if (a[i] == a[i-1] and a[i] == -1) {
            c[i] = -1;
            r = max(r, i);
        }

    // cout << "l=" << l << " r=" << r << endl;

    if (l != INF and r != -INF and l < r) {
        int mr = INF, ml = INF;
        for (int i=r; i < n; i++) {
            mr = min(b[i], mr);
        }
        for (int i=0; i < l; i++) {
            ml = min(b[i], ml);
        }

        if (mr == b[n-1] and ml >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (l != INF and b[n-1] <= 0) {
        int ml = INF, mr = INF;
        for (int i=0; i < l; i++) {
            ml = min(b[i], ml);
        }
        for (int i=l; i < n; i++) {
            mr = min(b[i], mr);
        }
        if (mr == b[n-1] and ml >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (r != -INF and b[n-1] >= 0) {
        int ml = INF, mr = INF;
        for (int i=0; i < r; i++) {
            ml = min(b[i], ml);
        }
        for (int i=r; i < n; i++) {
            mr = min(b[i], mr);
        }
        if (mr == b[n-1] and ml >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int32_t main () {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi a(n, 0);
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            a[i] = 1;
        else
            a[i] = -1;
    
    while (q--) {
        int i; cin >> i;
        i--;
        // cout << "i=" << i << endl;
        a[i] = -a[i];
        solve(n, a);
        // a[q] = -a[q];
    }
}