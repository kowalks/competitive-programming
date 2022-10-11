#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> st;
const int K = 25;
const int START = INT_MAX;

void init(vector<int> v, int f(int,int)) {
    int N = v.size();
    st = vector<vector<int>>(N, vector<int>(K));

    for(int i=0; i<N; i++)
        st[i][0] = v[i];

    for(int j=1; j<K; j++)
        for(int i=0; i + (1 << j) <= N; i++)
            st[i][j] = f(st[i][j-1], st[i + (1<<(j-1))][j-1]);
}

int query(int a, int b, int f(int,int)) { // len = b-a+1
    int res = START;
    for (int j = K-1; j >=0; j--)
        if ((1<<j) <= b-a+1)
            res = f(res, st[a][j]), a += (1<<j);

    return res;
}

int min (int a, int b) { return (a < b) ? a : b; }

int32_t main () {
    int N; cin >> N;
    vector<int> a(N);
    for (int i=0; i < N; i++)
        cin >> a[i];

    init(a, min);
    
    int Q; cin >> Q;
    for (int i=0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        cout << query(x,y,min) << endl;
    }
}