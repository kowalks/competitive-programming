#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define int long long

using namespace std;


int32_t main (){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    int s = 1;
    int d = 1;
    for (int i=1; i < n; i++) {
        if (a[i] == a[i-1])
            d += 1;
        else
            d = d + i + 1;
        s += d;
    }

    // cout << s << endl;

    for (int k=0; k < m; k++) {
        int i, x;
        cin >> i >> x;

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        i = i-1;

        if (i == 0) {
            if (a[0] != x) {
                if (a[0] == a[1]) {
                    s += n-1;
                } else if (x == a[1]) {
                    s -= n-1;
                }
            }
        }

        else if (i == n-1) {
            if (a[n-1] != x) {
                if (a[n-1] == a[n-2]) {
                    s += n-1;
                } else if (x == a[n-2]) {
                    s -= n-1;
                }
            }
        }

        else {
            int l = a[i-1];
            int r = a[i+1];
            if (x != a[i]) {
                if (l == x) {
                    s -= i;
                } else if (l == a[i]) {
                    s += i;
                }
                
                if (r == x) {
                    s -= n-i-1;
                } else if (r == a[i]) {
                    s += n-i-1;
                }

                int d = 0;
                if (l == a[i]) d++;
                if (l == x) d--;
                if (r == a[i]) d++;
                if (r == x) d--;
                // cout << "d " << d << endl;
                s += d*(n-i-1)*i;
            }
        }
        
        
        cout << s << endl;
        a[i] = x;
    }
}