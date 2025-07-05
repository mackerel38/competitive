#pragma once
#include <bits/stdc++.h>
#include "isqrt"
using namespace std;

template <class S, auto op, auto e, class F, auto mapping, auto mapping2>
struct sqrttree {
    int n, bsize, m;
    vector<S> data, block;
    sqrttree() = default;
    sqrttree(int n) : sqrttree(vector<S>(n, e())) {}
    sqrttree(vector<S> v) {
        n = v.size();
        bsize = isqrt(n) + 1;
        m = bsize * bsize;
        data.reserve(m);
        block.reserve(bsize);
        for (int i=0; i<bsize; i++) {
            block[i] = e();
            for (int j=0; j<bsize; j++) {
                int k = i * bsize + j;
                if (k < n) {
                    data[k] = v[k];
                } else {
                    data[k] = e();
                }
                block[i] = op(block[i], data[k]);
            }
        }
    }
    void apply(int i, F f) {
        assert(0<=i && i<n);
        data[i] = mapping(f, data[i]);
        block[i/bsize] = mapping2(f, block[i/bsize]);
    }
    S get(int i) {
        assert(0 <= i && i < n);
        return data[i];
    }
    S operator[](int i) {
        return get(i);
    }
    S prod(int l, int r) {
        assert(0<=l && l<=r && r<=n);
        S re = e();
        for (int i=0; i<bsize; i++) {
            if (r<=i*bsize || (i+1)*bsize<=l) continue;
            if (l<=i*bsize && (i+1)*bsize<=r) re = op(re, block[i]);
            else {
                for (int j=0; j<bsize; j++) {
                    int k = i * bsize + j;
                    if (l<=k && k<r) {
                        re = op(re, data[k]);
                    }
                }
            }
        }
        return re;
    }
};
