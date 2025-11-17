---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/erasablepq.hpp
    title: structure/erasablepq.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/erasablepq.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct erasablepq {\n    priority_queue<T>\
    \ pq, del;\n    void push(const T& x) {\n        pq.push(x);\n        normalize();\n\
    \    }\n    void erase(const T& x) {\n        del.push(x);\n        normalize();\n\
    \    }\n    void pop() {\n        pq.pop();\n        normalize();\n    }\n   \
    \ T top() {\n        return pq.top();\n        normalize();\n    }\n    bool empty()\
    \ {\n        return pq.empty();\n        normalize();\n    }\n    int size() {\n\
    \        return pq.size() - del.size();\n    }\n    void normalize() {\n     \
    \   while (!del.empty() && !pq.empty() && pq.top() == del.top()) {\n         \
    \   pq.pop();\n            del.pop();\n        }\n    }\n};\n\ntemplate <class\
    \ T>\nstruct erasablepqg {\n    priority_queue<T, vector<T>, greater<T>> pq, del;\n\
    \    void push(const T& x) {\n        pq.push(x);\n        normalize();\n    }\n\
    \    void erase(const T& x) {\n        del.push(x);\n        normalize();\n  \
    \  }\n    void pop() {\n        pq.pop();\n        normalize();\n    }\n    T\
    \ top() {\n        return pq.top();\n        normalize();\n    }\n    bool empty()\
    \ {\n        return pq.empty();\n        normalize();\n    }\n    int size() {\n\
    \        return pq.size() - del.size();\n    }\n    void normalize() {\n     \
    \   while (!del.empty() && !pq.empty() && pq.top() == del.top()) {\n         \
    \   pq.pop();\n            del.pop();\n        }\n    }\n};\n#line 4 \"structure/bipq.hpp\"\
    \nusing namespace std;\n\ntemplate <class T>\nstruct bipq {\n    erasablepq<T>\
    \ q;\n    erasablepqg<T> qg;\n    void push(const T& x) { q.push(x); qg.push(x);\
    \ }\n    void erase(const T& x) { q.erase(x); qg.erase(x); }\n    void pop_max()\
    \ {\n        qg.erase(q.top());\n        q.pop();\n    }\n    void pop_min() {\n\
    \        q.erase(qg.top());\n        qg.pop();\n    }\n    T top_max() { return\
    \ q.top(); }\n    T top_min() { return qg.top(); }\n    int size() { return q.size();\
    \ }\n    bool empty() { return q.empty(); }\n};\n"
  code: "#pragma once\n#include \"erasablepq\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct bipq {\n    erasablepq<T> q;\n    erasablepqg<T>\
    \ qg;\n    void push(const T& x) { q.push(x); qg.push(x); }\n    void erase(const\
    \ T& x) { q.erase(x); qg.erase(x); }\n    void pop_max() {\n        qg.erase(q.top());\n\
    \        q.pop();\n    }\n    void pop_min() {\n        q.erase(qg.top());\n \
    \       qg.pop();\n    }\n    T top_max() { return q.top(); }\n    T top_min()\
    \ { return qg.top(); }\n    int size() { return q.size(); }\n    bool empty()\
    \ { return q.empty(); }\n};\n"
  dependsOn:
  - structure/erasablepq.hpp
  isVerificationFile: false
  path: structure/bipq.hpp
  requiredBy: []
  timestamp: '2025-11-18 00:25:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/bipq.hpp
layout: document
redirect_from:
- /library/structure/bipq.hpp
- /library/structure/bipq.hpp.html
title: structure/bipq.hpp
---
