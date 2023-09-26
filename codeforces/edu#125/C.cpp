#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    // cout << "@" + s + "@" << endl;

    int ptr = 0, c=0, r=n;
    while (ptr < n) {
        if (s[ptr] == '(' && ptr+1 < n) {
            ptr+=2;
            c++;
            r -=2;
        } else if (s[ptr] == ')') {
            ptr++;
            while(s[ptr] != ')' && ptr < n)
                ptr++;
            if (s[ptr] == ')') {
                ptr++;
                c++;
                r = n-ptr;
            }
                
        } else break;
        // cout << "ptr " << ptr << endl;
    }

    cout << c << " " << r << endl;   
}

int32_t main () {
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        solve();
    }
}