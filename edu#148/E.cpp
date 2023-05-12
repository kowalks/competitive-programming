#include <bits/stdc++.h>
#define int long long
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int32_t main () {
    int n, a, x, y, m, k;
    cin >> n >> a >> x >> y >> m >> k;
    vector<vi> b(k+1LL, vi(n+1LL));
    b[1][1] = a;
    b[1][0] = 0LL;
    int s = 0LL;
    for (int i=1LL ; i <= n; i++) {
        s = (s + a) % MOD;
        b[1][i] = (s + b[1][i-1]) % MOD;
        a = (a * x + y) % m;
    }

    for (int i=2LL; i <= k; i++) {
        b[i][0] = 0;
        for (int j=1LL; j <= n; j++)
            b[i][j] = (b[i][j-1] + b[i-1][j-1]) % MOD;
    }

    int c = 0;
    for (int i=1LL; i <= n; i++) {
        c ^= i * b[k][i]; 
    }

    cout << c << endl;
}