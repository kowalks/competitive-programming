#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n, int m): n(n), m(m) {
        g = vector<vi>(n);
        while(m--) {
            int x, y; cin >> x >> y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    bool toposort(int, int);
};

bool Graph::toposort(int u, int t) {
    vi leave(n, 0), vis(n, 0);

    priority_queue<int, vi, greater<int>> pq;   // min priority queue
    pq.push(u);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        if (u == t) return true;
        if (vis[u]) continue;

        vis[u] = 1;
        for (int v : g[u]) {
            leave[v]++;
            if (2*leave[v] >= g[v].size() && !vis[v]) pq.push(v);
        }
    }

    return false;
}

int main () {
    int c, p, x, l; cin >> c >> p >> x >> l;

    auto g = Graph(c, p);
    cout << (g.toposort(--l, --x) ? "leave" : "stay") << endl;
}