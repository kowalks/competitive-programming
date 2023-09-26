#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

struct Graph {
    int n, m;
    vector<string> b, b_old;
    vector<vi> cc;
    vi cc_valid;
    vector<ii> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    Graph() {
        cin >> n >> m;
        for (int i=0; i < n; i++) {
            string s; cin >> s;
            b_old.push_back(s);
            for (auto& c : s)
                if (c == 'C') c = 'L';
            b.push_back(s);
        }
        cc = vector<vi>(n, vi(m, 0));
        cc_valid = vi(m*n+1, 0);
    }

    int count() {
        int cnt = 0;
        for (int i=0; i < n; i++) for (int j=0; j < m; j++) {
            if (b[i][j] == 'L' && !cc[i][j])
                dfs(i, j, ++cnt);
        }

        return accumulate(cc_valid.begin(), cc_valid.end(), 0);
    }

    void dfs(int i, int j, int c) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;
        
        if (b[i][j] == 'W' || cc[i][j])
            return;
        
        cc[i][j] = c;
        if (b_old[i][j] == 'L')
            cc_valid[c] = 1;
        for (auto [dx, dy] : d) {
            dfs(i+dx, j+dy, c);
        }
    }
};

int32_t main () {
    auto g = Graph();
    cout << g.count() << endl;
}