#pragma once
#include "graphtemplate"
#include "UnionFind"
#include<bits/stdc++.h>
using namespace std;
// クラスカル法を用いて最小全域木を求める O(m log m)
template<class T = int, bool directed = false, bool weighted = true>
graph<T, directed, weighted> kruskal(graph<T, directed, weighted>& g) {
    graph<T, directed, weighted> re(g.size());
    edges<T> _edges = g._edges;
    sort(_edges.begin(), _edges.end(), [](edge<T> e1, edge<T> e2) { return e1.cost < e2.cost;} );
    UnionFind uf(g.size());
    for (auto& _e : _edges) {
        if (uf.merge(_e.from, _e.to)) {
            re.add_edge(_e);
        }
    }
    return re;
}