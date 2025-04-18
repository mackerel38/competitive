#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template<class T = int, bool directed = false, bool weighted = true>
vector<int> dijkstrarestore(graph<T, directed, weighted>& g, int from = 0, int to = -1) {
    if (to == -1) to = g.size() - 1;
    vector<int> prev(g.size(), -1);
    vector<T> dist(g.size(), numeric_limits<T>::max()); dist[from] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    q.push({T{}, from});
    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        if (dist[x] < t) continue;
        for (auto& _e : g[x]) {
            int y = _e.to;
            if (dist[x] + _e.cost < dist[y]) {
                dist[y] = dist[x] + _e.cost;
                q.push({dist[y], y});
                prev[y] = x;
            }
        }
    }
    vector<int> path;
    for (int i=to; i!=-1; i=prev[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}