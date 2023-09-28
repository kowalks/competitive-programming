#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n, int m): n(n), m(m) {
        g.resize(n);
        while(m--) {
            int x, y; cin >> x >> y;
            g[--x].push_back(--y);
        }
    }

    vi toposort() {
        vi ts, vis(n, 0);

        bool dag = true;
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for (auto v : g[u])
                if (vis[v] == 1) dag = false;
                else if (!vis[v]) dfs(v);
            ts.push_back(u); vis[u] = 2;
        };

        for (int i=0; i < n; i++)
            if (!vis[i]) dfs(i);

        if (!dag) ts.clear();
        reverse(ts.begin(), ts.end());
        return ts;
    }
};

int main () {
    int n, m; cin >> n >> m;
    auto g = Graph(n, m);

    auto ts = g.toposort();
    if (ts.size() == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int t : ts)
        cout << t+1 << endl;
}