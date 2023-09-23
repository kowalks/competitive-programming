#include<bits/stdc++.h>
#define int long long

using namespace std;
typedef vector<int> vi;

vi p, r, s;

int get(int a){
    if (p[a] == a)
        return a;
    int rep = get(p[a]);
    if (p[p[a]] != p[a])
        s[a] += s[p[a]];
    return p[a] = rep;
}

void join(int a, int b) {
    a = get(a); b = get(b);
    if (a == b)
        return;
    if (r[a] == r[b])
        r[a]++;
    if (r[a] < r[b])
        swap(a, b);
    p[b] = a;
    s[b] -= s[a];
}

void add(int x, int v){
    x = get(x);
    s[x] += v;
}

void init(int n){
    p = vi(n+1); iota(p.begin(), p.end(), 0);
    r = vi(n+1, 0ll);
    s = vi(n+1, 0ll);
}

int32_t main() {
    int n, m; cin >> n >> m;
    init(n);

    while(m--) {
        string str; cin >> str;
        if (str == "join") {
            int x, y; cin >> x >> y;
            join(x, y);
        } else if (str == "add") {
            int x, v; cin >> x >> v;
            add(x, v);
        } else if (str == "get") {
            int x; cin >> x;
            int y = get(x);
            cout << s[x] + ((x != y) ? s[y] : 0ll) << endl;
        }
    }
}