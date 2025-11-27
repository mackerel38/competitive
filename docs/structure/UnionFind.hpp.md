---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-unionfind-1.test.cpp
    title: verify/yosupo-unionfind-1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/UnionFind.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nstruct UnionFind {\n    int _n;\n    vector<int> data;\n   \
    \ UnionFind() = default;\n    // n \u500B\u306E\u8981\u7D20\u304B\u3089\u306A\u308B\
    UnionFind \u3092\u69CB\u7BC9 O(n)\n    UnionFind(int n) : _n(n), data(n, -1) {}\n\
    \    // 2 \u3064\u306E\u8981\u7D20\u3092\u4F75\u5408 O(\u03B1(n))\n    bool merge(int\
    \ p, int q) {\n        p = root(p);\n        q = root(q);\n        if (p == q)\
    \ return false;\n        if (data[q] < data[p]) swap(p, q);\n        data[p] +=\
    \ data[q];\n        data[q] = p;\n        return true;\n    }\n    // \u89AA\u8981\
    \u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n    int root(int p) {\n        assert(0\
    \ <= p && p < _n);\n        if (data[p] < 0) {\n            return p;\n      \
    \  } else {\n            data[p] = root(data[p]);\n            return data[p];\n\
    \        }\n    }\n    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n\
    \    int operator[](int p) {\n        return root(p);\n    }\n    // 2 \u3064\u306E\
    \u8981\u7D20\u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\
    \u5224\u5B9A O(\u03B1(n))\n    bool same(int p, int q) {\n        return root(p)\
    \ == root(q);\n    }\n    // \u8981\u7D20\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\
    \u5927\u304D\u3055\u3092\u8FD4\u3059 O(\u03B1(n))\n    int size(int p) {\n   \
    \     return -data[root(p)];\n    }\n    // UnionFind \u306E\u9023\u7D50\u6210\
    \u5206\u306Evector \u3092\u8FD4\u3059 O(n \u03B1(n))\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> re(_n);\n        for (int i=0; i<_n;\
    \ i++) re[root(i)].push_back(i);\n        re.erase(remove_if(re.begin(), re.end(),\
    \ [](vector<int>& v){ return v.empty(); }), re.end());\n        return re;\n \
    \   }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nstruct UnionFind\
    \ {\n    int _n;\n    vector<int> data;\n    UnionFind() = default;\n    // n\
    \ \u500B\u306E\u8981\u7D20\u304B\u3089\u306A\u308BUnionFind \u3092\u69CB\u7BC9\
    \ O(n)\n    UnionFind(int n) : _n(n), data(n, -1) {}\n    // 2 \u3064\u306E\u8981\
    \u7D20\u3092\u4F75\u5408 O(\u03B1(n))\n    bool merge(int p, int q) {\n      \
    \  p = root(p);\n        q = root(q);\n        if (p == q) return false;\n   \
    \     if (data[q] < data[p]) swap(p, q);\n        data[p] += data[q];\n      \
    \  data[q] = p;\n        return true;\n    }\n    // \u89AA\u8981\u7D20\u3092\u53D6\
    \u5F97 O(\u03B1(n))\n    int root(int p) {\n        assert(0 <= p && p < _n);\n\
    \        if (data[p] < 0) {\n            return p;\n        } else {\n       \
    \     data[p] = root(data[p]);\n            return data[p];\n        }\n    }\n\
    \    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n    int operator[](int\
    \ p) {\n        return root(p);\n    }\n    // 2 \u3064\u306E\u8981\u7D20\u304C\
    \u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A O(\u03B1\
    (n))\n    bool same(int p, int q) {\n        return root(p) == root(q);\n    }\n\
    \    // \u8981\u7D20\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u5927\u304D\u3055\
    \u3092\u8FD4\u3059 O(\u03B1(n))\n    int size(int p) {\n        return -data[root(p)];\n\
    \    }\n    // UnionFind \u306E\u9023\u7D50\u6210\u5206\u306Evector \u3092\u8FD4\
    \u3059 O(n \u03B1(n))\n    vector<vector<int>> groups() {\n        vector<vector<int>>\
    \ re(_n);\n        for (int i=0; i<_n; i++) re[root(i)].push_back(i);\n      \
    \  re.erase(remove_if(re.begin(), re.end(), [](vector<int>& v){ return v.empty();\
    \ }), re.end());\n        return re;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/UnionFind.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2025-11-27 14:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-unionfind-1.test.cpp
documentation_of: structure/UnionFind.hpp
layout: document
redirect_from:
- /library/structure/UnionFind.hpp
- /library/structure/UnionFind.hpp.html
title: structure/UnionFind.hpp
---
