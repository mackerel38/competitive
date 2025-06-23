#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;

template <class T, bool directed=true, bool weighted=true>
T TSP(graph<T, directed, weighted>& g, int s=0, int t=-1) {
    if (t == -1) t = g.size() - 1;
    vector<vector<T>> dp(1<<g.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    dp[1<<s][s] = T{};
    for (int i=0; i<(1<<g.size()); i++) {
        for (int j=0;  j<(int)g.size(); j++) {
            if ((i >> j) & 1) {
                if (dp[i][j] != numeric_limits<T>::max()) {
                    for (auto& _e : g[j]) {
                        if ((i >> _e.to) & 1) continue;
                        dp[i^(1<<_e.to)][_e.to] = min(dp[i^(1<<_e.to)][_e.to], dp[i][j] + _e.cost);
                    }
                }
            }
        }
    }
    return dp.back()[t];
}