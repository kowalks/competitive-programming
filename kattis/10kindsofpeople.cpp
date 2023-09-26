#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int n, m, c;
    vector<string> b;
    vector<vi> cc;
    vector<ii> d = {{-1, 0}, {1, 0}, {0, 1}, {0,-1}};

    Graph() {
        cin >> n >> m;
        cc = vector<vi>(n, vi(m, 0));
        for (int i=0; i < n; i++) {
            string s; cin >> s;
            b.push_back(s);
        }
    }

    bool invalid(int i, int j) { return (i < 0 || j < 0 || i >= n || j >= m); }

    void dfs(int i, int j, int c) {
        if (cc[i][j])
            return;
        if (invalid(i, j))
            return;
        
        cc[i][j] = c;
        for (auto [dx,dy] : d) {
            if (invalid(dx+i, dy+j))
                continue;
            if (b[dx+i][dy+j] == b[i][j])
                dfs(dx+i, dy+j, c);
        }
    }

    void process() {
        c = 0;
        for (int i=0; i < n; i++) for (int j=0; j < m; j++)
            if (!cc[i][j])
                dfs(i,j, ++c);
    }
};

int32_t main () {
    auto graph = Graph();
    int q; cin >> q;

    graph.process();

    while(q--) {
        int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; r2--; c1--; c2--;
        if (graph.cc[r1][c1] == graph.cc[r2][c2]) {
            if (graph.b[r1][c1] == '1')
                cout << "decimal\n";
            else
                cout << "binary\n";
        } else
            cout << "neither\n";
    }
}