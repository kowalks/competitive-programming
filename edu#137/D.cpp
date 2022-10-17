#include <bits/stdc++.h>
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve(){
    int n; cin >> n;
    vector<char> a(n);
    for (int i=0; i < n; i++)
        cin >> a[i];
    
    int ptr = 0;
    while (ptr < n && a[ptr] == '0') ptr++;
    while (ptr < n && a[ptr] != '0') ptr++;
    // a[ptr] = primeiro 0

    int master = 0;
    int pmaster = 0;
    if (ptr < n) {
        // cout << "ptr: " << ptr << endl;
        for (int ptr2=0; ptr2 <= ptr; ptr2++) {
            // cout << "ptr2: " << ptr2 << endl;
            int i = ptr2;
            int j = ptr;
            int cnt = 0;
            while (j < n && i < n) {
                while (j < n && i < n && a[j] == '1') {
                    j++;
                    i++;
                }
                if (j < n && i < n && a[j] == '0' && a[i] == '1')
                    cnt++;
                else
                    break;
                j++;
                i++;
            }
            if (cnt > master) {
                master = cnt;
                pmaster = ptr2;
            } else if (cnt == master) {
                int i = ptr2;
                int j = ptr;
                int k = pmaster;
                while (i < n && j < n && k < n) {
                    while (j < n && i < n && k < n && a[j] == '1') {
                        j++;
                        i++;
                        k++;
                    }
                    if (j < n && i < n && k < n && a[i] == '1' && a[k] == '0') {
                        pmaster = ptr2;
                        break;
                    } else if (j < n && i < n && k < n && a[i] == '0' && a[k] == '1')
                        break;
                    j++; i++; k++;
                }
            }
        }
    }
    // cout << master << endl;
    if (master == 0) {
        int i = 0;
        while (i < n && a[i] == '0') i++;

        if (i == n) {
            cout << 0;
        }
        else {
            while (i < n) {
                cout << a[i];
                i++;
            }
        }
    } else {
        int i = 0;
        while (i < n && a[i] == '0') i++;
        for (; i < ptr; i++)
            cout << a[i];
        for (int i=ptr, j=pmaster; i < n; i++,j++)
            if (a[i] == '1' || a[j] == '1')
                cout << '1';
            else cout << '0';
    }
    cout << endl;
}

int32_t main () {
    solve();
}