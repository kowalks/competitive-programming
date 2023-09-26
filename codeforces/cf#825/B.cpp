#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b,a);
    if (b == 0) return a;

    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n+1);

    for (int i=0; i < n; i++)
        cin >> a[i];
    
    b[0] = a[0];
    b[n] = a[n-1];
    for (int i=1; i < n; i++)
        b[i] = lcm(a[i], a[i-1]);

    for (int i=0; i < n; i++)
        if (gcd(b[i], b[i+1]) != a[i]) {
            cout << "NO" << endl;
            return;
        } 
    cout << "YES" << endl;
}

int main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}