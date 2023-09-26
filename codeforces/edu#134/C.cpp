#include<bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i=0; i < n; i++)
        cin >> a[i];
    for (int i=0; i < n; i++)
        cin >> b[i];

    // min
    vector<int> mn(n);
    int ptr = 0;
    for (int i=0; i < n; i++) {
        if (b[ptr] >= a[i])
            mn[i] = b[ptr] - a[i];
        else {
            while (b[ptr] < a[i])
                ptr++;
            mn[i] = b[ptr] - a[i];
        }
    }

    for (int i=0; i < n; i++)
        cout << mn[i] << " ";
    cout << endl;

    // max
    vector<int> mx(n);
    int ptr = n-1;
    for (int i=n-1; i >=0; i--) {
        if (b[ptr] >= a[i])
            mn[i] = b[ptr] - a[i];
        else {
            while (b[ptr] < a[i])
                ptr++;
            mn[i] = b[ptr] - a[i];
        }
    }

    for (int i=0; i < n; i++)
        cout << mn[i] << " ";
    cout << endl;
}

int32_t main (){
    int t;
    cin >> t;
    while(t--)
        solve();
    // solve()
}