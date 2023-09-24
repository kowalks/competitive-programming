#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef vector<int> vi;

void solve(){
    int n; cin >> n;
    vi s(n), e(n);
    for (int i=0; i < n; i++) 
        cin >> s[i] >> e[i];
    
    int w = s[0];
    int winner = 0;
    for (int i=0; i < n; i++) {
        if (s[i] >= w && e[i] >= e[winner])
            winner = i;
    }

    if (winner == 0)
        cout << w << endl;
    else
        cout << -1 << endl;
}

int32_t main () { _
    int t; cin >> t;
    while(t--)
        solve();
}