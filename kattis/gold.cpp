#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Graph {
    int n, m;
    vector<string> b;
    vector<vi> visited;
    vector<ii> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<ii> pending;

    Graph (int n, int m): n(n), m(m) {
        visited = vector<vi>(n, vi(m, 0));
        while(n--) {
            string s; cin >> s;
            b.pb(s);
        }
    }

    bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

    void transform() {
        for (int i=0; i < n; i++) for(int j=0; j < m; j++) {
            if (b[i][j] == 'T') for (auto [dx,dy] : d) {
                b[i][j] = '#';
                if (valid(i+dx, j+dy)){
                    if (b[i+dx][j+dy] == 'G')
                        pending.push_back({i+dx, j+dy});
                    b[i+dx][j+dy] = '#';
                }
            }
        }
    }

    int dfs(int i, int j) {
        if (visited[i][j])
            return 0;
        
        if (!valid(i, j))
            return 0;
        
        visited[i][j] = 1;
        if (b[i][j] == '#') {
            return 0;
        }
        
        int cnt = 0;
        if (b[i][j] == 'G')
            cnt++;
        
        for (auto [dx, dy] : d) {
            cnt += dfs(i+dx, j+dy);
        }
        return cnt;
    }

    int count() {
        int px, py;
        for(int i=0; i < n; i++) for (int j=0; j < m; j++)
            if (b[i][j] == 'P') {
                px = i; py = j; break;
            }
        
        for (auto [dx, dy] : d) {
            if (valid(dx+px, dy+py))
                if (b[dx+px][dy+py] == 'T')
                    return 0;
        }

        transform();

        int cnt = dfs(px, py);
        for (auto [x,y] : pending) {
            if (visited[x][y])
                cnt++;
        }

        return cnt;
    }
};

int32_t main () {
    int n, m; cin >> m >> n;
    auto graph = Graph(n, m);
    cout << graph.count() << endl;
}