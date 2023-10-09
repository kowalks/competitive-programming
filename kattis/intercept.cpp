#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef tuple<ll, int, int> iii;
typedef priority_queue<iii, vector<iii>, greater<iii>> min_heap;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

fstream test;

struct Graph {
    int n, m;
    map<int, vii> gw;
    map<int, vi> g;       // subgraph
    vi exp, art, p; int cnt = 0;
    vector<bool> vis;

    Graph(int n, int m): n(n), m(m) {
        while(m--) {
            int x, y, w; test >> x >> y >> w;
            gw[x].emplace_back(y, w);
            gw[y].emplace_back(x, w);
        }
    }

    void dijkstra(int u){
        vi d(n, LINF); d[u]=0;                  // distance to u
        min_heap pq; pq.emplace(0, u, u);          // add first node
        vi vis(n, 0);

        while(!pq.empty()) {
            auto [du, u, v] = pq.top(); pq.pop();
            if (du > d[u]) continue;            // lazy deletion
            if (u != v)
                g[u].push_back(v), g[v].push_back(u);
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : gw[u]) if (d[v] >= d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v, u);
            }
        }
    }

    ll dfs(ll u, ll p) {
        ll low = exp[u] = ++cnt;
        for (auto& v : g[u]) if (v != p) {
            if (!exp[v]) {
                ll val = dfs(v, u);
                low = min(low, val);
                if (val >= exp[u])
                    art[u]++;
            } else low = min(low, exp[v]);
        }
        if (p == -1 and art[u]) art[u]--;
        return low;
    }

    vi articulations() {
        exp.resize(n, 0); art.resize(n, 0);
        cnt = 0;
        
        for(ll u=0; u<n; u++)
            if (!exp[u]) dfs(u, -1);
        
        return art;
    }

    void dfs_path(int u) {
        vis[u] = true;
        for (auto v : g[u])
            if (!vis[v])
                p[v] = u, dfs_path(v);

    }

    set<int> path(int u, int v) {
        vis.resize(n, false);
        p.resize(n, 0);

        dfs_path(u);

        set<int> path;
        while(v != u) {
            path.emplace(v);
            v = p[v];
        }
        path.emplace(v);
        return path;
    }
};

int main () {
    test = fstream("tst/butterflies1.in");

    int n, m; test >> n >> m;
    auto graph = Graph(n, m);
    int s, t; test >> s >> t;

    graph.dijkstra(s);
    auto art = graph.articulations();
    auto path = graph.path(s, t);
    art[s] = art[t] = 1;
    for (int i=0; i < n; i++) {
        if (art[i] == 0) continue;
        if (path.count(i) > 0)
            cout << i << " ";
    }
    cout << endl;
}