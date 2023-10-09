#include "../template.h"

struct Graph {
    int n, m;
    vector<vi> g; vector<vii> gw;

    void dfs(int);
    void bfs(int);
    vi conncomp();
    vi toposort();
    vi articulations();
    vi bridges();
    vi dijkstra(int);
};