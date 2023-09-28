#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int m): m(m), g(5001) { };

    bool dag(int u) {
        vi vis(n+1, 0);
        bool dag = true;

        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for (int v : g[u])
                if (vis[v] == 1)  dag = false;
                else if (!vis[v]) dfs(v);
            vis[u] = 2;
        };

        dfs(u);
        return dag;
    }
};

int main () {
    int m; cin >> m;
    auto g = Graph(m);
    map<string, int> mp, mr; int n = 0;

    while (m--) {
        string r, s; cin >> r >> s;
        if (!mp[r]) mp[r] = ++n;
        if (!mp[s]) mp[s] = ++n;
        g.g[mp[r]].push_back(mp[s]);
    }
    g.n = n;

    while(!cin.eof()) {
        string s; cin >> s;
        if (s.size() == 0) break;
        if (g.dag(mp[s]))
            cout << s << " trapped" << endl;
        else
            cout << s << " safe" << endl;
    }
}