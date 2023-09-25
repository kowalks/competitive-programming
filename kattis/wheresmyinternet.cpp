#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct graph {
    vector<vi> g;
    vector<bool> v;
    int cnt = 0;

    graph(int n) {
        g = vector<vi>(n+1);
        v = vector<bool>(n+1, false);
    }

    void dfs(int i) {
        v[i] = true; cnt++;
        for (int p : g[i])
            if (!v[p])
                dfs(p);
    }
};

int32_t main () {
    int n, m; cin >> n >> m;
    auto gr = graph(n);

    for (int i=0; i < m; i++){
        int a, b; cin >> a >> b;
        gr.g[a].push_back(b);
        gr.g[b].push_back(a);
    }

    gr.dfs(1);

    if (gr.cnt == n){
        cout << "Connected\n";
        return 0;
    }

    for (int i=1; i <= n; i++)
        if (!gr.v[i])
            cout << i << endl;

}