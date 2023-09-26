#include <bits/stdc++.h>
#define pb push_back
#define int ll

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Graph {
    int n;
    vector<vi> p;
    vi a, visited, s;
    vector<ll> c, ans;

    Graph(int n): n(n) {
        a = vi(n+1, 0); visited = vi(n+1, 0); s = vi(n+1, 0);
        p = vector<vi>(n+1);
        c = vector<ll>(n+1, 0); ans = vector<ll>(n+1, 0);
        for (int i=1; i <= n; i++) cin >> a[i];
        for (int i=1; i < n; i++) {
            int x, y; cin >> x >> y;
            p[x].pb(y);
            p[y].pb(x);
        }
    }

    void clear() {
        visited.assign(n+1, 0);
        s.assign(n+1, 0);
        c.assign(n+1, 0);
        ans.assign(n+1, 0);
    }

    int dfs_bit(int x, ll b, int par) {
        if (visited[x])
            return 0;
        visited[x] = 1ll;
        int s = 1ll;
        for (int v : p[x]) {
            s += dfs_bit(v, b, x);
        }
        if ((a[par]&b) != (a[x]&b))
            c[x] += s*b;

        this->s[x] = s;
        return s;
    }

    int dfs(int x, int par, ll bit) {
        if (visited[x])
            return 0;
        
        visited[x] = 1ll;

        if (x != 1) {
            ans[x] = ans[par] + ((c[x] == 0) ? 0 : (bit*(n-s[x]) - c[x]));
        } else {
            ans[x] = accumulate(c.begin(), c.end(), 0ll);
        }

        int s = 0ll;
        for (int v : p[x]) {
            s += dfs(v, x, bit);
        }
        return s;
    }
};

void solve(){
    int n; cin >> n;
    auto graph = Graph(n);

    auto ans = vector<ll>(n+1ll, 0ll);

    for (int i=0ll; i <= 25ll; i++) {
        int bit = 1<<i;
        graph.clear();
        graph.dfs_bit(1ll, bit, 1ll);
        graph.visited.assign(n+1, 0ll);
        graph.dfs(1ll, 1ll, bit);

        for (int k=0; k < n+1; k++)
            ans[k] += graph.ans[k];
    }

    for (int i=1ll; i < n+1ll; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}