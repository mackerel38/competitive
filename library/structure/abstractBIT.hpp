#pragma once
#include<bits/stdc++.h>
using namespace std;
template <class T, auto op, auto iop>
struct abstractBIT {
    int _n;
    T _e;
    vector<T> data;
    abstractBIT() = default;
    // 抽象化BIT を構築する O(n)
    abstractBIT(int n, T e = T{}) : _n(n), data(_n), _e(e) {}
    // p 番目の値にx を加算する O(log n)
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p-1] = op(data[p-1], x);
            p += p & -p;
        }
    }
    // p 番目の値をx にする O(log n)
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        data[p] = x;
        p++;
        p += p & -p;
        while (p <= _n) {
            data[p-1] = op(data[p-1], x);
            p += p & -p;
        }
    }
    // [0, r) の総和 を求める O(log n)
    T sum(int r) {
        assert(0 <= r &&  r <= _n);
        T re = T{};
        while (0 < r) {
            re = op(re, data[r-1]);
            r -= r & -r;
        }
        return re;
    }
    // [l, r) の総xor を求める O(log n)
    T sum(int l, int r) {
        assert(l <= r);
        return iop(sum(r), sum(l));
    }
    // p 番目の値を取得する O(log n)
    T get(int p) {
        return iop(sum(p+1), sum(p));
    }
    T operator[](int p) {
        return get(p);
    }
    // 全体の総xor を取得する O(log n)
    T all_sum() {
        return sum(_n);
    }
    // [l, r) にx を加算する 一点取得はsum(p) で行う 区間和クエリができなくなるので注意O(log n)
    void imos(int l, int r, T x) {
        add(l, x);
        if (r < _n) add(r, x);
    }
};