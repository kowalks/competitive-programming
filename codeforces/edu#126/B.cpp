#include <bits/stdc++.h>
#define MOD 32768

using namespace std;

int ans[MOD+5];

void solve() { 
    queue< int > fila;

    ans[0] = 0;
    fila.push(0);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        int alt = (MOD + u - 1)%MOD;
        if (ans[alt] == -1) {
            ans[alt] = ans[u] + 1;
            fila.push(alt);
        }
        if (u % 2 == 0) {
            alt = u/2;
            if (ans[alt] == -1) {
                ans[alt] = ans[u] + 1;
                fila.push(alt);
            }
            alt = ((MOD + u)/2 )%MOD;
            if (ans[alt] == -1) {
                ans[alt] = ans[u] + 1;
                fila.push(alt);
            }
        }
    }
}


int main () {
    int n, k;
    cin >> n;

    memset(ans, -1, sizeof(ans));
    solve();

    while (n--) {
        cin >> k;
        cout << ans[k] << endl;
    }
}