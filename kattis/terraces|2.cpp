#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int x, y;
    vector<vi> p;
    map<ii, bool> visited;
    map<ii, int> cc;
    int cc_cnt = 0;
    vi size;
    vector<ii> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    Graph(int x, int y) : x(x), y(y) {
        p = vector<vi>(x);
        for (auto& l : p) {
            l = vi(y);
            for (auto& c : l)
                cin >> c;
        }

        assign_cc();
    }

    void assign_cc() {
        cc_cnt = 0;
        for (int i=0; i < x; i++) for (int j = 0; j < y; j++) {
            if (!visited[{i,j}]){
                size.push_back(0);
                dfs(i, j, p[i][j]);
                cc_cnt++;
            }
        }
    }

    void dfs(int i, int j, int h) {
        if (i < 0 || j < 0 || i >= x || j >= y)
            return;
        if (visited[{i,j}] || p[i][j] != h)
            return;

        visited[{i,j}] = true;
        cc[{i,j}] = cc_cnt;
        size[cc_cnt]++;

        for (auto [dx, dy] : d) {
            dfs(i+dx, j+dy, h);
        }
    }

    void check() {
        for (int i=0; i < x; i++) for (int j = 0; j < y; j++) {
            for (auto [dx, dy] : d) {
                int x = i + dx, y = j + dy;
                if (x < 0 || y < 0 || x >= this->x || y >= this->y)
                    continue;
                if (p[x][y] < p[i][j])
                    size[cc[{i,j}]] = 0;
            }
        }
    }

    int count() {
        check();
        return accumulate(size.begin(), size.end(), 0);
    }
};

int32_t main () {
    int x, y; cin >> y >> x;
    auto graph = Graph(x, y);
    cout << graph.count() << endl;
}