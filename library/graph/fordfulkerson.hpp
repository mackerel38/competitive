#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "flowtemplate"

template <class T>
T fordfullkerson(flowgraph<T>& g, int s=0, int t=-1) {
    if (t == -1) t = g.size()-1;
    T re = T{};
    auto f = [&](auto&& self, int from, int to, T lim, vector<char>& used) -> T {
        if (from == to) return lim;
        used[from] = true;
        for (int i=0; i<(int)g[from].size(); i++) {
            flowedge<T>& _e = g[from][i];
            if (!used[_e.to] && 0<_e.cap) {
                T r = self(self, _e.to, to, min(lim, _e.cap), used);
                if (T{} < r) {
                    _e.cap -= r;
                    g[_e.to][_e.rev] += r;
                    return r;
                }
            }
        }
        return T{};
    };
    while (true) {
        vector<char> used(g.size());
        int flow = f(f, s, t, numeric_limits<T>::max(), used);
        if (flow == T{}) break;
        re += flow;
    }
    return re;
}
