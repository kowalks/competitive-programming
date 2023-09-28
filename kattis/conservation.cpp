#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;
    vi lab;

    Graph(int n, int m): n(n), m(m) {
        g.resize(n);
        while (n--) {
            int x; cin >> x;
            lab.push_back(--x);
        } 
        while(m--) {
            int x, y; cin >> x >> y;
            g[--x].push_back(--y);
        }
    }

    int toposort(int l) {
        queue<int> pq[2];
        int cnt = 0;

        vi in_deg(n, 0);
        for (int i=0; i < n; i++)
            for (auto v : g[i])
                in_deg[v]++;
        
        for (int u=0; u < n; u++)
            if (in_deg[u] == 0) pq[lab[u]].push(u);

        do {
            while(!pq[l].empty()) {
                int u = pq[l].front(); pq[l].pop();
                for (auto v : g[u])
                    if (--in_deg[v] == 0) pq[lab[v]].push(v);
            }
            cnt++; l = 1-l;
        } while(!pq[l].empty());

        return cnt-1;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    auto graph = Graph(n, m);

    cout << min(graph.toposort(0), graph.toposort(1)) << endl;
}

int main () {
    int t; cin >> t;
    while(t--)
        solve();
}