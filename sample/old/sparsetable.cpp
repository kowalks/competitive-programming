#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> st;
const int K = 25;

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
    int res = 0;
    for (int j = K-1; j >=0; j--)
        if ((1<<j) <= b-a+1)
            res = f(res, st[a][j]), a += (1<<j);

    return res;
}

int sum (int a, int b) { return a+b; }
int max (int a, int b) { return (a > b) ? a : b; }

int32_t main () {
    vector<int> v = {0,1,1,2,0,4,5,2,1};
    init(v, sum);
    cout << (query(2,6,sum)) << endl;

    init(v, max);
    cout << (query(2,6,max)) << endl;
}