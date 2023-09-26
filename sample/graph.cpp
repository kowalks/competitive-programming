#include "template.h"

struct Graph {
    int n, m;
    vector<vi> p;
    vi visited;

    Graph(int n, int m): n(n), m(m) {
        p = vector<vi>(n+1);
        visited = vi(n+1, 0);
        while(m--) {
            int x, y; cin >> x >> y;
            p[x].pb(y);
            p[y].pb(x);
        }
    }

    void dfs(int a) {
        if(visited[a])
            return;
        
        visited[a] = 1;
        for (int v : p[a])
            dfs(v);
    }

    void bfs(int a) {
        queue<int> q; q.push(a);
        while(!q.empty()) {
            int a = q.front(); q.pop();
            visited[a] = 1;

            for (int v : p[a]) {
                if (visited[v])
                    continue;
                q.push(v);
            }
        }

    }
};
