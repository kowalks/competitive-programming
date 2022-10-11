#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    int cntA = 0;
    int cntB = 0;
    int posdif = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            cntA++;
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 1)
            cntB ++;
        if (a[i] != b[i])
            posdif++;

    }

    if (posdif == 0)
        cout << 0 << endl;
    else if (cntA == cntB)
        cout << 1 << endl;
    else
        cout << min(abs(cntA-cntB) + 1, posdif) << endl;
}

int main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}