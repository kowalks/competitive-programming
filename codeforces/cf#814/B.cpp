// #include<bits/stdc++.h>
#include <iostream>
// #define int long long

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;

    if (k%2 == 1) {
        cout << "YES" << endl;
        for (int i = 1; i < n; i+=2) {
            cout << i << " " << i+1 << endl;
        }
    } else if (n%4 == 0 && k%4 == 2) {
        cout << "YES" << endl;
        for (int i = 1; i < n; i+=4) {
            cout << i+1 << " " << i << endl;
            cout << i+2 << " " << i+3 << endl;
        }
    } else if (n%4 == 2 && k%4 == 2) {
        cout << "YES" << endl;
        for (int i = 1; i < n-4; i+=4) {
            cout << i+1 << " " << i << endl;
            cout << i+2 << " " << i+3 << endl;
        }
        cout << n << " " << n-1 << endl;
    } else
        cout << "NO" << endl;
}

int main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}