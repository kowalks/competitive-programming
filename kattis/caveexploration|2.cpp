#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph (int n, int m): n(n), m(m) {
        g.resize(n);
        while(m--) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    pair<vi, vi> articulations(){
        vi exp(n, 0), art(n,0), low(n,0);

        int cnt = 0;
        function<void(int,int)> dfs = [&](int u, int p) {
            low[u] = exp[u] = ++cnt;
            for (int& v : g[u]) if (v != p) {
                if (!exp[v]) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] >= exp[u])
                        art[u]++;
                    // if (low[v] > exp[u])

                } else low[u] = min(low[u], exp[v]);
            }
            if (p == -1 and art[u]) art[u]--;
        };

        for (int u=0; u < n; u++)
            if (!exp[u]) dfs(u, -1);
        
        return {exp, low};
    };

    int count(int u, vi& exp, vi& low) {
        vi vis(n, 0);

        int cnt = 0;
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1; cnt++;
            for (int& v : g[u])
                if (!vis[v] && low[v] <= exp[u])
                    dfs(v);
        };

        dfs(0);
        return cnt;
    }
};

int main () {
    int n, m; cin >> n >> m;
    auto graph = Graph(n, m);

    auto [exp, low] = graph.articulations();
    cout << graph.count(0, exp, low) << endl;
}