#include "graph.h"

// returns number of new CC when each point is removed
// i.e. >= 1 if it is am articulation point
vi Graph::articulations() {
    vi exp(n, 0), art(n, 0);    // exp: exploration count

    int cnt = 0;
    function<int(int, int)> dfs = [&](int u, int p) {
        int low = exp[u] = ++cnt;
        for (int v : g[u]) if (v != p) {
            if (!exp[v]) {
                int val = dfs(v, u);
                low = min(low, val);
                if (val >= exp[u])
                    art[u]++;
                // if (val > exp[u]) (u, v) is a bridge
            } else low = min(low, exp[v]);
        }
        if (p == -1 and art[u]) art[u]--;     // if root 
        return low;
    };

    for (int i=0; i < n; i++)
        if (!exp[i]) dfs(i, -1);
    
    return art;
}