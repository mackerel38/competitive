#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// 最短経路問題の双対（牛ゲー）を解く
template<class T>
struct dualshortestpath {
    graph<T, true, true> g;
    dualshortestpath(int n) : g(n) {}
    // f(to) <= f(from) + cost
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        if (cost < 0) {
            cost = -cost;
            swap(from, to);
        }
        g.add_edge(from, to, cost, id);
    }
    // f(to) <= f(from) + cost
    void add_edge(edge<T> _e) {
        if (_e.cost < 0) {
            _e.cost = -_e.cost;
            swap(_e.from, _e.to);
        }
        g.add_edge(_e);
    }
    // 牛ゲーを解く d[t]: max{f(t) - f(s)} を求める O(nm)
    vector<T> solve(int start = -1) {
        vector<T> d(N, numeric_limits<T>::max()/2);
        if (start == -1) fill(begin(d), end(d), T{});
        if (start != -1) d[start] = 0;
        for (int i=0; i<g.size(); i++) {
            int updated = 0;
            for (auto _e : g._edges) {
                if (d[_e.from] + _e.cost < d[e.to]) {
                  d[_e.to] = d[_e.from] + _e.cost;
                  updated = 1;
                }
            }
            if (!updated) break;
            if (i == g.size() - 1) {
                for (int j=0; j<g.size(); j++) {
                    d[j] = -1;
                }
            }
        }
        return d;
    }
};