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
  bundledCode: "#line 2 \"graph/fordfulkerson.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"graph/flowtemplate.hpp\"\nusing namespace std;\n\n\
    template <class T>\nstruct flowedge {\n    int to;\n    T cap;\n    int rev;\n\
    };\n\ntemplate <class T>\nusing flowedges = vector<flowedge<T>>;\n\ntemplate <class\
    \ T>\nstruct flowgraph {\n    vector<flowedges<T>> data;\n    flowgraph() = default;\n\
    \    flowgraph(int n) : data(n) {}\n    void add_edge(int from, int to, T cap\
    \ = numeric_limits<T>::max()) {\n        if (id == -1) id = _edges.size();\n \
    \       data[from].push_back(flowedge<T>{to, cap, data[to].size()});\n       \
    \ data[to].push_back(flowedge<T>{from, T{}, data[from].size()-1});\n    }\n  \
    \  int size() {\n        return data.size();\n    }\n    flowedges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};\n#line 5 \"graph/fordfulkerson.hpp\"\
    \n\ntemplate <class T>\nT fordfullkerson(flowgraph<T>& g, int s=0, int t=-1) {\n\
    \    if (t == -1) t = g.size()-1;\n    T re = T{};\n    auto f = [&](auto&& self,\
    \ int from, int to, T lim, vector<char>& used) -> T {\n        if (from == to)\
    \ return lim;\n        used[from] = true;\n        for (int i=0; i<(int)g[from].size();\
    \ i++) {\n            flowedge<T>& _e = g[from][i];\n            if (!used[_e.to]\
    \ && 0<_e.cap) {\n                T r = self(self, _e.to, to, min(lim, _e.cap),\
    \ used);\n                if (T{} < r) {\n                    _e.cap -= r;\n \
    \                   g[_e.to][_e.rev] += r;\n                    return r;\n  \
    \              }\n            }\n        }\n        return T{};\n    };\n    while\
    \ (true) {\n        vector<char> used(g.size());\n        int flow = f(f, s, t,\
    \ numeric_limits<T>::max(), used);\n        if (flow == T{}) break;\n        re\
    \ += flow;\n    }\n    return re;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"\
    flowtemplate\"\n\ntemplate <class T>\nT fordfullkerson(flowgraph<T>& g, int s=0,\
    \ int t=-1) {\n    if (t == -1) t = g.size()-1;\n    T re = T{};\n    auto f =\
    \ [&](auto&& self, int from, int to, T lim, vector<char>& used) -> T {\n     \
    \   if (from == to) return lim;\n        used[from] = true;\n        for (int\
    \ i=0; i<(int)g[from].size(); i++) {\n            flowedge<T>& _e = g[from][i];\n\
    \            if (!used[_e.to] && 0<_e.cap) {\n                T r = self(self,\
    \ _e.to, to, min(lim, _e.cap), used);\n                if (T{} < r) {\n      \
    \              _e.cap -= r;\n                    g[_e.to][_e.rev] += r;\n    \
    \                return r;\n                }\n            }\n        }\n    \
    \    return T{};\n    };\n    while (true) {\n        vector<char> used(g.size());\n\
    \        int flow = f(f, s, t, numeric_limits<T>::max(), used);\n        if (flow\
    \ == T{}) break;\n        re += flow;\n    }\n    return re;\n}\n"
  dependsOn:
  - graph/flowtemplate.hpp
  isVerificationFile: false
  path: graph/fordfulkerson.hpp
  requiredBy: []
  timestamp: '2025-08-08 21:59:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordfulkerson.hpp
layout: document
redirect_from:
- /library/graph/fordfulkerson.hpp
- /library/graph/fordfulkerson.hpp.html
title: graph/fordfulkerson.hpp
---
