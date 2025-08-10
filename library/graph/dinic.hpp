#include <bits/stdc++.h>
using namespace std;
#include "flowtemplate"

template <class T>
T dinic(flowgraph<T>& g, int s=0, int t=-1) {
    if (t == -1) t = g.size()-1;
    T re = T{};
    auto f = [&](auto&& self, int from, int to, T lim, vector<int>& d, vector<int>& seen) -> T {
        if (from == to) return lim;
        for (int& i=seen[from]; i<(int)g[from].size(); i++) {
            flowedge<T>& _e = g[from][i];
            if (d[from]<d[_e.to] && 0<_e.cap) {
                T r = self(self, _e.to, to, min(lim, _e.cap), d, seen);
                if (T{} < r) {
                    _e.cap -= d;
                    g[_e.to][_e.rev] += d;
                    return d;
                }
            }
        }
        return T{};
    };
    while (true) {
        vector<int> d(g.size(), -1);
        queue<int> q;
        d[s] = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i=0; i<g[x].size(); i++) {
                flowedge<T>& _e = g[x][i];
                if (d[_e.to]==-1 && 0<_e.cap) {
                    d[_e.to] = d[x] + 1;
                    q.push(_e.to);
                }
            }
        }
        if (d[t] == -1) break;
        vector<char> seen(g.size());
        int r;
        while (0 < (r = f(f, s, t, numeric_limits<T>::max())), d, seen) re += r;
    }
    return re;
}