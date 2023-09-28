#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n): n(n) {
        g.resize(n);
        int u; cin >> u;
        while (u-- != 0) {
            string s; getline(cin, s);
            stringstream ss(s);
            while(!ss.eof()) {
                int v; ss >> v; v--;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            cin >> u;
        }
    }

    vi articulations() {
        vi exp(n, 0), art(n, 0);    // exp: exploration count

        int cnt = 0;
        function<int(int, int)> dfs = [&](int u, int p) {
            int low = exp[u] = ++cnt;
            for (int v : g[u]) if (v != p) {
                if (!exp[v]) {
                    int val = dfs(v, u);
                    low = min(low, val);
                    if (val >= exp[u])
                        art[u]++;
                    // if (val > exp[u]) (u, v) is a bridge
                } else low = min(low, exp[v]);
            }
            if (p == -1 and art[u]) art[u]--;     // if root 
            return low;
        };

        for (int i=0; i < n; i++)
            if (!exp[i]) dfs(i, -1);
        
        return art;
    }
};

bool solve() {
    int n; cin >> n;
    if (n == 0) return false;

    auto graph = Graph(n);
    auto art = graph.articulations();

    int cnt = 0;
    for (int a : art) if (a > 0) cnt++;
    cout << cnt << endl;
    return true;
}

int main () {
    while(solve());
}