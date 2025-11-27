#pragma once
#include<bits/stdc++.h>
using namespace std;

template<class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct lazysegtree {
    int _n, size, sz;
    vector<S> data;
    vector<F> lazy;
    lazysegtree() = default;
    // 大きさn のセグ木を構築 O(n)
    lazysegtree(int n) : _n(n) { build(vector<S>(n, e())); }
    // 大きさv.size() のセグ木を構築 O(n)
    lazysegtree(vector<S>& v) : _n((int)v.size()) { build(v); }
    void build(vector<S> v) {
        size = __bit_ceil((unsigned int)_n);
        sz = __countr_zero(size);
        data.assign(2 * size, e());
        lazy.assign(2 * size, id());
        for (int i=0; i<_n; i++) data[size+i] = v[i];
        for (int i=size-1; 0<i; i--) update(i);
    }
    void update(int k) { data[k] = op(data[2*k], data[2*k+1]); }
    void all_apply(int k, F f) {
        data[k] = mapping(f, data[k]);
        if (k < size) lazy[k] = composition(f, lazy[k]);
    }
    void push(int k) {
        all_apply(2*k, lazy[k]);
        all_apply(2*k+1, lazy[k]);
        lazy[k] = id();
    }
    // p 番目の要素をx にする O(log n)
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i=sz; 0<i; i--) push(p >> i);
        data[p] = x;
        for (int i=p>>1; 0<i; i>>=1) update(i);
    }
    // p 番目の要素を取得する O(log n)
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i=sz; 0<i; i--) push(p >> i);
        return data[p];
    }
    // p 番目の要素を取得する O(log n)
    S operator[](int p) { return get(p); }
    // [l, r) の区間クエリに答える O(log n)
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        l += size;
        r += size;
        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >> i);
        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1) >> i);
        S ll = e(), rr = e();
        while (l < r) {
            if (l & 1) ll = op(ll, data[l++]);
            if (r & 1) rr = op(data[--r], rr);
            l >>= 1;
            r >>= 1;
        }
        return op(ll, rr);
    }
    // [0, n) のクエリに答える O(1)
    S all_prod() const { return data[1]; }
    // [0, n) の区間の値を取得する O(n)
    vector<S> values() {
        vector<S> re(_n);
        for (int i=0; i<size; i++) if (lazy[i] != id()) push(i);
        for (int i=0; i<_n; i++) re[i] = data[size+i];
        return re;
    }
    // [l, r) に対して f を適用する O(log n)
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >> i);
        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1) >> i);
        int ll = l, rr = r;
        while (ll < rr) {
            if (ll & 1) all_apply(ll++, f);
            if (rr & 1) all_apply(--rr, f);
            ll >>= 1;
            rr >>= 1;
        }
        for (int i=1; i<=sz; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
    // f(op([l, r)))==true となる最大のr を返す
    template<class G>
    int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i=sz; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, data[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, data[l]))) {
                        sm = op(sm, data[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, data[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    // f(op([l, r)))==true となる最小のl を返す
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i=sz; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(data[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(data[r], sm))) {
                        sm = op(data[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};