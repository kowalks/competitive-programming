#include<bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct Matrix {
    int a, b, c, d, r;

    Matrix (int a, int b, int c, int d, int r){
        this->a = a%r;
        this->b = b%r;
        this->c = c%r;
        this->d = d%r;
        this->r = r;
    }

    Matrix operator+ (Matrix other) {
        int x = a*other.a + b*other.c;
        int y = a*other.b + b*other.d;
        int z = c*other.a + d*other.c;
        int w = c*other.b + d*other.d;
        return Matrix(x, y, z, w, r);
    }
};

typedef vector<Matrix> vm;

struct Segtree {
    int n; vm v; int mod;
    vm seg;

    Segtree(vm v, int mod): v(v), mod(mod) {
        int n = v.size();
        seg.resize(4*n, Matrix(1, 0, 0, 1, mod));
        build(1, 0, n-1);
    }

    Matrix build(int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    Matrix query(int a, int b, int p, int l, int r) {
        if (b < l or r < a) return Matrix(1, 0, 0, 1, mod);
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }
};

int main () { _
    int r, n, q; cin >> r >> n >> q;
    vm a;

    for (int i=0; i < n; i++) {
        int x, y, z, w; cin >> x >> y >> z >> w;
        a.emplace_back(x, y, z, w, r);
    }

    auto seg = Segtree(a, r);
    while(q--) {
        int i, j; cin >> i >> j;
        auto m = seg.query(i-1, j-1, 1, 0, n-1);
        cout << endl << m.a << " " << m.b << endl << m.c << " " << m.d << endl;
    }
}