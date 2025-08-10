#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// ベルマンフォード法で単一始点最短経路を求める 負閉路がある場合は re[from] < 0 O(nm)
template <typename T, bool directed = true, bool weighted = true>
vector<T> bellmanford(graph<T, directed, weighted>& g, int from = 0) {
    vector<T> d(g.size(), numeric_limits<T>::max());
    d[from] = 0;
    for (int i=1; i<g.size(); i++) {
        for (auto& _e : g._edges) {
            if (d[_e.from] != numeric_limits<T>::max() && d[_e.from] + _e.cost < d[_e.to]) {
                d[_e.to] = d[_e.from] + _e.cost;
            }
        }
    }
    for (auto& _e : g._edges) {
        if (d[_e.from] != numeric_limits<T>::max() && d[_e.from] + _e.cost < d[_e.to]) {
            d[from] = -1;
        }
    }
    return d;
}
// ベルマンフォード法で二点間最短経路を求める 負閉路がある場合は re < 0 O(nm)
template <typename T, bool directed = true, bool weighted = true>
T bellmanford(graph<T, directed, weighted>& g, int from, int to) {
    if (to == -1) to = g.size()-1;
    vector<T> d = bellmanford(g, from);
    if (d[from] < 0) return -1;
    return d[to];
}