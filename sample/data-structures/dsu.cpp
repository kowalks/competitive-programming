#include "template.h"

struct DSU {
    vi p, r, s, v;
    
    DSU(int n) {
        p = vi(n+1); iota(p.begin(), p.end(), 0);
        r = vi(n+1, 0);     // rank: distance to leaves
        v = vi(n+1, 0);     // value: marginal value
        s = vi(n+1, 1);     // size: size for reps
    }

    int get_(int a) { return p[a] = (p[a] == a ? a : get(p[a])); }

    int get(int a) {                // get parent with path-compression
        if (p[a] == a)
            return a;
        int rep = get(p[a]);
        if (p[p[a]] != p[a])
            v[a] += v[p[a]];
        return p[a] = rep;
    }

    bool join(int a, int b) {       // return true if they could join
        a = get(a); b = get(b);
        if (a == b)
            return false;
        
        if (r[a] == r[b])
            r[a]++;
        if (r[a] < r[b])
            swap(a, b);
        
        s[a] += s[b];
        p[b] = a;
        v[b] -= v[a];
        return true;
    }

    void add(int a, int val) { v[get(a)] += val; }

    bool size(int a) { return s[get(a)]; }

    bool same(int a, int b) { return get(a) == get(b); }

    int value(int a) { int b = get(a); return v[a] + (a != b ? v[b] : 0); }
};
