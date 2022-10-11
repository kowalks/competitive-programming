#include<bits/stdc++.h>
#define P 10007
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
            c[i][j] = (((k+P)%P)*a[i][j])%P;
    return c;
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

inline matrix operator*(const matrix& a, const int& k) { return k*a; }
inline matrix operator-(const matrix& a, const matrix& b) { return a+(-1)*b; }
inline matrix& operator+=(matrix& a, const matrix& b) { return a = a+b; }
inline matrix& operator-=(matrix& a, const matrix& b) { return a = a-b; }
inline matrix& operator*=(matrix& a, const matrix& b) { return a = a*b; }

int fibo(int n) {
    matrix f = {{1,1},{1,0}};
    f = f^n;
    return f[0][1];
}

int solve(int n) {
    matrix m = {{2,2,1,0},{1,0,0,0},{0,0,2,2},{0,0,1,0}};
    matrix v = {{4},{1},{6},{2}};
    m = m^n;
    m = m*v;
    return m[1][0];
}

int main () {
    int n;
    cin >> n;
    while(n != -1) {
        cout << solve(n) << endl;
        cin >> n;
    }
}