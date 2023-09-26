#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    // for (int i=0; i < a.size(); i++)
    //     cout << a[i] << " ";

    
    int i=0; int j = a.size() - k;
    long long sum = 0;
    for (int k=i; k < j; k++)
        sum += a[k];

    auto best_sum = sum;
    // cout << "sum " << sum << endl;
    while (j < a.size()) {
        sum -= a[i] + a[i+1];
        sum += a[j];
        i+=2;
        j+=1;
        if (best_sum < sum)
            best_sum = sum;
        // cout << endl << i << " " << j << " " << sum << endl;
    }
    
    
    cout << best_sum << endl;

}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}