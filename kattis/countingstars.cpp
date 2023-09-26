#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef pair<int,int> ii;

struct Graph {
    int n, m;
    vector<string> b;
    vector<ii> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    map<ii, bool> visited;

    Graph(int n, int m): n(n), m(m) {
        while(n--) {
            string s; cin >> s;
            b.pb(s);
        }
    }

    int count() {
        int cnt = 0;
        for (int i=0 ; i < n; i++) for (int j=0; j < m; j++)
            if (!visited[{i,j}] && b[i][j] == '-') {
                dfs({i,j});
                cnt++;
            }
        return cnt;
    }

    void dfs(ii cell) {
        if (visited[cell])
            return;

        auto [x,y] = cell;
        if (x < 0 || y < 0 || x >= n || y >= m || b[x][y] == '#')
            return;
        
        visited[cell] = true;
        for (auto [dx, dy] : d) {
            dfs({x+dx, y+dy});
        }
    }
};

int32_t main () { _
    int t = 1;
    while (!cin.eof()) {
        int n=0, m=0; cin >> n >> m;
        if (n == 0)
            break;
        auto graph = Graph(n, m);
        cout << "Case "<< t++ << ": "<< graph.count() << endl;
    }
}