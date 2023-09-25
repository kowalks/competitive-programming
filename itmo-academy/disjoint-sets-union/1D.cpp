#include<bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef vector<int> vi;

struct DSU {
    vi p, r;

    DSU(int n) {
        p = vi(n+1), iota(p.begin(), p.end(), 0);
        r = vi(n+1,0);
    }

    int get(int a) { return p[a] = p[a] == a ? a : get(p[a]); }

    void join(int a, int b) {
        a = get(a); b = get(b);
        if (a == b)
            return;
        if (r[a] == r[b])
            r[a]++;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
    }
};

int32_t main () { _
    int n, m, k; cin >> n >> m >> k;
    vector<bool> ans;
    DSU dsu(n);
    
    while(m--) {
        int u, v;
        cin >> u >> v;
    }

    vector<tuple<string, int, int>> query;
    while(k--){
        string s; cin >> s;
        int u, v; cin >> u >> v;
        query.emplace_back(s, u, v);
    }

    reverse(query.begin(), query.end());

    for (auto [s, u, v] : query)
        if (s == "ask")
            ans.push_back(dsu.get(u) == dsu.get(v));
        else
            dsu.join(u, v);
    
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << (a ? "YES" : "NO") << endl;
}