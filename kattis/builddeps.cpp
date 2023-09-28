#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n): n(n) { g.resize(n); };

    vi toposort(int a) {
        vi ts, vis(n,0);

        bool dag = true;
        function<void(int)> dfs = [&](int a){
            vis[a] = 1;
            for (auto v : g[a])
                if (vis[v] == 1) dag = false;
                else if (!vis[v]) dfs(v);
            ts.push_back(a);
            vis[a] = 2; 
        };

        dfs(a);
        reverse(ts.begin(), ts.end());
        return ts;
    }
};

int main () {
    int n; cin >> n;
    auto graph = Graph(n+1);

    map<string, int> m;
    map<int, string> mr;
    int cnt = 1;
    for (int i=0; i < n; i++) {
        string s; cin >> s; s.pop_back();
        if (!m[s])
            m[s] = cnt, mr[cnt] = s, cnt++;

        string t; getline(cin, t);
        auto ss = stringstream(t);
        while(!ss.eof() && t.size() > 0) {
            string t; ss >> t;
            if (!m[t])
                m[t] = cnt, mr[cnt] = t, cnt++;
            graph.g[m[t]].push_back(m[s]);
        }
    }

    string s; cin >> s;

    auto ts = graph.toposort(m[s]);
    for (auto a : ts)
        cout << mr[a] << endl;
}