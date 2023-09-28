#include "graph.h"

vi Graph::conncomp() {
    vi vis(n, 0);
    int cc = 0;

    function<void(int)> dfs = [&](int u) {
        vis[u] = cc;
        for (auto v : g[u])
            if (!vis[v]) dfs(v);
    };

    int cc = 0;
    for (int i=0; i < n; i++)
        if (!vis[i]) cc++, dfs(i);
    
    return vis;
}