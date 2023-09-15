#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

vi p, r;
vl s;

void init(int n) {
    p = vi(n+1); iota(p.begin(), p.end(), 0);
    r = vi(n+1, 0);
    s = vl(n+1, 0);
}

int get(int a) {
    if (p[p[a]] == p[a]) return p[a];
    s[a] += s[p[a]];
    return p[a] = get(p[a]);
}

void une(int a, int b) {
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

void add(int a, int val) {
    a = get(a);
    s[a] += val;
}

void solve(){
    string ss; cin >> ss;
    if (ss == "add") {
        int a, v; cin >> a >> v;
        add(a, v);
    } else if (ss == "join") {
        int a, b; cin >> a >> b;
        une(a, b);
        return;
    } else if (ss == "get") {
        int a; cin >> a;
        int b = get(a);
        if (a == b) cout << s[a] << endl;
        else cout << s[a] + s[b] << endl;
    }
}

int32_t main () { _
    int n, m; cin >> n >> m;
    init(n);
    while(m--)
        solve();
}