#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i = 0; i<n; i++)
        cin >> a[i];

    int ptr = 0;
    while (a[ptr] == 0 && ptr < n) {
        b[ptr] = 0;
        ptr++;
    }

    for (int i = ptr; i < n; i++) {
        if (ptr*b[ptr] + i - ptr == a[ptr]) {
            ptr++;
            b[i] = 0;
        } else {
            b[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
}

int32_t main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}