#include<bits/stdc++.h>
#define MAXN 300005

using namespace std;

int fd(int n; int* h) {
    int s;
    for (int i = 0; i < n; i++)
        s += h[i];
    int dois,um,dias;
    if (s%3 == 0) {
        dois = s/3;
        um = s/3;
        dias = dois + um;
    }
    if (s%3 == 1) {
        dois = s/3;
        um = s/3 + 1;
        dias = dois + um;
    }
    if (s%3 == 2) {
        dois = s/3 + 1;
        um = s/3;
        dias = dois + um;
    }

    sort(h[0], h[n]);
    while (dois > 0) {
        
    }

}

void solve() {
    int n, h[MAXN];
    cin >> n;
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] > max) max = h[i];
    }
    int k;
    for (int i = 0; i < n; i++)
        k += max - h[i];

    int ans;
    if (k%3 == 0)
        ans = k/3*2;
    else if (k%3 == 1)
        ans = k/3*2+1;
    else
        ans = k/3*2 
}


int main () {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}




// 0 0 0 0 1   6
// 1 0 0 0 1
// 1 2 0 0 1
// 2 2 0 0 1
// 2 2 2 0 1
// 2 2 2 0 2
// 2 2 2 2 2


// 0 0 0 0 1   7
// 1 0 0 0 1
// 1 0 0 0 1
// 1 1 0 0 1
// 1 1 0 0 1
// 1 1 1 0 1
// 1 1 1 0 1
// 1 1 1 1 1

// 0 3 3 3 4   2 + 6 = 8
// 1 3 3 3 4
// 3 3 3 3 4

// 0 3 3 3 4   5
// 0 3 3 4 4
// 2 3 3 4 4
// 2 3 4 4 4
// 4 3 4 4 4
// 4 4 4 4 4


// 4 1 1 1 0 -> 3x1, 2x2, 5d -> 5

// 1 1 1 1 0 -> 2x1, 1x2, 3d -> 7
// 2 2 2 2 1 -> 3x1, 3x2, 6d -> 6
