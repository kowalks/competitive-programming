#include<bits/stdc++.h>

using namespace std;

int main () {
    int a, b;
    cin >> a >> b;

    if (a != 1) {
        cout << "*" << endl;
        return 0;
    }

    int i=1;
    int cur=1;

    int k = b;
    while (k > 2) {
        k/=2;
        i*=2;
    }

    while (cur != b) {
        cout << "1 " << cur << endl;
        cout << "1 " << cur << endl;
        cur *= 2;

        if ((b & i) != 0) {
            cout << "1 1" << endl;
            cout << "1 " << cur << endl;
            cur += 1;
        }
        // if (i > 1000)
        //     return 0;
        i /= 2;


        // cout << "i=" << i << " cur=" << cur << endl;
    }
}