#pragma once
#include<bits/stdc++.h>
using namespace std;
// op(op(a, b), c) = op(a, op(b, c)) が成り立つ必要がある(結合律)
template<class S, auto op, auto e>
struct segtree {
    int _n, size;
    vector<S> data;
    segtree() = default;
    // 大きさn のセグ木を構築 O(n)
    exolicit segtree(int n) : _n(n) { build(vector<S>(n, e())); }
    // 大きさv.size() のセグ木を構築 O(n)
    explicit segtree(const vector<S>& v) : _n(v.size()) { build(v); }
    void build(const vector<S>& v) {
        size = __bit_ceil((unsigned int)_n);
        data.assign(2 * size, e());
        for (int i=0; i<_n; i++) data[size+i] = v[i];
        for (int i=size-1; 0<i; i--) update(i);
    }
    // p 番目の要素をx にする O(log n)
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        data[p] = x;
        for (p>>=1; 0<p; p>>=1) update(p);
    }
    // p 番目の要素を取得する O(1)
    S get(int p) const {
        assert(0 <= p && p < _n);
        return data[size+p];
    }
    // p 番目の要素を取得する O(1)
    S operator[](int p) const { return get(p); }
    // [l, r) の区間クエリに答える O(log n)
    S prod(int l, int r) const {
        assert(0<=l && l<=r && r<=_n);
        S ll = e(), rr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) ll = op(ll, data[l++]);
            if (r & 1) rr = op(data[--r], rr);
            l >>= 1;
            r >>= 1;
        }
        return op(ll, rr);
    }
    // [0, _n) のクエリに答える O(1)
    S all_prod() const { return data.size() > 1 ? data[1] : e(); }
    // [0, _n) の区間の値を取得する O(n)
    vector<S> values() const {
        vector<S> re(_n);
        for (int i=0; i<_n; i++) re[i] = data[size+i];
        return re;
    }
    void update(int p) { data[p] = op(data[2*p], data[2*p+1]); }
    // f(op([l, r)))=true となる最大のr を返す O(log n)
    template <class F>
    int max_right(int l, F f) const {
        assert(f(e()));
        assert(0 <= l && l <= _n);
        if (l == _n) return _n;
        int idx = l + size;
        S s = e();
        do {
            while (idx % 2 == 0) idx >>= 1;
            if (!f(op(s, data[idx]))) {
                while (idx < size) {
                    idx = idx * 2;
                    if (f(op(s, data[idx]))) s = op(s, data[idx++]);
                }
                return idx - size;
            }
            s = op(s, data[idx]);
            idx++;
        } while (idx != (idx & -idx));
        return _n;
    }
    // f(op([l, r)))=true となる最小のl を返す O(log n)
    template <class F>
    int min_left(int r, F f) const {
        assert(f(e()));
        assert(0 <= r && r <= _n);
        if (r == 0) return 0;
        int idx = r + size;
        S s = e();
        do {
            idx--;
            while (idx % 2 == 1) idx >>= 1;
            if (!f(op(data[idx], s))) {
                while (idx < size) {
                    idx = idx * 2 + 1;
                    if (f(op(data[idx], s))) s = op(data[idx--], s);
                }
                return (idx + 1) - size;
            }
            s = op(data[idx], s);
        } while(idx != (idx & -idx));
        return 0;
    }
};
