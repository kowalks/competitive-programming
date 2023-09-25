#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    vector<vi> g;
    vi visited;
    int n, m;

    Graph(int n, int m) : n(n), m(m) {
        g = vector<vi>(n+1);
        visited = vi(n+1, 0);
        while(m--) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    int count() {
        int cnt = 0;
        for (int i=0; i < n; i++)
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        return cnt;
    }

    void dfs(int a) {
        if (visited[a])
            return;
        visited[a] = 1;
        for (auto p : g[a])
            dfs(p);
    }

};

void solve() {
    int n, r; cin >> n >> r;
    auto graph = Graph(n,r);
    cout << graph.count() - 1 << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}