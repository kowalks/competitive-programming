#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n): n(n) { g.resize(n); };

    vi traversal(int u) {
        vi p(n), vis(n,0);
        iota(p.begin(), p.end(), 0);

        bool dag = true;
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for (auto v : g[u])
                if (!vis[v]) p[v] = u, dfs(v);
        };

        dfs(u);
        return p;
    }
};

int main () {
    int n; cin >> n;
    auto graph = Graph(100);

    map<string, int> m;
    map<int, string> mr;
    int cnt = 1;
    for (int i=0; i < n; i++) {
        string s; cin >> s;;
        if (!m[s])
            m[s] = cnt, mr[cnt] = s, cnt++;

        string t; getline(cin, t);
        auto ss = stringstream(t);
        while(!ss.eof() && t.size() > 0) {
            string t; ss >> t;
            if (!m[t])
                m[t] = cnt, mr[cnt] = t, cnt++;
            graph.g[m[t]].push_back(m[s]);
            graph.g[m[s]].push_back(m[t]);
        }
    }

    string srce, dest; cin >> srce >> dest;
    int s = m[srce], d = m[dest];
    auto p = graph.traversal(s);
    if (p[d] == d) {
        cout << "no route found\n";
        return 0;
    }

    vi ans;
    while(p[d] != d)
        ans.push_back(d), d = p[d];
    ans.push_back(d);
    
    reverse(ans.begin(), ans.end());
    for (auto u : ans)
        cout << mr[u] << " ";
    cout << endl;
    return 0;
}