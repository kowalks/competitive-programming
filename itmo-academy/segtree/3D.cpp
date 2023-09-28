#include<bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

struct Segtree {
    int n; vi v;
    vi seg;

    Segtree(int n): n(n) {
        v.resize(n); fill(v.begin(), v.end(), 0);
        seg.resize(4*n); fill(seg.begin(), seg.end(), 0);
    }

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    int update(int i, int x) { return update(i, x, 1, 0, n-1); }

    int query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    int query(int a, int b) { return query(a, b, 1, 0, n-1); }
};

int main () { _
    int n; cin >> n;
    vi first(n, INF), last(n, INF);
    vi ans(n, 0); vi a(2*n, 0);

    auto seg = Segtree(2*n);
    for (int i=0; i < 2*n; i++) {
        int k; cin >> k; a[i] = --k;
        if (first[k] == INF) { // left end
            first[k] = i;
            seg.update(i, 1);
        } else { // right end
            seg.update(first[k], 0);
            ans[k] += seg.query(first[k], i);
        }
    }

    for (int i=2*n-1; i >= 0; i--) {
        int k = a[i];
        if (last[k] == INF) { // right end 
            last[k] = i;
            seg.update(i, 1);
        } else { // left end
            seg.update(last[k], 0);
            ans[k] += seg.query(i, last[k]);
        }
    }

    for (auto& a : ans)
        cout << a << " "; cout << endl;
}