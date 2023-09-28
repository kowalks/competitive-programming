#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct Graph {
    int n, m;
    vector<vi> g;

    Graph(int n): n(n) {
        g.resize(n);
        while (true) {
            int x, y; cin >> x >> y;
            if (x == -1 and y == -1) break;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    vi articulations() {
        vi exp(n, 0), art(n, 0);

        int cnt = 0;
        function<int(int,int)> dfs = [&](int u, int p) {
            int low = exp[u] = ++cnt;
            for (auto& v : g[u]) if (v != p) {
                if (!exp[v]) {
                    int val = dfs(v, u);
                    low = min(low, val);
                    if (val >= exp[u])
                        art[u]++;
                } else low = min(low, exp[v]);
            }
            if (p == -1 and art[u]) art[u]--;
            return low;
        };

        for (int u=0; u < n; u++)
            if (!exp[u]) dfs(u, -1);
        
        return art;
    }
};

bool solve() {
    int n, m; cin >> n >> m;
    if (n == 0 and m == 0) return false;

    auto graph = Graph(n);
    auto art = graph.articulations();

    vector<ii> ans;
    for (int i=0; i<n; i++)
        ans.emplace_back(-art[i], i);
    
    sort(ans.begin(), ans.end());

    for (int i=0; i < m; i++) {
        auto [a, u] = ans[i];
        // if (i != 0) cout << endl;
        cout << u << " " << -a + 1 << endl;
    }
    cout << endl;

    return true;
}

int main () {
    while(solve());
}