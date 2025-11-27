#pragma once
#include <bits/stdc++.h>
using namespace std;

// op は結合律かつ冪等性（op(x,x)=x）を満たすこと
template<class T, auto op>
struct sparsetable {
    int n, k;
    vector<vector<T>> data;
    sparsetable() = default;
    // sparsetable を構築 O(n log n)
    sparsetable(const vector<T>& v) : n((int)v.size()) {
        if (n == 0) { k = 0; return; }
        k = __lg(n);
        data.assign(n, vector<T>(k + 1));
        for (int i=0; i<n; i++) data[i][0] = v[i];
        for (int j=1; j<=k; j++) {
            int len = 1<<j;
            for (int i=0; i+len<=n; i++) {
                data[i][j] = op(data[i][j-1], data[i+(1<<(j-1))][j-1]);
            }
        }
    }
    //op([l, r)) を求める O(1)
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return T{};
        int j = __lg(r - l);
        return op(data[l][j], data[r - (1 << j)][j]);
    }
};
