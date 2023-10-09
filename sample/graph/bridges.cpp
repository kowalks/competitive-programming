#include "graph.h"

// returns bi-edge-connected component for each vertex
// the number in component is the edge of bridge 
vi Graph::bridges() {
    vi p(n); iota(p.begin(), p.end(), 0);
    vi exp(n, 0);

    int cnt = 0; int b = 1;
    function<int(int)> dfs = [&](int u) {
        int low = exp[u] = ++cnt;
        for (int v : g[u]) if (v != p[u]) {
            if (!exp[v]) {
                p[v] = u;
                int val = dfs(v);
                low = min(low, val);
                if (val > exp[u]) p[v] = v;
            } else low = min(low, exp[v]);            
        }
        return low;
    };

    function <int(int)> find = [&](int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    };

    for (int u=0; u < n; u++)
        if (!exp[u]) dfs(u);
        else p[u] = find(p[u]);
    return p;
}