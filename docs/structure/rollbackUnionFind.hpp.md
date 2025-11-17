---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/rollbackUnionFind.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\nstruct rollbackUnionFind {\n    int _n;\n    vector<int>\
    \ data;\n    stack<pair<int, int>> history;\n    int snap;\n    rollbackUnionFind()\
    \ = default;\n    // _n \u500B\u306E\u8981\u7D20\u304B\u3089\u306A\u308Brollback\
    \ \u53EF\u80FD\u306AUnionFind \u3092\u69CB\u7BC9 O(n)\n    rollbackUnionFind(int\
    \ n) : _n(n), data(n, -1), snap(0) {}\n    // 2 \u3064\u306E\u8981\u7D20\u3092\
    \u4F75\u5408 O(log n)\n    bool merge(int p, int q) {\n        p = root(p);\n\
    \        q = root(q);\n        history.push({p, data[p]});\n        history.push({q,\
    \ data[q]});\n        if (p == q) return false;\n        if (data[q] < data[p])\
    \ swap(p, q);\n        data[p] += data[q];\n        data[q] = p;\n        return\
    \ true;\n    }\n    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97 O(log n)\n    int\
    \ root(int p) {\n        assert(0 <= p && p < _n);\n        if (data[p] < 0) {\n\
    \            return p;\n        } else {\n            return root(data[p]);\n\
    \        }\n    }\n    // 2 \u3064\u306E\u8981\u7D20\u304C\u540C\u3058\u96C6\u5408\
    \u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A O(log n)\n    bool same(int p,\
    \ int q) {\n        return root(p) == root(q);\n    }\n    // \u8981\u7D20\u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059 O(log\
    \ n)\n    int size(int p) {\n        return -data[root(p)];\n    }\n    // UnionFind\u306E\
    \u72B6\u614B\u3092\u8A18\u9332 O(1)\n    int snapshot() {\n        snap = history.size();\n\
    \        return snap;\n    }\n    // 1 \u56DE\u5206\u306E\u64CD\u4F5C\u3092\u623B\
    \u3059\n    void undo() {\n        data[history.top().first] = history.top().second;\
    \ history.pop();\n        data[history.top().first] = history.top().second; history.pop();\n\
    \    }\n    // \u64CD\u4F5C\u3092\u6307\u5B9A\u3057\u305F\u72B6\u614B\u307E\u3067\
    \u5DFB\u304D\u623B\u3059 \u7701\u7565\u3057\u305F\u5834\u5408\u306Fsnapshot \u306E\
    \u4F4D\u7F6E\u304B\u3089 O(\u64CD\u4F5C\u56DE\u6570)\n    void rollback(int state=-1)\
    \ {\n        if (state == -1) state = snap;\n        assert(state <= history.size());\n\
    \        while (state < history.size()) undo();\n    }\n    // UnionFind \u306E\
    \u9023\u7D50\u6210\u5206\u306Evector \u3092\u8FD4\u3059 O(n log n)\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> re(_n);\n        for (int i=0; i<_n;\
    \ i++) re[root(i)].push_back(i);\n        re.erase(remove_if(re.begin(), re.end(),\
    \ [](vector<int>& v){ return v.empty(); }), re.end());\n        return re;\n \
    \   }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nstruct rollbackUnionFind\
    \ {\n    int _n;\n    vector<int> data;\n    stack<pair<int, int>> history;\n\
    \    int snap;\n    rollbackUnionFind() = default;\n    // _n \u500B\u306E\u8981\
    \u7D20\u304B\u3089\u306A\u308Brollback \u53EF\u80FD\u306AUnionFind \u3092\u69CB\
    \u7BC9 O(n)\n    rollbackUnionFind(int n) : _n(n), data(n, -1), snap(0) {}\n \
    \   // 2 \u3064\u306E\u8981\u7D20\u3092\u4F75\u5408 O(log n)\n    bool merge(int\
    \ p, int q) {\n        p = root(p);\n        q = root(q);\n        history.push({p,\
    \ data[p]});\n        history.push({q, data[q]});\n        if (p == q) return\
    \ false;\n        if (data[q] < data[p]) swap(p, q);\n        data[p] += data[q];\n\
    \        data[q] = p;\n        return true;\n    }\n    // \u89AA\u8981\u7D20\u3092\
    \u53D6\u5F97 O(log n)\n    int root(int p) {\n        assert(0 <= p && p < _n);\n\
    \        if (data[p] < 0) {\n            return p;\n        } else {\n       \
    \     return root(data[p]);\n        }\n    }\n    // 2 \u3064\u306E\u8981\u7D20\
    \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\
    \ O(log n)\n    bool same(int p, int q) {\n        return root(p) == root(q);\n\
    \    }\n    // \u8981\u7D20\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u5927\u304D\
    \u3055\u3092\u8FD4\u3059 O(log n)\n    int size(int p) {\n        return -data[root(p)];\n\
    \    }\n    // UnionFind\u306E\u72B6\u614B\u3092\u8A18\u9332 O(1)\n    int snapshot()\
    \ {\n        snap = history.size();\n        return snap;\n    }\n    // 1 \u56DE\
    \u5206\u306E\u64CD\u4F5C\u3092\u623B\u3059\n    void undo() {\n        data[history.top().first]\
    \ = history.top().second; history.pop();\n        data[history.top().first] =\
    \ history.top().second; history.pop();\n    }\n    // \u64CD\u4F5C\u3092\u6307\
    \u5B9A\u3057\u305F\u72B6\u614B\u307E\u3067\u5DFB\u304D\u623B\u3059 \u7701\u7565\
    \u3057\u305F\u5834\u5408\u306Fsnapshot \u306E\u4F4D\u7F6E\u304B\u3089 O(\u64CD\
    \u4F5C\u56DE\u6570)\n    void rollback(int state=-1) {\n        if (state == -1)\
    \ state = snap;\n        assert(state <= history.size());\n        while (state\
    \ < history.size()) undo();\n    }\n    // UnionFind \u306E\u9023\u7D50\u6210\u5206\
    \u306Evector \u3092\u8FD4\u3059 O(n log n)\n    vector<vector<int>> groups() {\n\
    \        vector<vector<int>> re(_n);\n        for (int i=0; i<_n; i++) re[root(i)].push_back(i);\n\
    \        re.erase(remove_if(re.begin(), re.end(), [](vector<int>& v){ return v.empty();\
    \ }), re.end());\n        return re;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/rollbackUnionFind.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/rollbackUnionFind.hpp
layout: document
redirect_from:
- /library/structure/rollbackUnionFind.hpp
- /library/structure/rollbackUnionFind.hpp.html
title: structure/rollbackUnionFind.hpp
---
