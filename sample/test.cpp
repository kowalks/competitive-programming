#include "template.h"

void print(vi a) {
    for (auto ele : a)
        cout << ele << " "; cout << endl;
}

int32_t main () {
    vi a = {2, 3, 5, 8};
    print(a);
    adjacent_difference(a.begin(), a.end(), a.begin());
    print(a);
    partial_sum(a.begin(), a.end(), a.begin());
    print(a);
}