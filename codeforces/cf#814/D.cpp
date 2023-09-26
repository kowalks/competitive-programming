// #include<bits/stdc++.h>
#include <iostream>
// #include <deque>
#include <vector>
// #include <utility>
#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> fg(n+1), op(n+1);
    for (int i=0; i < n; i++)
        cin >> a[i];

    for (int l=0; l < 32; l++) {
        for (int i=0; i < n-1; i++)
            if (a[i] % 2 != a[i+1] % 2)
                fg[i] = 1;
        for (int i=0; i < n; i++)
            if (a[i] %2 == 1)
                op[i] = 1;

        for (int i=0; i < n; i++) {
            a[i] /= 2;
        }
    }

    int cnt = 0; int i=0;
    while (i < n) {
        if (op[i] == 1) {
            cnt++;
            if (fg[i] == 1) {
                i++;
            } else {
                i+=2;
            }
        } else
            i++;
    }
        
    cout << cnt << endl;
}

int32_t main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}