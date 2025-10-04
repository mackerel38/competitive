#pragma once
#include "graphtemplate"
#include "graphutil"
#include<bits/stdc++.h>
using namespace std;

template <class S, class Merge, class Calc, class T = int, bool directed = false, bool weighted = false>
vector<S> treedp(graph<T, weighted, directed>& g, Merge merge, Calc calc, int s = 0, S e = S{}) {
    vector<S> dp1(g.size(), e), dp2(g.size(), e);
    auto dfs = [&](auto&& self, int x, int p) -> void {
        if (g[x].size() == 1 && g[x][0].to == p) {
            dp2[x] = calc(dp1[x]);
            return;
        }
        for (auto e : g[x]) {
            if (e.to == p) continue;
            self(self, e.to, x);
            dp1[x] = merge(x, dp1[x], e.to, dp1[e.to]);
        }
        dp2[x] = calc(dp1[x]);
    };
    dfs(dfs, s, -1);
    return dp2;
}