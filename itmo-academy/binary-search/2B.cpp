#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi a;

int f(double x, int n) {  // 111..11100000..0
    if (x == 0) return 1;
    for (auto aa : a) {
        if (aa/x > n)
            return 1;
        n -= (int) (aa/x);
        if (n<=0) return 1;
    }
    return 0;
}

int32_t main () {
    int n, k; cin >> n >> k;
    a = vi(n); for (int& aa : a) cin >> aa;

    double l=0, r = 1e8;
    for(int i=0; i < 100; i++) {
        double m = (l+r)/2;
        if (f(m, k) == 1)
            l = m;
        else
            r = m;
    }

    cout << setprecision(20) << r << endl;
}