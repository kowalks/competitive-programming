#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef vector<int> vi;

vi vec;

bool find(int k, int l, int r) {
    if (l > r)
        return false;

    int m = (l+r)/2;
    if (vec[m] == k)
        return true;
    
    if (vec[m] > k)
        return find(k, l, m-1);
    
    return find(k, m+1, r);
}

void solve(int n){
    int k; cin >> k;
    if (find(k, 0, n-1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main () { _
    int n, k; cin >> n >> k;
    vec = vi(n); for (auto& v : vec) cin >> v;

    while(k--)
        solve(n);
}