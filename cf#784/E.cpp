#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt=0;
    cin >> n;
    vector<string> s(n);
    for (int i=0; i < n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());
    for (int i=0, k=0; i < n;) {
        int c = 0;
        int q=i;
        while(i < n && s[i][0] == s[k][0]){
            int c2=0;
            while(i < n && s[i][0] == s[k][0] && s[i][1] == s[q][1]) {
                c2+= c2+1;
                i++;
                c++;
            }
            cnt -= c2;
            q = i;
        }
        cnt += c*(c+1)/2;
        k = i;
    }

    // cout << cnt << endl;
    for (int i=0; i < n; i++)
        swap(s[i][0], s[i][1]);
    sort(s.begin(), s.end());
    // for (int i=0; i < n; i++) cout << s[i] << endl;

    for (int i=0, k=0; i < n;) {
        int c = 0;
        int q=i;
        while(i < n && s[i][0] == s[k][0]){
            int c2=0;
            while(i < n && s[i][0] == s[k][0] && s[i][1] == s[q][1]) {
                c2+= c2+1;
                i++;
                c++;
            }
            cnt -= c2;
            q = i;
        }
        cnt += c*(c+1)/2;
        k = i;
    }

    cout << cnt << endl;
}

int32_t main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
