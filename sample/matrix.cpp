#include<bits/stdc++.h>

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
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

matrix operator*(const matrix& a, const matrix& b) {
    int n = a.size(), k = a[0].size(), m = b[0].size();
    matrix c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l < k; l++)
                c[i][j] += a[i][l]*b[l][j];
    return c;
}

matrix operator*(const int& k, const matrix& a) {
    int n = a.size(), m = a[0].size();
    matrix c(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for (int j=0; j< m; j++)
            c[i][j] = k*a[i][j];
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

int main () {
    for (int i=0; i < 20; i++)
        cout << "f(" << i << ") = " << fibo(i) << endl;

    matrix a = {{1,2},{3,4}};
    matrix b = {{1,2},{3,4}};
    matrix c = {{1,2},{3,3}};
}