---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\n\
    template<class T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n// \u9802\u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class\
    \ T = int>\nusing edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\
    \u4F53 graph<T, directed, weighted> \ntemplate <class T = int, bool directed =\
    \ false, bool weighted = false>\nstruct graph {\n    bool isdirected, isweighted;\n\
    \    edges<T> _edges;\n    vector<edges<T>> data;\n    T sumcost;\n    graph()\
    \ = default;\n    // \u9802\u70B9\u6570 n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u6210\u3059\u308B\n    graph(int n) : isdirected(directed), isweighted(weighted),\
    \ data(n), sumcost(T{}) {}\n    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(int from, int to, T cost = 1, int id = -1)\
    \ {\n        if (id == -1) id = _edges.size();\n        data[from].push_back(edge<T>{from,\
    \ to, cost, id});\n        _edges.push_back(edge<T>{from, to, cost, id});\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>{to, from, cost,\
    \ id});\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n    // \u30D1\u30B9\u3092\u9802\u70B9\u306B\
    \u5909\u63DB\u3059\u308B\n    vector<int> path_to_vertex(edges<T>& _e) {\n   \
    \     vector<int> re;\n        if (_e.size() == 0) {\n            return re;\n\
    \        }\n        if (_e.size() == 1) {\n            re.push_back(_e[0].from);\n\
    \            re.push_back(_e[0].to);\n            return re;\n        }\n    \
    \    int x=_e[0].from,y=_e[0].to;\n        if (x==_e[1].to || x == _e[1].from)\
    \ swap(x, y);\n        re.push_back(x);\n        for (int i=1; i<_e.size(); i++)\
    \ {\n            re.push_back(y);\n            x = _e[i].to;\n            if (x\
    \ == y) x = _e[i].from;\n            swap(x, y);\n        }\n        return re;\n\
    \    }\n    // \u9802\u70B9\u3092\u30D1\u30B9\u306B\u5909\u63DB\u3059\u308B\n\
    \    edges<T> vetex_to_path (vector<int>& v){\n        edges<T> re;\n        for\
    \ (int i=0; i+1<v.size(); i++) {\n            for (auto& _e : this[v[i]]) {\n\
    \                if (_e.to == v[i+1]) {\n                    re.push_back(_e);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return re;\n    }\n};\n#line 3 \"structure/UnionFind.hpp\"\nusing namespace\
    \ std;\nstruct UnionFind {\n    int _n;\n    vector<int> data;\n    UnionFind()\
    \ = default;\n    // n \u500B\u306E\u8981\u7D20\u304B\u3089\u306A\u308BUnionFind\
    \ \u3092\u69CB\u7BC9 O(n)\n    UnionFind(int n) : _n(n), data(n, -1) {}\n    //\
    \ 2 \u3064\u306E\u8981\u7D20\u3092\u4F75\u5408 O(\u03B1(n))\n    bool merge(int\
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
    \   }\n};\n#line 5 \"graph/kruskal.hpp\"\nusing namespace std;\n// \u30AF\u30E9\
    \u30B9\u30AB\u30EB\u6CD5\u3092\u7528\u3044\u3066\u6700\u5C0F\u5168\u57DF\u6728\
    \u3092\u6C42\u3081\u308B O(m log m)\ntemplate<class T = int, bool directed = false,\
    \ bool weighted = true>\ngraph<T, directed, weighted> kruskal(graph<T, directed,\
    \ weighted>& g) {\n    graph<T, directed, weighted> re(g.size());\n    edges<T>\
    \ _edges = g._edges;\n    sort(_edges.begin(), _edges.end(), [](edge<T> e1, edge<T>\
    \ e2) { return e1.cost < e2.cost;} );\n    UnionFind uf(g.size());\n    for (auto&\
    \ _e : _edges) {\n        if (uf.merge(_e.from, _e.to)) {\n            re.add_edge(_e);\n\
    \        }\n    }\n    return re;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include \"UnionFind\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n// \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\u3092\u7528\u3044\
    \u3066\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B O(m log m)\ntemplate<class\
    \ T = int, bool directed = false, bool weighted = true>\ngraph<T, directed, weighted>\
    \ kruskal(graph<T, directed, weighted>& g) {\n    graph<T, directed, weighted>\
    \ re(g.size());\n    edges<T> _edges = g._edges;\n    sort(_edges.begin(), _edges.end(),\
    \ [](edge<T> e1, edge<T> e2) { return e1.cost < e2.cost;} );\n    UnionFind uf(g.size());\n\
    \    for (auto& _e : _edges) {\n        if (uf.merge(_e.from, _e.to)) {\n    \
    \        re.add_edge(_e);\n        }\n    }\n    return re;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  - structure/UnionFind.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2025-11-27 12:44:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
