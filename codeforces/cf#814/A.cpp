// #include<bits/stdc++.h>
#include <iostream>
// #define int long long

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    if ((m%2 == 0) && (n%2 == 1) || (n%2 == 0) && (m%2 == 1)) {
        cout << "Burenka" << endl;
    } else {
        cout << "Tonya" << endl;
    }
}

int main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}