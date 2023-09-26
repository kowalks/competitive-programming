#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int r, b, n;
    cin >> n >> r >> b;
    int bl = r/(b+1);
    int num_bl = r - (b+1)*bl;

    for (int i = 0; i < num_bl; i++) {
        for (int j = 0; j < bl+1; j++)
            cout << "R";
        cout << "B";
    }

    for (int i = 0; i < (b+1) - num_bl - 1; i++) {
        for (int j = 0; j < bl; j++)
            cout << "R";
        cout << "B";
    }

    for (int j = 0; j < bl; j++)
        cout << "R";


    // while(b > 0 || r > 0) {
    //     for (int i = 0; i < bl; i++) {
    //         if (r > 0) {
    //             cout << "R";
    //             r--;
    //         }
    //     }
    //     if (b>0){
    //         cout << "B";
    //         b--;
    //     }
    // }
    cout << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}