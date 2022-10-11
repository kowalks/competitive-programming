#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    vi a(n);

    int s=0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    
    int resp = 20000;
    for (int i=1; i<=n; i++) {
        if (s%i != 0)
            continue;
        
        int p = s/i;
        int ptr = 0;
        int tick = 0;
        bool should = true;
        while (ptr < n) {
            int sp = 0;
            int cnt = 0;
            while(sp < p && ptr < n) {
                sp += a[ptr++];
                cnt++;
            }
            if (sp != p) {
                should = false;
                break;
            }
            tick = max(tick, cnt);
        }

        if (should)
            resp = min(resp, tick);
    }

    cout << resp << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}