#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int n, m;
    vector<string> b;
    vector<vi> cc;
    int cnt;
    vector<ii> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    Graph() {
        cin >> n >> m;
        b = vector<string>(n+2, string(m+2, '0'));
        for (int i=1; i <= n; i++) {
            string s; cin >> s;
            for (int j=0; j < m; j++)
                b[i][j+1] = s[j];
        }
        cc = vector<vi>(n+2, vi(m+2, 0));
        m+=2; n+=2;
    }

    int count() {
        cnt = 0;
        
        for (int i=0; i < n; i++) {
            if (!cc[i][0])
                dfs(i, 0);
            if (!cc[i][m-1])
                dfs(i, m-1);
        }
        for (int i=0; i < m; i++) {
            if (!cc[0][i])
                dfs(0, i);
            if (!cc[n-1][i])
                dfs(n-1, i);
        }

        return cnt;
    }

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || cc[i][j])
            return;
        
        if (b[i][j] == '1') {
            cnt++; return;
        }

        cc[i][j] = 1;
        for (auto [dx, dy] : d) {
            dfs(dx+i, dy+j);
        }
    }
};

int main () {
    auto graph = Graph();
    cout << graph.count() << endl;
}