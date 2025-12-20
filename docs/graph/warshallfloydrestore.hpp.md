---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
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
    \     return re;\n    }\n};\n#line 4 \"graph/warshallfloydrestore.hpp\"\nusing\
    \ namespace std;\nvector<vector<int>> warshallfloydrestore_p;\nvector<vector<bool>>\
    \ warshallfloydrestore_unreachable;\n// \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\
    \u30A4\u30C9\u6CD5\u3067\u6C42\u3081\u305F\u6700\u77ED\u7D4C\u8DEF\u306E\u5FA9\
    \u5143 O(n^3)\ntemplate<class T = int, bool directed = false, bool weighted =\
    \ true>\nvector<T> warshallfloydrestorebuild(graph<T, directed, weighted>& g,\
    \ int from, int to) {\n    d = vector<vector<int>>(g.size(), vector<int>(g.size(),\
    \ numeric_limits<int>::max()));\n    warshallfloydrestore_p = vector<vector<int>>(g.size(),\
    \ vector<int>(g.size(), -1));\n    for (int i=0; i<g.size(); i++) {\n        d[i][i]\
    \ = 0;\n        for (auto& _e : g[i]) {\n            d[i][_e.to] = _e.cost;\n\
    \            warshallfloydrestore_p[i][_e.to] = i;\n        }\n    }\n    for\
    \ (int k=0; k<g.size(); k++) {\n        for (int i=0; i<g.size(); i++) {\n   \
    \         for (int j=0; j<g.size(); j++) {\n                if (d[i][k] < numeric_limits<int>::max()/2\
    \ && d[k][j] < numeric_limits<int>::max()/2) {\n                    if (d[i][j]\
    \ > d[i][k] + d[k][j]) {\n                        d[i][j] = d[i][k] + d[k][j];\n\
    \                        warshallfloydrestore_p[i][j] = k;\n                 \
    \   }\n                }\n            }\n        }\n    }\n    warshallfloydrestore_unreachable\
    \ = vector<vector<bool>>(g.size(), vector<bool>(g.size(), false));\n    for (int\
    \ i=0; i<g.size(); i++) {\n        for (int j=0; j<g.size(); j++) {\n        \
    \    if (d[i][j] == numeric_limits<int>::max()) {\n                warshallfloydrestore_unreachable[i][j]\
    \ = true;\n            }\n        }\n    }\n    return d[from][to];\n}\n// \u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u6C42\u3081\u305F\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u5FA9\u5143 O(n)\nvector<int> warshallfloydrestore(int\
    \ from, int to) {\n    vector<int> path;\n    if (warshallfloydrestore_unreachable[from][to])\
    \ return path;\n    for (int i=to; i!=from; i=warshallfloydrestore_p[from][i])\
    \ path.push_back(i);\n    path.push_back(from);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nvector<vector<int>> warshallfloydrestore_p;\nvector<vector<bool>>\
    \ warshallfloydrestore_unreachable;\n// \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\
    \u30A4\u30C9\u6CD5\u3067\u6C42\u3081\u305F\u6700\u77ED\u7D4C\u8DEF\u306E\u5FA9\
    \u5143 O(n^3)\ntemplate<class T = int, bool directed = false, bool weighted =\
    \ true>\nvector<T> warshallfloydrestorebuild(graph<T, directed, weighted>& g,\
    \ int from, int to) {\n    d = vector<vector<int>>(g.size(), vector<int>(g.size(),\
    \ numeric_limits<int>::max()));\n    warshallfloydrestore_p = vector<vector<int>>(g.size(),\
    \ vector<int>(g.size(), -1));\n    for (int i=0; i<g.size(); i++) {\n        d[i][i]\
    \ = 0;\n        for (auto& _e : g[i]) {\n            d[i][_e.to] = _e.cost;\n\
    \            warshallfloydrestore_p[i][_e.to] = i;\n        }\n    }\n    for\
    \ (int k=0; k<g.size(); k++) {\n        for (int i=0; i<g.size(); i++) {\n   \
    \         for (int j=0; j<g.size(); j++) {\n                if (d[i][k] < numeric_limits<int>::max()/2\
    \ && d[k][j] < numeric_limits<int>::max()/2) {\n                    if (d[i][j]\
    \ > d[i][k] + d[k][j]) {\n                        d[i][j] = d[i][k] + d[k][j];\n\
    \                        warshallfloydrestore_p[i][j] = k;\n                 \
    \   }\n                }\n            }\n        }\n    }\n    warshallfloydrestore_unreachable\
    \ = vector<vector<bool>>(g.size(), vector<bool>(g.size(), false));\n    for (int\
    \ i=0; i<g.size(); i++) {\n        for (int j=0; j<g.size(); j++) {\n        \
    \    if (d[i][j] == numeric_limits<int>::max()) {\n                warshallfloydrestore_unreachable[i][j]\
    \ = true;\n            }\n        }\n    }\n    return d[from][to];\n}\n// \u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u6C42\u3081\u305F\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u5FA9\u5143 O(n)\nvector<int> warshallfloydrestore(int\
    \ from, int to) {\n    vector<int> path;\n    if (warshallfloydrestore_unreachable[from][to])\
    \ return path;\n    for (int i=to; i!=from; i=warshallfloydrestore_p[from][i])\
    \ path.push_back(i);\n    path.push_back(from);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/warshallfloydrestore.hpp
  requiredBy: []
  timestamp: '2025-10-04 20:14:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/warshallfloydrestore.hpp
layout: document
redirect_from:
- /library/graph/warshallfloydrestore.hpp
- /library/graph/warshallfloydrestore.hpp.html
title: graph/warshallfloydrestore.hpp
---
