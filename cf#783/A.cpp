#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int resp;
    if (n > m) swap(n,m);
    if (n==1 && m > 2) resp = -1;
    else {
        resp = 2*n - 2;
        if (m > n) {
            resp++;
            resp += 2*(m-n-1) + (m-n-1)%2;
        }
    }
    cout << resp << endl;
}

int main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}

// 0000000000
// 0000000000
// 0000000000
// 0000000000
// 0000003478

//      01234
     