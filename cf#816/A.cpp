#include<bits/stdc++.h>
#include <iostream>
// #define int long long

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    if (n > m) swap(n, m);
    if (m == 1)
        cout << 0 << endl;
    else if (n == 1)
        cout << m << endl;
    else
        cout << 2*n + m - 2 << endl;
    
}

int main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}