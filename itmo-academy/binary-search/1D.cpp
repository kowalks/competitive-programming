#include<bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef vector<int> vi;

vi vec;

int findl(int k, int l, int r) {
    if (r == l+1) 
        return (vec[r] <= k) ? r : l;
    
    int m = (l+r)/2;
    if (vec[m] <= k)
        return findl(k, m, r);
    return findl(k, l, m);
}

int findr(int k, int l, int r) {
    if (r == l+1)
        return (vec[l] >= k) ? l : r;

    int m = (l+r)/2;
    if (vec[m] >= k)
        return findr(k, l, m);
    return findr(k, m, r);
}

int32_t main () { _
    int n; cin >> n;
    vec = vi(n+2); vec[0] = -INT_MAX; vec[n+1] = INT_MAX;
    for (int i=1; i <= n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int k; cin >> k;
    while(k--) {
        int l, r; cin >> l >> r;
        int idxl = findr(l, 0, n+1);
        int idxr = findl(r, 0, n+1);
        cout << idxr - idxl + 1 << endl;
    }
}