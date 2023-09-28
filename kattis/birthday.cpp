#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n, int m): n(n), m(m) {
        g.resize(n);
        while(m--) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    bool bridges() {
        vi exp(n, 0); bool bridge = false;

        int cnt = 0;
        function<int(int, int)> dfs = [&](int u, int p) {
            int low = exp[u] = ++cnt;
            for (auto v : g[u]) if (v != p) {
                if (!exp[v]) {
                    int val = dfs(v, u);
                    low = min(low, val);
                    if (val > exp[u])
                        bridge = true;
                } else low = min(low, exp[v]);
            }
            return low;
        };

        for (int i=0; i < n; i++)
            if (!exp[i]) dfs(i, -1);
        return bridge;
    }
};

bool solve() {
    int n, m; cin >> n >> m;
    if (n == 0 and m == 0) return false;

    auto graph = Graph(n, m);
    auto b = graph.bridges();

    if (b) cout << "Yes\n";
    else cout << "No\n";

    return true;
}

int main () {
    while (solve());
}