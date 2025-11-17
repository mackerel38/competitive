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
    \   pq.pop();\n            del.pop();\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct erasablepq {\n    priority_queue<T> pq, del;\n    void push(const\
    \ T& x) {\n        pq.push(x);\n        normalize();\n    }\n    void erase(const\
    \ T& x) {\n        del.push(x);\n        normalize();\n    }\n    void pop() {\n\
    \        pq.pop();\n        normalize();\n    }\n    T top() {\n        return\
    \ pq.top();\n        normalize();\n    }\n    bool empty() {\n        return pq.empty();\n\
    \        normalize();\n    }\n    int size() {\n        return pq.size() - del.size();\n\
    \    }\n    void normalize() {\n        while (!del.empty() && !pq.empty() &&\
    \ pq.top() == del.top()) {\n            pq.pop();\n            del.pop();\n  \
    \      }\n    }\n};\n\ntemplate <class T>\nstruct erasablepqg {\n    priority_queue<T,\
    \ vector<T>, greater<T>> pq, del;\n    void push(const T& x) {\n        pq.push(x);\n\
    \        normalize();\n    }\n    void erase(const T& x) {\n        del.push(x);\n\
    \        normalize();\n    }\n    void pop() {\n        pq.pop();\n        normalize();\n\
    \    }\n    T top() {\n        return pq.top();\n        normalize();\n    }\n\
    \    bool empty() {\n        return pq.empty();\n        normalize();\n    }\n\
    \    int size() {\n        return pq.size() - del.size();\n    }\n    void normalize()\
    \ {\n        while (!del.empty() && !pq.empty() && pq.top() == del.top()) {\n\
    \            pq.pop();\n            del.pop();\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/erasablepq.hpp
  requiredBy:
  - structure/bipq.hpp
  timestamp: '2025-11-18 00:25:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/erasablepq.hpp
layout: document
redirect_from:
- /library/structure/erasablepq.hpp
- /library/structure/erasablepq.hpp.html
title: structure/erasablepq.hpp
---
