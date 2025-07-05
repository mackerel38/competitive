#pragma once
#include<bits/stdc++.h>
using namespace std;
struct rollbackUnionFind {
    int _n;
    vector<int> data;
    stack<pair<int, int>> history;
    int snap;
    rollbackUnionFind() = default;
    // _n 個の要素からなるrollback 可能なUnionFind を構築 O(n)
    rollbackUnionFind(int n) : _n(n), data(n, -1), snap(0) {}
    // 2 つの要素を併合 O(log n)
    bool merge(int p, int q) {
        p = root(p);
        q = root(q);
        history.push({p, data[p]});
        history.push({q, data[q]});
        if (p == q) return false;
        if (data[q] < data[p]) swap(p, q);
        data[p] += data[q];
        data[q] = p;
        return true;
    }
    // 親要素を取得 O(log n)
    int root(int p) {
        assert(0 <= p && p < _n);
        if (data[p] < 0) {
            return p;
        } else {
            return root(data[p]);
        }
    }
    // 2 つの要素が同じ集合に含まれるか判定 O(log n)
    bool same(int p, int q) {
        return root(p) == root(q);
    }
    // 要素が属する集合の大きさを返す O(log n)
    int size(int p) {
        return -data[root(p)];
    }
    // UnionFindの状態を記録 O(1)
    int snapshot() {
        snap = history.size();
        return snap;
    }
    // 1 回分の操作を戻す
    void undo() {
        data[history.top().first] = history.top().second; history.pop();
        data[history.top().first] = history.top().second; history.pop();
    }
    // 操作を指定した状態まで巻き戻す 省略した場合はsnapshot の位置から O(操作回数)
    void rollback(int state=-1) {
        if (state == -1) state = snap;
        assert(state <= history.size());
        while (state < history.size()) undo();
    }
    // UnionFind の連結成分のvector を返す O(n log n)
    vector<vector<int>> groups() {
        vector<vector<int>> re(_n);
        for (int i=0; i<_n; i++) re[root(i)].push_back(i);
        re.erase(remove_if(re.begin(), re.end(), [](vector<int>& v){ return v.empty(); }), re.end());
        return re;
    }
};