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
const int MAX = 100005;

void solve(){
    int n; cin >> n;
    vii l(n);

    for (int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        l[i] = {a, b};
    }
    
    sort(l.begin(), l.end());

    int ptr = 0;
    ll resp = 0;
    while (ptr < n) {
        auto [a, b] = l[ptr];
        int ptr2 = ptr;
        while (l[ptr2].f == a and ptr2 < n) ptr2++;
        ptr2--;
        if (ptr2-ptr + 1 <= a) {
            for (int i=ptr; i <= ptr2; i++)
                resp += l[i].s;
        } else {
            for (int i=ptr2, c = 0; c < a; c++)
                resp += l[i--].s;
        }
        ptr = ptr2 + 1;
    }

    cout << resp << endl;
}

int32_t main () {
    int t; cin >> t;
    while(t--)
        solve();
}