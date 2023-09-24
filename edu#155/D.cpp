#include<bits/stdc++.h>
#define mult(a, b) (((a)*(b))%998244353ll)
#define sum(a, b) (((a)+(b))%998244353ll)

using namespace std;
typedef vector<long long> vi;
typedef long long ll;

int32_t main () {
    int n; cin >> n;
    vi a(n); for (auto& aa : a) cin >> aa;
    vi s(n+1);

    s[0] = 0;
    for (int i=1; i <= n; i++)
        s[i] = s[i-1] ^ a[i-1];
    
    ll ans = 0ll;
    for (int i=0; i < n; i++)
        for (int j=i+1; j <= n; j++)
            ans = sum(ans, mult(j-i, s[j]^s[i]));

    cout << ans << endl;
}