#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int prev = 0, resp=0;
        for (int j = i+1; j < n; j++) {
            int k = prev/a[j] + 1;
            resp += k;
            prev = k*a[j];
        }
        prev = 0;
        for (int j = i-1; j >=0; j--) {
            int k = prev/a[j] + 1;
            resp += k;
            prev = k*a[j];
        }
        if (ans == -1)
            ans = resp;
        ans = min(ans, resp);
    }

    cout << ans << endl;
}