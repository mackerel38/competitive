#pragma once
#include<bits/stdc++.h>
using namespace std;
// op(op(a, b), c) = op(a, op(b, c)) が成り立つ必要がある(結合律)
template<class S, auto op, auto e>
struct dynamicsegtree {
    long long _n, size;
    unordered_map<long long, S> data;
    dynamicsegtree() = default;
    // 大きさn, 単位元e(省略するとS{} になる) のセグ木を構築 O(log n)
    dynamicsegtree(long long n) : _n(n) {
        size = 1;
        while (size < _n) size <<= 1;
    }
    // p 番目の要素をx にする O(log n)
    void set(long long p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        data[p] = x;
        for (p>>=1; 0<p; p>>=1) update(p);
    }
    // p 番目の要素を取得する O(1)
    S get(long long p) {
        assert(0 <= p && p < _n);
        return data[size+p];
    }
    // p 番目の要素を取得する O(1)
    S operator[](long long p) {
        return get(p);
    }
    // [l, r) の区間クエリに答える O(log n)
    S prod(long long l, long long r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, data.count(l) ? data[l] : e()), ++l;
            if (r & 1) --r, smr = op(data.count(r) ? data[r] : e(), smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    // [0, _n) のクエリに答える O(1)
    S all_prod() {
        return data[1];
    }
    void update(long long p) {
        S l = e(), r = e();
        if (data.count(2*p)) l = data[2*p];
        if (data.count(2*p+1)) r = data[2*p+1];
        data[p] = op(l, r);
    }
};
