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
  bundledCode: "#line 2 \"structure/dynamicUnionFind.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nstruct dynamicUnionFind {\n    long long _n;\n    unordered_map<long\
    \ long, long long> data;\n    dynamicUnionFind() = default;\n    // n \u500B\u306E\
    \u8981\u7D20\u304B\u3089\u306A\u308BdynamicUnionFind \u3092\u69CB\u7BC9 O(1)\n\
    \    dynamicUnionFind(long long n) : _n(n) {}\n    // 2 \u3064\u306E\u8981\u7D20\
    \u3092\u4F75\u5408 O(\u03B1(n))\n    bool merge(long long p, long long q) {\n\
    \        p = root(p);\n        q = root(q);\n        if (p == q) return false;\n\
    \        if (q < p) swap(p, q);\n        data[p] += data[q];\n        data[q]\
    \ = p;\n        return true;\n    }\n    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97\
    \ O(\u03B1(n))\n    long long root(long long p) {\n        assert(0 <= p && p\
    \ < _n);\n        if (!data.count(p)) {\n            data[p] = -1;\n        }\n\
    \        if (data[p] < 0) {\n            return p;\n        } else {\n       \
    \     data[p] = root(data[p]);\n            return data[p];\n        }\n    }\n\
    \    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n    long long operator[](long\
    \ long p) {\n        return root(p);\n    }\n    // 2 \u3064\u306E\u8981\u7D20\
    \u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\
    \ O(\u03B1(n))\n    bool same(long long p, long long q) {\n        return root(p)\
    \ == root(q);\n    }\n    // \u8981\u7D20\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\
    \u5927\u304D\u3055\u3092\u8FD4\u3059 O(\u03B1(n))\n    long long size(long long\
    \ p) {\n        return -data[root(p)];\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nstruct dynamicUnionFind\
    \ {\n    long long _n;\n    unordered_map<long long, long long> data;\n    dynamicUnionFind()\
    \ = default;\n    // n \u500B\u306E\u8981\u7D20\u304B\u3089\u306A\u308BdynamicUnionFind\
    \ \u3092\u69CB\u7BC9 O(1)\n    dynamicUnionFind(long long n) : _n(n) {}\n    //\
    \ 2 \u3064\u306E\u8981\u7D20\u3092\u4F75\u5408 O(\u03B1(n))\n    bool merge(long\
    \ long p, long long q) {\n        p = root(p);\n        q = root(q);\n       \
    \ if (p == q) return false;\n        if (q < p) swap(p, q);\n        data[p] +=\
    \ data[q];\n        data[q] = p;\n        return true;\n    }\n    // \u89AA\u8981\
    \u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n    long long root(long long p) {\n   \
    \     assert(0 <= p && p < _n);\n        if (!data.count(p)) {\n            data[p]\
    \ = -1;\n        }\n        if (data[p] < 0) {\n            return p;\n      \
    \  } else {\n            data[p] = root(data[p]);\n            return data[p];\n\
    \        }\n    }\n    // \u89AA\u8981\u7D20\u3092\u53D6\u5F97 O(\u03B1(n))\n\
    \    long long operator[](long long p) {\n        return root(p);\n    }\n   \
    \ // 2 \u3064\u306E\u8981\u7D20\u304C\u540C\u3058\u96C6\u5408\u306B\u542B\u307E\
    \u308C\u308B\u304B\u5224\u5B9A O(\u03B1(n))\n    bool same(long long p, long long\
    \ q) {\n        return root(p) == root(q);\n    }\n    // \u8981\u7D20\u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059 O(\u03B1(n))\n\
    \    long long size(long long p) {\n        return -data[root(p)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamicUnionFind.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/dynamicUnionFind.hpp
layout: document
redirect_from:
- /library/structure/dynamicUnionFind.hpp
- /library/structure/dynamicUnionFind.hpp.html
title: structure/dynamicUnionFind.hpp
---
