#include "graph.h"

vi Graph::dijkstra(int u){
    vi d(n, INF); d[u]=0;                  // distance to u
    min_heap pq; pq.emplace(0, u);          // add first node

    while(!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du > d[u]) continue;            // lazy deletion

        for (auto [v, w] : gw[u]) if (d[v] > d[u] + w) {
            d[v] = d[u] + w;
            pq.emplace(d[v], v);
        }
    }
    return d;
}