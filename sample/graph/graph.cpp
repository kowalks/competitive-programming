#include "graph.h"

Graph::Graph() {
    cin >> n >> m;
    g = vector<vi>(n);
    while(m--) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}

void Graph::dfs(int a) {
    vi vis(n, 0);

    function<void(int)> dfs = [&](int a){
        vis[a] = 1;
        for (int v : g[a])
            if (!vis[a]) dfs(a);
    };

    for (int i=0 ; i < n; i++)
        if (!vis[i]) dfs(i);
}

void Graph::bfs(int a) {
    vi vis(n, 0);
    queue<int> q; q.push(a);

    while(!q.empty()) {
        int a = q.front(); q.pop();
        if (vis[a]) continue;

        vis[a] = 1;
        for (int v : g[a])
            if (!vis[a]) q.push(v);
    }
}