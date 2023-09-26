#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    vector<string> b;
    map<ii, bool> visited;
    vector<ii> d = {{0,1}, {0,-1}, {1,0}, {1,1}, {1,-1}, {-1,1}, {-1,0}, {-1,-1}};
    int n, m;

    Graph(int n, int m) : n(n), m(m) {
        b = vector<string>(n);
        for (int i=0; i < n; i++)
            cin >> b[i];
    }

    int count() {
        int cnt = 0;
        for (int i=0 ; i < n; i++) for (int j=0; j < m; j++) {
            ii cell = {i,j};
            if (b[i][j] == '#' && !visited[cell]){
                dfs(cell);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(ii cell) {
        if (visited[cell])
            return;
        
        auto [cx, cy] = cell;
        
        if (cx < 0 || cy < 0 || cx >= n || cy >= m || b[cx][cy] == '.')
            return;
        
        visited[cell] = true;
        for (auto [dx,dy] : d) {
            dfs({dx+cx, dy+cy});
        }
    }
};

int32_t main () {
    int n, m; cin >> n >> m;
    auto graph = Graph(n, m);
    cout << graph.count() << endl;
}