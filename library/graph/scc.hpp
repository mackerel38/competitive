#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// グラフを強連結成分分解し、トポロジカル順に並べたものを返す O(n + m)
template<class T = int, bool directed = true, bool weighted = false>
vector<vector<int>> scc(graph<T, directed, weighted>& g) {
    vector<int> low(g.size()), num(g.size(), -1);
    stack<int> st;
    vector<bool> onStack(g.size());
    vector<vector<int>> re;
    auto dfs = [&](auto& self, int x) -> void {
        low[x] = num[x] = st.size();
        st.push(x);
        onStack[x] = true;
        for (auto& _e : g[x]) {
            int y = _e.to;
            if (num[y] == -1) {
                self(self, y);
                low[x] = min(low[x], low[y]);
            } else if (onStack[y]) {
                low[x] = min(low[x], num[y]);
            }
        }
        if (low[x] == num[x]) {
            vector<int> component;
            int y = -1;
            while (y != x) {
                y = st.top(); st.pop(); onStack[y] = false;
                component.push_back(y);
            }
            re.push_back(component);
        }
    };
    for (int i=0; i<(int)g.size(); i++) if (num[i] == -1) dfs(dfs, i);
    reverse(re.begin(), re.end());
    return re;
}