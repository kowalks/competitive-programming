#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3F3F3F3F;
const ll LINF = 0x3F3F3F3F3F3F3F3FLL;
const int MAXN = 100005;

ll bit[MAXN];

void update(int pos, int val) {
    while (pos < MAXN) {
        bit[pos] += val;
        pos += pos&-pos;
    }
}

ll query(int pos) {
    ll val = 0;
    while (pos > 0) {
        val += bit[pos];
        pos -= pos&-pos;
    }
    return val;
}

ll query(int a, int b) {
    return query(b) - query(a-1);
}

int32_t main () {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        int p; cin >> p;
        ll resp = query(p, n);
        update(p, 1);
        cout << resp << " ";
    }
    cout << endl;
}