#pragma once
#include<bits/stdc++.h>
using namespace std;
struct UnionFind {
    int _n;
    vector<int> data;
    UnionFind() = default;
    // n 個の要素からなるUnionFind を構築 O(n)
    UnionFind(int n) : _n(n), data(n, -1) {}
    // 2 つの要素を併合 O(α(n))
    bool merge(int p, int q) {
        p = root(p);
        q = root(q);
        if (p == q) return false;
        if (q < p) swap(p, q);
        data[p] += data[q];
        data[q] = p;
        return true;
    }
    // 親要素を取得 O(α(n))
    int root(int p) {
        assert(0 <= p && p < _n);
        if (data[p] < 0) {
            return p;
        } else {
            data[p] = root(data[p]);
            return data[p];
        }
    }
    // 親要素を取得 O(α(n))
    int operator[](int p) {
        return root(p);
    }
    // 2 つの要素が同じ集合に含まれるか判定 O(α(n))
    bool same(int p, int q) {
        return root(p) == root(q);
    }
    // 要素が属する集合の大きさを返す O(α(n))
    int size(int p) {
        return -data[root(p)];
    }
    // UnionFind の連結成分のvector を返す O(n α(n))
    vector<vector<int>> groups() {
        vector<vector<int>> re(_n);
        for (int i=0; i<_n; i++) re[root(i)].push_back(i);
        re.erase(remove_if(re.begin(), re.end(), [](vector<int>& v){ return v.empty(); }), re.end());
        return re;
    }
};