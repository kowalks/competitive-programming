#include<bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef vector<int> vi;

vi a;

struct Segtree {
    int n; vi seg, cnt, left;

    Segtree(int n): n(n) {
        seg = vi(4*n);
        cnt = vi(n/2, 0);
        left = vi(n/2);
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
        if (l == r) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    int query(int a, int b) { return query(a, b, 1, 0, n-1); }

    void count() {
        for (int i=n-1; i >= 0; i--)
            left[a[i]] = i;
        for (int i=0 ; i < n; i++) {
            if (left[a[i]] == i) { // left
                update(i, 1);
            } else { // rigjt
                update(left[a[i]], 0);
                cnt[a[i]] += query(left[a[i]], i);
            }
        }
    }
};

int main () { _
    int n; cin >> n;
    a.resize(2*n); for (int& x : a) {
        scanf("%d", &x);
        x--;
    }

    auto seg = Segtree(2*n);
    seg.count();
    reverse(a.begin(), a.end());
    seg.count();

    for (int i=0; i < n; i++)
        printf("%d ", seg.cnt[i]);
    printf("\n");
}