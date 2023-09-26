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
    map<int, int> m, p;

    ll s = 0;
    for (auto k : a) s += k;
    if (s % n) {
        cout << "NO" << endl;
        return;
    }

    for (int i=0; i < 50; i++) m[i] = 0;

    // s % n == 0
    int target = (int) (s/n);
        // cout << "s: " << s << endl;
        // cout << "target: " << target << endl;
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

        if (r == d+1) { // power of two
            if (k > target) p[r]++;
            else p[r]--;
        }
        // cout << r << " " << d << endl; 
    }

    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        auto [k, v] = *it;
        if (v != 0) {
            auto vp = p[k];
            if ((vp >= v && v > 0) || (vp <= v && v < 0)) {
                    m[k] -= v;
                    m[k-1] += 2*v;
                    m[0] -= 2*v;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}