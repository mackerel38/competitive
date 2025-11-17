---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/flowtemplate.hpp
    title: graph/flowtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dinic.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#line 3 \"graph/flowtemplate.hpp\"\nusing namespace std;\n\ntemplate <class\
    \ T>\nstruct flowedge {\n    int to;\n    T cap;\n    int rev;\n};\n\ntemplate\
    \ <class T>\nusing flowedges = vector<flowedge<T>>;\n\ntemplate <class T>\nstruct\
    \ flowgraph {\n    vector<flowedges<T>> data;\n    flowgraph() = default;\n  \
    \  flowgraph(int n) : data(n) {}\n    void add_edge(int from, int to, T cap =\
    \ numeric_limits<T>::max()) {\n        if (id == -1) id = _edges.size();\n   \
    \     data[from].push_back(flowedge<T>{to, cap, data[to].size()});\n        data[to].push_back(flowedge<T>{from,\
    \ T{}, data[from].size()-1});\n    }\n    int size() {\n        return data.size();\n\
    \    }\n    flowedges<T> operator[](int k) {\n        return data[k];\n    }\n\
    };\n#line 4 \"graph/dinic.hpp\"\n\ntemplate <class T>\nT dinic(flowgraph<T>& g,\
    \ int s=0, int t=-1) {\n    if (t == -1) t = g.size()-1;\n    T re = T{};\n  \
    \  auto f = [&](auto&& self, int from, int to, T lim, vector<int>& d, vector<int>&\
    \ seen) -> T {\n        if (from == to) return lim;\n        for (int& i=seen[from];\
    \ i<(int)g[from].size(); i++) {\n            flowedge<T>& _e = g[from][i];\n \
    \           if (d[from]<d[_e.to] && 0<_e.cap) {\n                T r = self(self,\
    \ _e.to, to, min(lim, _e.cap), d, seen);\n                if (T{} < r) {\n   \
    \                 _e.cap -= d;\n                    g[_e.to][_e.rev] += d;\n \
    \                   return d;\n                }\n            }\n        }\n \
    \       return T{};\n    };\n    while (true) {\n        vector<int> d(g.size(),\
    \ -1);\n        queue<int> q;\n        d[s] = 0;\n        while (!q.empty()) {\n\
    \            int x = q.front(); q.pop();\n            for (int i=0; i<g[x].size();\
    \ i++) {\n                flowedge<T>& _e = g[x][i];\n                if (d[_e.to]==-1\
    \ && 0<_e.cap) {\n                    d[_e.to] = d[x] + 1;\n                 \
    \   q.push(_e.to);\n                }\n            }\n        }\n        if (d[t]\
    \ == -1) break;\n        vector<char> seen(g.size());\n        int r;\n      \
    \  while (0 < (r = f(f, s, t, numeric_limits<T>::max())), d, seen) re += r;\n\
    \    }\n    return re;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#include \"flowtemplate\"\
    \n\ntemplate <class T>\nT dinic(flowgraph<T>& g, int s=0, int t=-1) {\n    if\
    \ (t == -1) t = g.size()-1;\n    T re = T{};\n    auto f = [&](auto&& self, int\
    \ from, int to, T lim, vector<int>& d, vector<int>& seen) -> T {\n        if (from\
    \ == to) return lim;\n        for (int& i=seen[from]; i<(int)g[from].size(); i++)\
    \ {\n            flowedge<T>& _e = g[from][i];\n            if (d[from]<d[_e.to]\
    \ && 0<_e.cap) {\n                T r = self(self, _e.to, to, min(lim, _e.cap),\
    \ d, seen);\n                if (T{} < r) {\n                    _e.cap -= d;\n\
    \                    g[_e.to][_e.rev] += d;\n                    return d;\n \
    \               }\n            }\n        }\n        return T{};\n    };\n   \
    \ while (true) {\n        vector<int> d(g.size(), -1);\n        queue<int> q;\n\
    \        d[s] = 0;\n        while (!q.empty()) {\n            int x = q.front();\
    \ q.pop();\n            for (int i=0; i<g[x].size(); i++) {\n                flowedge<T>&\
    \ _e = g[x][i];\n                if (d[_e.to]==-1 && 0<_e.cap) {\n           \
    \         d[_e.to] = d[x] + 1;\n                    q.push(_e.to);\n         \
    \       }\n            }\n        }\n        if (d[t] == -1) break;\n        vector<char>\
    \ seen(g.size());\n        int r;\n        while (0 < (r = f(f, s, t, numeric_limits<T>::max())),\
    \ d, seen) re += r;\n    }\n    return re;\n}"
  dependsOn:
  - graph/flowtemplate.hpp
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2025-08-08 22:07:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dinic.hpp
layout: document
redirect_from:
- /library/graph/dinic.hpp
- /library/graph/dinic.hpp.html
title: graph/dinic.hpp
---
