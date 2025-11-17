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
  bundledCode: "#line 2 \"graph/graphutil.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T = int, bool directed = false, bool weighted = false>\n\
    vector<int> dfs_order(graph<T, weighted, directed>& g, int s = 0) {\n    vector<int>\
    \ re(g.size(), -1);\n    stack<int> q; q.push(s);\n    int cnt = 0; re[s] = cnt++;\n\
    \    while (!q.empty()) {\n        int x = q.top(); q.pop();\n        for (auto\
    \ e : g[x]) {\n            if (re[e.to] == -1) {\n                re[e.to] = cnt++;\n\
    \                q.push(e.to);\n            }\n        }\n    }\n    return re;\n\
    }\n\ntemplate <class T = int, bool directed = false, bool weighted = false>\n\
    vector<int> bfs_order(graph<T, weighted, directed>& g, int s = 0) {\n    vector<int>\
    \ re(g.size(), -1);\n    queue<int> q; q.push(s);\n    int cnt = 0; re[s] = cnt++;\n\
    \    while (!q.empty()) {\n        int x = q.front(); q.pop();\n        for (auto\
    \ e : g[x]) {\n            if (re[e.to] == -1) {\n                re[e.to] = cnt++;\n\
    \                q.push(e.to);\n            }\n        }\n    }\n    return re;\n\
    }\n\ntemplate <class T = int, bool directed = false, bool weighted = false>\n\
    vector<int> distance(graph<T, weighted, directed>& g, int s = 0) {\n    vector<int>\
    \ re(g.size(), -1);\n    queue<int> q; q.push(s);\n    re[s] = 0;\n    while (!q.empty())\
    \ {\n        int x = q.front(); q.pop();\n        for (auto e : g[x]) {\n    \
    \        if (re[e.to] == -1) {\n                re[e.to] = re[x] + 1;\n      \
    \          q.push(e.to);\n            }\n        }\n    }\n    return re;\n}\n\
    \ntemplate <class T = int, bool directed = false, bool weighted = false>\npair<int,\
    \ pair<int, int>> diameter(graph<T, weighted, directed>& g) {\n    vector<int>\
    \ d1 = distance(g, 0);\n    int s = max_element(d1.begin(), d1.end()) - d1.begin();\n\
    \    vector<int> d2 = distance(g, s);\n    int t = max_element(d2.begin(), d2.end())\
    \ - d2.begin();\n    return {d2[t], {s, t}};\n}\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate <class\
    \ T = int, bool directed = false, bool weighted = false>\nvector<int> dfs_order(graph<T,\
    \ weighted, directed>& g, int s = 0) {\n    vector<int> re(g.size(), -1);\n  \
    \  stack<int> q; q.push(s);\n    int cnt = 0; re[s] = cnt++;\n    while (!q.empty())\
    \ {\n        int x = q.top(); q.pop();\n        for (auto e : g[x]) {\n      \
    \      if (re[e.to] == -1) {\n                re[e.to] = cnt++;\n            \
    \    q.push(e.to);\n            }\n        }\n    }\n    return re;\n}\n\ntemplate\
    \ <class T = int, bool directed = false, bool weighted = false>\nvector<int> bfs_order(graph<T,\
    \ weighted, directed>& g, int s = 0) {\n    vector<int> re(g.size(), -1);\n  \
    \  queue<int> q; q.push(s);\n    int cnt = 0; re[s] = cnt++;\n    while (!q.empty())\
    \ {\n        int x = q.front(); q.pop();\n        for (auto e : g[x]) {\n    \
    \        if (re[e.to] == -1) {\n                re[e.to] = cnt++;\n          \
    \      q.push(e.to);\n            }\n        }\n    }\n    return re;\n}\n\ntemplate\
    \ <class T = int, bool directed = false, bool weighted = false>\nvector<int> distance(graph<T,\
    \ weighted, directed>& g, int s = 0) {\n    vector<int> re(g.size(), -1);\n  \
    \  queue<int> q; q.push(s);\n    re[s] = 0;\n    while (!q.empty()) {\n      \
    \  int x = q.front(); q.pop();\n        for (auto e : g[x]) {\n            if\
    \ (re[e.to] == -1) {\n                re[e.to] = re[x] + 1;\n                q.push(e.to);\n\
    \            }\n        }\n    }\n    return re;\n}\n\ntemplate <class T = int,\
    \ bool directed = false, bool weighted = false>\npair<int, pair<int, int>> diameter(graph<T,\
    \ weighted, directed>& g) {\n    vector<int> d1 = distance(g, 0);\n    int s =\
    \ max_element(d1.begin(), d1.end()) - d1.begin();\n    vector<int> d2 = distance(g,\
    \ s);\n    int t = max_element(d2.begin(), d2.end()) - d2.begin();\n    return\
    \ {d2[t], {s, t}};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphutil.hpp
  requiredBy: []
  timestamp: '2025-10-04 20:14:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graphutil.hpp
layout: document
redirect_from:
- /library/graph/graphutil.hpp
- /library/graph/graphutil.hpp.html
title: graph/graphutil.hpp
---
