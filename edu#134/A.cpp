#include<bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

void solve() {
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    int ca = (a == b) + (a == c) + (a == d);
    int cb = (b == a) + (b == c) + (b == d);
    int cc = (c == b) + (c == a) + (c == d);
    int cd = (d == b) + (d == c) + (d == a);

    int maximo = max(max(max(ca, cb), cc), cd);
    int minimo = min(min(min(ca, cb), cc), cd);

    int resp;
    if (maximo == 3) 
        resp = 0;
    if (maximo == 2)
        resp = 1;
    if (maximo == 1 && minimo == 1)
        resp = 1;
    if (maximo == 1 && minimo == 0)
        resp = 2;
    if (maximo == 0)
        resp = 3;

    cout << resp << endl;

}

int32_t main (){
    int t;
    cin >> t;
    while(t--)
        solve();
    // solve()
}