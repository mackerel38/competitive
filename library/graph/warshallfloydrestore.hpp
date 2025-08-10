#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> warshallfloydrestore_p;
vector<vector<bool>> warshallfloydrestore_unreachable;
// ワーシャルフロイド法で求めた最短経路の復元 O(n^3)
template<class T = int, bool directed = false, bool weighted = true>
vector<T> warshallfloydrestorebuild(graph<T, directed, weighted>& g, int from, int to) {
    d = vector<vector<int>>(g.size(), vector<int>(g.size(), numeric_limits<int>::max()));
    warshallfloydrestore_p = vector<vector<int>>(g.size(), vector<int>(g.size(), -1));
    for (int i=0; i<g.size(); i++) {
        d[i][i] = 0;
        for (auto& _e : g[i]) {
            d[i][_e.to] = _e.cost;
            warshallfloydrestore_p[i][_e.to] = i;
        }
    }
    for (int k=0; k<g.size(); k++) {
        for (int i=0; i<g.size(); i++) {
            for (int j=0; j<g.size(); j++) {
                if (d[i][k] < numeric_limits<int>::max()/2 && d[k][j] < numeric_limits<int>::max()/2) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        warshallfloydrestore_p[i][j] = k;
                    }
                }
            }
        }
    }
    warshallfloydrestore_unreachable = vector<vector<bool>>(g.size(), vector<bool>(g.size(), false));
    for (int i=0; i<g.size(); i++) {
        for (int j=0; j<g.size(); j++) {
            if (d[i][j] == numeric_limits<int>::max()) {
                warshallfloydrestore_unreachable[i][j] = true;
            }
        }
    }
    return d[from][to];
}
// ワーシャルフロイド法で求めた最短経路の復元 O(n)
vector<int> warshallfloydrestore(int from, int to) {
    vector<int> path;
    if (warshallfloydrestore_unreachable[from][to]) return path;
    for (int i=to; i!=from; i=warshallfloydrestore_p[from][i]) path.push_back(i);
    path.push_back(from);
    reverse(path.begin(), path.end());
    return path;
}