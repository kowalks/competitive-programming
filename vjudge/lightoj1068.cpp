#include <bits/stdc++.h>
#define int long long
using namespace std;


// [pos] [div?] [smaller?]
int dp[12][2][2];
vector<int> num;

int call(int pos, int div, int smaller) {
    if (pos == num.size()) {
        if 
    }
}

int solve(int b) {
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (b>0) {
        num.push_back(b%10);
        b /= 10;
    }
    reverse(num.begin(), num.end());

    return call(0,0,0);
}


void test(int t) {
    int a, b, k;
    cin >> a >> b >> k;
    int resp = solve(b) - solve(a-1);
    cout << "Case " << t << ": "<< resp << endl;

}

int32_t main () {
    int t;
    cin >> t;
    for (int i=1; i <= t; i++)
        test(i);
}