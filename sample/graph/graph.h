#include "../template.h"

struct Graph {
    int n, m;
    vector<vi> g;

    void dfs(int);
    void bfs(int);
    vi conncomp();
    vi toposort();
    vi articulations();
};