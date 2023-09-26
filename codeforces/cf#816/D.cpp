// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define int long long

using namespace std;


int32_t main (){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    priority_queue< pair<int, pair<int, int> > > a;
    for (int k=0; k <q; k++){
        v[k]=0;
        int i, j, x;
        cin >> i >> j >> x;
        if (i > j) swap(i, j);

        if (i == j)
            v[k] = x;
        else 
        a.push(make_pair(-j, make_pair(-i, x)));
        a.push(make_pair(-j, make_pair(-i, x)));
    }

    while (!a.empty()) {
        auto k = a.top();
        int i = -k.first;
        int j = -k.second.first;
        int x = -k.second.second;

        if (i -)
    }
}