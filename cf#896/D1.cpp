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
    vi a(n); for (auto& k : a) cin >> k;
    map<int, int> m;

    ll s = 0;
    for (auto k : a) s += k;
    if (s % n) {
        cout << "NO" << endl;
        return;
    }

    // s % n == 0
    int target = (int) (s/n);
    for (auto k : a) {
        int dif = k-target;
        dif = max(dif, -dif);
        // cout << "dif: " << dif << " ";

        if (dif == 0) continue;

        int d=0;
        while (dif%2 == 0) {
            dif >>= 1;
            d++;
        }

        dif++;
        if ((dif&-dif) != dif) {
            cout << "NO" << endl;
            return;
        }

        int r = -1;
        while (dif > 0) {
            dif /= 2;
            r++;
        }
        r += d;

        if (k > target) {
            m[r]++;
            m[d]--;
        } else {
            m[r]--;
            m[d]++;
        }
        // cout << r << " " << d << endl; 
    }

    for (auto [k, v] : m) {
        if (v != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}