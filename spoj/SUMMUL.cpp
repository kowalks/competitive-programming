#include<bits/stdc++.h>
#define P 1000000007
#define int long long
using namespace std;

typedef vector<vector<int>> matrix;

ostream& operator<<(ostream& os, const matrix& m){
    for(int i = 0; i < m.size(); i++) {
        for (int j=0; j< m[i].size(); j++)
            os << m[i][j] << " ";
        os << endl;
    }
    return os;
}

matrix operator+(const matrix& a, const matrix& b) {
    int n = a.size(), m = a[0].size();
    matrix c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            c[i][j] = (a[i][j] + b[i][j])%P;
    return c;
}

matrix operator*(const matrix& a, const matrix& b) {
    int n = a.size(), k = a[0].size(), m = b[0].size();
    matrix c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l < k; l++)
                c[i][j] = (c[i][j] + (a[i][l]*b[l][j])%P)%P;
    return c;
}

matrix operator*(const int& k, const matrix& a) {
    int n = a.size(), m = a[0].size();
    matrix c(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for (int j=0; j< m; j++)
            c[i][j] = (k*a[i][j])%P;
    return c;
}

matrix operator*(const matrix& a, const int& k) {
    return k*a;
}

// Fast exponentiation
matrix operator^(const matrix& a, const int& k) {
    int n = a.size();
    matrix c(n, vector<int>(n));
    if (k == 0) {
        for (int i = 0; i < n; i++)
            c[i][i] = 1;
    } else {
        c = a^(k/2);
        c = c*c;
        if (k&1) c = a*c;
    }
    return c;
}

int fibo(int n) {
    matrix f = {{1,1},{1,0}};
    f = f^n;
    return f[0][1];
}

void solve() {
    int n;
    cin >> n;
    int fb = fibo(2*n);
    cout << (fb - n + P) % P << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--)
        solve();
}