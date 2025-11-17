---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/bipq.hpp
    title: structure/bipq.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/erasablepq.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct erasablepq {\n    priority_queue<T>\
    \ pq, del;\n    void push(const T& x) { pq.push(x); }\n    void erase(const T&\
    \ x) { del.push(x); }\n    void pop() {\n        normalize();\n        pq.pop();\n\
    \    }\n    T top() {\n        normalize();\n        return pq.top();\n    }\n\
    \    bool empty() {\n        normalize();\n        return pq.empty();\n    }\n\
    \    void normalize() {\n        while (!del.empty() && !pq.empty() && pq.top()\
    \ == del.top()) {\n            pq.pop();\n            del.pop();\n        }\n\
    \    }\n};\n\ntemplate <class T>\nstruct erasablepqg {\n    priority_queue<T,\
    \ vector<T>, greater<T>> pq, del;\n    void push(const T& x) { pq.push(x); }\n\
    \    void erase(const T& x) { del.push(x); }\n    void pop() {\n        normalize();\n\
    \        pq.pop();\n    }\n    T top() {\n        normalize();\n        return\
    \ pq.top();\n    }\n    bool empty() {\n        normalize();\n        return pq.empty();\n\
    \    }\n    void normalize() {\n        while (!del.empty() && !pq.empty() &&\
    \ pq.top() == del.top()) {\n            pq.pop();\n            del.pop();\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct erasablepq {\n    priority_queue<T> pq, del;\n    void push(const\
    \ T& x) { pq.push(x); }\n    void erase(const T& x) { del.push(x); }\n    void\
    \ pop() {\n        normalize();\n        pq.pop();\n    }\n    T top() {\n   \
    \     normalize();\n        return pq.top();\n    }\n    bool empty() {\n    \
    \    normalize();\n        return pq.empty();\n    }\n    void normalize() {\n\
    \        while (!del.empty() && !pq.empty() && pq.top() == del.top()) {\n    \
    \        pq.pop();\n            del.pop();\n        }\n    }\n};\n\ntemplate <class\
    \ T>\nstruct erasablepqg {\n    priority_queue<T, vector<T>, greater<T>> pq, del;\n\
    \    void push(const T& x) { pq.push(x); }\n    void erase(const T& x) { del.push(x);\
    \ }\n    void pop() {\n        normalize();\n        pq.pop();\n    }\n    T top()\
    \ {\n        normalize();\n        return pq.top();\n    }\n    bool empty() {\n\
    \        normalize();\n        return pq.empty();\n    }\n    void normalize()\
    \ {\n        while (!del.empty() && !pq.empty() && pq.top() == del.top()) {\n\
    \            pq.pop();\n            del.pop();\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/erasablepq.hpp
  requiredBy:
  - structure/bipq.hpp
  timestamp: '2025-11-17 11:52:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/erasablepq.hpp
layout: document
redirect_from:
- /library/structure/erasablepq.hpp
- /library/structure/erasablepq.hpp.html
title: structure/erasablepq.hpp
---
