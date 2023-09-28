#include "graph.h"

vi Graph::toposort() {
    vi vis(n, 0), ts;

    bool dag = true;
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto v : g[u])
            if (vis[v] == 1) dag = false;       // back edge (cycle detected)
            else if (!vis[v]) dfs(v);           // tree edge
        ts.push_back(u);                        // if vis[v]=2: forward edge
        vis[u] = 2;
    };

    for (int i=0; i < n; i++)
        if (!vis[i]) dfs(i);
    
    if (!dag) ts.clear();
    reverse(ts.begin(), ts.end());
    return ts;        
}

vi Graph::toposort() {
    vi in_deg(n, 0);
    for (int i=0; i < n; i++)
        for (int& v : g[i])
            in_deg[v]++;
    
    priority_queue<int, vi, greater<int>> pq;   // min priority queue
    for (int i=0; i < n; i++)
        if (in_deg[i] == 0)
            pq.push(i);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        for (int& v : g[u])
            if (--in_deg[v] == 0) pq.push(v);
    }

}