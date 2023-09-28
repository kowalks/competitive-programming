#include <graph.h>

vi Graph::conncomp() {
    vi vis(n, 0), cc(n, 0);

    function<void(int)> dfs = [&](int a) {
        vis[a] = 1;
        for (auto v : g[a])
            if (!vis[v]) dfs(v);
    };

    int cnt = 0;
    for (int i=0; i < n; i++)
        if (!vis[i]) cnt++, dfs(i);
    
    return cc;
}