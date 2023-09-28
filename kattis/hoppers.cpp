#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int n, m; vector<vi> g;

    Graph(int n, int m): n(n), m(m) {
        g.resize(n);
        while (m--) {
            int a, b; cin >> a >> b;
            --a; --b;
            g[a].push_back(b); g[b].push_back(a);
        }
    }

    ii cc_bipartite() {
        vi vis(n, 0), cor(n, 0);
        bool bipar = true;
        int cc = 0;

        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (auto v : g[u]) {
                if (!vis[v]) cor[v] = 1 - cor[u], dfs(v);
                if (cor[u] == cor[v])
                    bipar = false;
            }
        };

        for (int u=0; u < n; u++)
            if (!vis[u])
                cc++, dfs(u);

        return {cc, bipar};
    }
};

int main () {
    int n, m; cin >> n >> m;
    auto graph = Graph(n, m);
    auto [cc, bipar] = graph.cc_bipartite();
    if (!bipar)
        cc--;
    cout << cc << endl;
}