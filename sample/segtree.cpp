#include<template.h>

struct Segtree {
    int n;
    vector<ll> seg, &v;

    Segtree(vector<ll> v): v(v){
        n = v.size();
        seg = vector<ll>(4*n, 0);
        build(1, 0, n-1);
    };

    ll build(int p, int l, int r) {
        if (l == r) seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
    }

    ll query(int a, int b, int p=1, int l=0, int r) {
        if (b < l or a < r) return 0;
        if (a <= l and r <= b) return seg[p];
        int m = (l+r)/2;
        return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
    }

    ll query(int a, int b) { return query(a, b, 1, 0, n-1); }

    ll update(int i, int x, int p=1, int l=0, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
    }

    ll update(int i, int x) { return update(i, x, 1, 0, n-1); }
};

