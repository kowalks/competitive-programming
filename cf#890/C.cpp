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
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i=0; i < n; i++) cin >> v[i];

    ll m = v[0];
    for (int i=0; i < n; i++) m = max(m, v[i]);

    for (int i=1; i < n; i++) {
        if (v[i-1] <= v[i] and v[i] - v[i-1] < k)
            m = max(m, v[i] - v[i-1] + 1);
    }

    for (int i=v.size()-1; i > 0; i--) {
        cout << ("m = ") << m << endl;
        ll s = 0ll;
        int cnt = 0;
        for (int j = i-1; j >= 0; j--) {
            ll new_size = v[i] + i - j;
            cout << "ns=" << new_size << endl;
            if (new_size > v[j]) {
                s += new_size - v[j];
                if (s <= k) m = max(new_size, m);
                else if (cnt <= v[i] - v[i-1]) {
                    cout << "i=" << i << " j=" << j << endl;
                    s -= new_size;
                    int f = (new_size - v[j]-1)/(i-j-1) + 1;
                    cnt += f;
                    s -= f*(i-j-1);
                    j++;
                } else break;
            } else break;
        }
    }

    cout << m << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}