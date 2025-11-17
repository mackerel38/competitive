---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
  - icon: ':warning:'
    path: graph/fordfulkerson.hpp
    title: graph/fordfulkerson.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flowtemplate.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct flowedge {\n    int to;\n    T\
    \ cap;\n    int rev;\n};\n\ntemplate <class T>\nusing flowedges = vector<flowedge<T>>;\n\
    \ntemplate <class T>\nstruct flowgraph {\n    vector<flowedges<T>> data;\n   \
    \ flowgraph() = default;\n    flowgraph(int n) : data(n) {}\n    void add_edge(int\
    \ from, int to, T cap = numeric_limits<T>::max()) {\n        if (id == -1) id\
    \ = _edges.size();\n        data[from].push_back(flowedge<T>{to, cap, data[to].size()});\n\
    \        data[to].push_back(flowedge<T>{from, T{}, data[from].size()-1});\n  \
    \  }\n    int size() {\n        return data.size();\n    }\n    flowedges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct flowedge {\n    int to;\n    T cap;\n    int rev;\n};\n\n\
    template <class T>\nusing flowedges = vector<flowedge<T>>;\n\ntemplate <class\
    \ T>\nstruct flowgraph {\n    vector<flowedges<T>> data;\n    flowgraph() = default;\n\
    \    flowgraph(int n) : data(n) {}\n    void add_edge(int from, int to, T cap\
    \ = numeric_limits<T>::max()) {\n        if (id == -1) id = _edges.size();\n \
    \       data[from].push_back(flowedge<T>{to, cap, data[to].size()});\n       \
    \ data[to].push_back(flowedge<T>{from, T{}, data[from].size()-1});\n    }\n  \
    \  int size() {\n        return data.size();\n    }\n    flowedges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flowtemplate.hpp
  requiredBy:
  - graph/fordfulkerson.hpp
  - graph/dinic.hpp
  timestamp: '2025-08-08 21:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/flowtemplate.hpp
layout: document
redirect_from:
- /library/graph/flowtemplate.hpp
- /library/graph/flowtemplate.hpp.html
title: graph/flowtemplate.hpp
---
