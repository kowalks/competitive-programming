#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define s second
#define f first

using namespace std;
typedef vector<int> vi;

struct DSU {
    vi p, r, m;
    DSU(int n) {
        p = vi(n+1); iota(p.begin(), p.end(), 0);
        r = vi(n+1, 0);
        m = vi(n+1, -1);
    }

    int get(int a) { return p[a] = p[a] == a ? a : get(p[a]); }

    void join(int a, int b) {
        a = get(a); b = get(b);
        if (a==b)
            return;
        if (r[a] == r[b])
            r[a]++;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
    }
};

int32_t main(){
    int n, m; cin >> n >> m;
    auto dsu = DSU(n);
    vector<pair<int,int>> monkey, monkey_final;
    vector<tuple<int, int, int>> query;

    for (int i=0; i < n; i++) {
        int l, r; cin >> l >> r;
        monkey.emplace_back(l, r);
    }

    monkey_final.assign(monkey.begin(), monkey.end());

    for (int i=0; i < m; i++) {
        int p, h; cin >> p >> h; p--;
        query.emplace_back(i, p, h);
        if(h==1)
            monkey_final[p].f = -1;
        else
            monkey_final[p].s = -1;
    }

    for (int i=0; i<n; i++) {
        if (monkey_final[i].f != -1)
            dsu.join(i, monkey_final[i].f);
        if (monkey_final[i].s != -1)
            dsu.join(i, monkey_final[i].s);
    }

    // for (int i=0; i<n; i++) {
    //     if (get(0) != get(i))
    // }

    reverse(query.begin(), query.end());
    for (auto [i, p, h] : query) {
        if (h == 1)
            dsu.join(p, monkey[p].f);
        else
            dsu.join(p, monkey[p].s);
        if (dsu.get(0) == dsu.get(p))
            dsu.m[p] = i;
    }

}