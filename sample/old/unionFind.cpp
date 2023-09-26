#include<bits/stdc++.h>

using namespace std;

vector<int> e;

void init(int N) { e = vector<int>(N, -1); }

int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

bool same_set(int x, int y) { return get(x) == get(y); }

int size(int x) { return -e[get(x)]; }

bool join(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x,y);
    e[x] += e[y]; e[y] = x;
    return true;
}

int main () {
    int N = 10;
    init(N);

    cout << get(1) << " " << get(2) << endl;
    join(1,2);
    cout << get(1) << " " << get(2) << endl;
    join(3,4);
    join(4,5);
    cout << get(3) << " " << get(4) << " " << get(5) << endl;
    join(1,3);
    cout << get(3) << " " << get(4) << " " << get(5) << endl;
}
