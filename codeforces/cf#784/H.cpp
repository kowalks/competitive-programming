#include<bits/stdc++.h>
#define INF 4294967295
using namespace std;

void solve() {
    int n, k, rsp=INF;
    cin >> n >> k;
    vector<int> a(n);
    int b[50] = {0};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rsp = rsp & a[i];
        for (int j = 0; j < 31; j++)
            if (a[i] != (a[i] | (1 << j)))
                b[j]++;
    }

    // for (int i=0; i <=30; i++)
    //     cout << b[i] << " ";
    // cout << endl;

    for (int j=30; j >=0; j--) {
        if (k > 0 && b[j] <= k) {
            // cout << "* " << rsp << " * ";
            rsp = rsp | (1 << j);
            // cout << "* " << rsp << " * ";
            k -= b[j];
        }
    }

    cout << rsp << endl;
}

int32_t main () {
    // cout << (((4 & 6) & 28) & 12) << endl;
    int t;
    cin >> t;
    while(t--)
        solve();
}
