#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > a(n+1, vector<char>(m+1));
    string s;

    {
        for (int j = 0; j <= m; j++)
            a[0][j] = '.';
        for (int i = 0; i <= n; i++)
            a[i][0] = '.';

        for (int i = 1; i <= n; i++){
            cin >> s;
            for (int j = 1; j <= m; j++)
                a[i][j] = s[j-1];
        }
    }

    {
        for (int j = 1; j <= m; j++) {
            int k = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i][j] == '*') {
                    if (a[k][j] == '*')
                        continue;
                    k=i;
                }
                else if (a[i][j] == '.') {
                    if (a[k][j] == '*')
                        swap(a[k][j], a[i][j]);
                        k++;
                }
                else {
                    k=i;
                }
            }
        }
    }



    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << endl;
    }

}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
