#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int x, y;
    vector<vi> p;
    map<ii, bool> visited;
    vector<ii> d = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int cnt = 0;
    
    Graph(int x, int y) : x(x), y(y) {
        p = vector<vi>(x);
        for (auto& l : p) {
            l = vi(y);
            for (auto& c : l)
                cin >> c;
        }
        // for (int i=0; i < x; i++)
        //     for (int j=0; i < y; j++)
        //         visited[{x, y}] = false;
    }

    int count() {
        int total = 0;
        for (int i=0; i < x; i++)
            for (int j=0; j < y; j++)
                if (!visited[{i,j}]) {
                    int prev = cnt;
                    if (dfs(i, j, p[i][j]))
                        total += cnt - prev;
                }
        return total;
    }

    bool dfs(int i, int j, int h) {
        if (i < 0 || j < 0 || i >= x || j >= y)
            return true;
        if (visited[{i,j}] || p[i][j] != h)
            return p[i][j] >= h;

        visited[{i,j}] = true;
        cnt++;

        bool ans = true;
        for (auto [dx, dy] : d)
            ans = dfs(i+dx, j+dy, h) ? ans : false;
        return ans ? p[i][j] >= h : ans;
    }
};

int32_t main () {
    int x, y; cin >> y >> x;
    auto graph = Graph(x, y);
    cout << graph.count() << endl;
}