#pragma once
#include<bits/stdc++.h>
using namespace std;
// op(op(a, b), b) = op(a, b) が成り立つ必要がある(冪等性)
template<class T, auto op>
struct sparsetable {
    int n;
    vector<vector<T>> data;
    sparsetable() = default;
    // sparsetable を構築 O(n log n)
    sparsetable(const vector<T>& v) : n(v.size()) {
        int m = 1;
        while (m < n) m <<= 1;
        data.assign(m, vector<T>(__lg(m)+1));
        for (int i=0; i<n; i++) data[i][0] = v[i];
        for (int j=1; j<=__lg(m); j++) {
            for (int i=0; i+(1<<j)<=n; i++) {
                data[i][j] = op(data[i][j-1], data[i+(1<<(j-1))][j-1]);
            }
        }
    }
    // op([l, r)) の値を取得 O(1)
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return T{};
        int j = __lg(r-l);
        return op(data[l][j], data[r-(1 << j)][j]);
    }
};