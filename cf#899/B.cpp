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
    int n; cin >> n;
    vector<set<int>> s(n);
    set<int> un;
    for (int i=0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int ss; cin >> ss;
            s[i].insert(ss);
            un.insert(ss);
        }
    }

    int max_size = 0;
    for (int el=1; el <= 50; el++) {
        set<int> total;
        total.clear();
        for (int i=0; i < n; i++) {
            if (!s[i].count(el))
                for (auto ss : s[i])
                    total.insert(ss);
        }
        if (total.size() < un.size())
            max_size = max((int) total.size(), max_size);
    }

    cout << max_size << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}