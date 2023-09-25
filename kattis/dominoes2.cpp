#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph{
    vector<vi> g;
    vi visit;
    int cnt = 0;

    Graph(int n, int m) {
        g = vector<vi>(n+1);
        visit = vi(n+1, 0);
        while(m--) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
        }
    }

    void dfs(int a) {
        if (visit[a])
            return;

        visit[a] = 1; cnt++;
        for (auto p : g[a])
            dfs(p);
    }
};

void solve() {
    int n, m, l; cin >> n >> m >> l;
    auto graph = Graph(n, m);

    while(l--) {
        int z; cin >> z;
        graph.dfs(z);
    }

    cout << graph.cnt << endl;
}

int32_t main() {
    int t; cin >> t;
    while(t--)
        solve();
}