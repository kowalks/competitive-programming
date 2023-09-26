// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

void solve(){
    int n,k,b,s;
    cin >> n >> k >> b >> s;

    int a = b*k;

    if (s < a) {
        cout << -1 << endl;
        return;
    } else if (a + (k-1)*n < s) {
        cout << -1 << endl;
        return;
    }


    int ss = 0;
    for (int i=0; i < n; i++) {
        int aa;
        aa = (i == 0) ? a : 0;

        if ( s - ss - aa < k-1) {
            cout << s - ss << " ";
            ss = s;
        } else {
            cout << aa + k-1 << " ";
            ss += aa + k-1;
        }
    }
    cout << endl;


// extremo: s/k ou (s/n)/k

}

int32_t main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}