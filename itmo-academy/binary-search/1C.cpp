#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef vector<int> vi;
const int INF = 0x3F3F3F3F;

vi vec;

int find(int k, int l, int r) {
    if (r == l+1)
        return (vec[l] >= k) ? l : r;

    int m = (l+r)/2;
    if (vec[m] >= k)
        return find(k, l, m);
    return find(k, m, r);
}

void solve(int n) {
    int k; cin >> k;
    cout << find(k, 0, n+1) << endl;
}

int32_t main() { _
    int n, q; cin >> n >> q;
    vec = vi(n+2); vec[0] = -INT_MAX; vec[n+1] = INT_MAX;
    for (int i=1; i <= n; i++) cin >> vec[i];

    while(q--)
        solve(n);

}