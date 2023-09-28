#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;

struct Graph {
    int n, m; vector<vi> g;
    vector<ii> o;

    Graph(int n): n(n), m(n-1) {
        g.resize(n);
        for (int i=0; i < m; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
            o.emplace_back(x, y);
        }
    }

    vi color() {
        vi cor(n, INF);

        function<void(int)> dfs = [&](int u){
            for (int v : g[u]) {
                if (cor[v] == INF) cor[v] = 1-cor[u], dfs(v);
            }
        };

        cor[0] = 0; dfs(0);
        return cor;
    }
};

int main () {
    int n; cin >> n;
    auto graph = Graph(n);
    auto cor = graph.color();
    for (auto [a, b] : graph.o) {
        if (cor[a] == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}