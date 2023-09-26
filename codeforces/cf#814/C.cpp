// #include<bits/stdc++.h>
#include <iostream>
#include <deque>
#include <vector>
#include <utility>
// #define int long long

using namespace std;

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
    return a.second.second < b.second.second;
}

void solve(){
    int n, q, a, i, k;
    cin >> n >> q;
    deque<int> d;
    for (int i=0; i < n; i++){
        cin >> a;
        d.push_back(a);
    }

    vector< pair <int, pair<int, int> > > query;
    for (int l=0; l<q; l++) {
        cin >> i >> k;
        // cout << "participante " << d[i-1] << endl;
        query.push_back(make_pair(l, make_pair(d[i-1], k)));
    }
    sort(query.begin(), query.end(), comp);

    vector<int> c(n+1);
    vector<int> resp(q+1);
    int cnt = 0;
    int ptr = 0;

    while (d.front() != n) {
        cnt ++;

        int a1 = d.front();
        d.pop_front();
        int a2 = d.front();
        if (a2 > a1) {
            d.push_back(a1);
            c[a2]++;
        } else {
            c[a1]++;
            d.pop_front();
            d.push_front(a1);
            d.push_back(a2);
        }

        while (ptr < q && query[ptr].second.second == cnt) {
            resp[query[ptr].first] = c[query[ptr].second.first];
            ptr++;
        }
    }

    // cout << "ptr: " << ptr << "  cnt: " << cnt << endl;

    // for (int i=1; i <= n; i++)
    //     cout << c[i] << " ";
    // cout <<endl;

    while (ptr < q) {
        if (query[ptr].second.first == n) {
            // cout << "eu" << endl;
            // cout << c[query[ptr].second.first] <<  query[ptr].second.second << cnt << query[ptr].first << endl;
            resp[query[ptr].first] = c[query[ptr].second.first] + query[ptr].second.second - cnt;
        } else
            resp[query[ptr].first] = c[query[ptr].second.first];
        ptr++;
    }

    for (int i=0; i < q; i++)
        cout << resp[i] << endl;

}

int main (){
    int t;
    cin >> t;
    while(t--)
        solve();
}