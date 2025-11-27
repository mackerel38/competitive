#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct BIT {
    int _n;
    vector<T> data;
    BIT() = default;
    // BIT を構築 O(n)
    BIT(int n) : _n(n), data(_n, T{}) {}
    // BIT を構築 O(n)
    BIT(vector<T>& v) : _n((int)v.size()), data(v) {
        for (int i=1; i<=_n; i++) {
            int j = i+(i&-i);
            if (j <= _n) data[j-1] += data[i-1];
        }
    }
    // p 番目の値にx を加算する O(log n)
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        int i = p + 1;
        while (i <= _n) {
            data[i-1] += x;
            i += i & -i;
        }
    }
    // p 番目の値をx にする O(log n)
    void set(int p, T x) { add(p, x - get(p)); }
    // [0, r) の総和を求める O(log n)
    T sum(int r) const {
        assert(0 <= r && r <= _n);
        T re = T{};
        int i = r;
        while (i > 0) {
            re += data[i-1];
            i -= i & -i;
        }
        return re;
    }
    // [l, r) の総和を求める O(log n)
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }
    // p 番目の値を取得する O(log n)
    T get(int p) const { return sum(p+1) - sum(p); }
    // p 番目の値を取得する O(log n)
    T operator[](int p) const { return get(p); }
};
