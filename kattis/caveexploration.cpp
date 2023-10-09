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

    auto bridges() {
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
};

int main () {
    int n, m; cin >> n >> m;
    auto graph = Graph(n, m);

    auto find = graph.bridges();
    
    int cnt = 0;
    for (int u=0; u <n; u++)
        if (find[u] == find[0]) cnt++;
    cout << cnt << endl;
}