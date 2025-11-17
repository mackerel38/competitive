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
  bundledCode: "#line 2 \"structure/abstractBIT.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T, auto op, auto iop>\nstruct abstractBIT {\n\
    \    int _n;\n    T _e;\n    vector<T> data;\n    abstractBIT() = default;\n \
    \   // \u62BD\u8C61\u5316BIT \u3092\u69CB\u7BC9\u3059\u308B O(n)\n    abstractBIT(int\
    \ n, T e = T{}) : _n(n), data(_n), _e(e) {}\n    // p \u756A\u76EE\u306E\u5024\
    \u306Bx \u3092\u52A0\u7B97\u3059\u308B O(log n)\n    void add(int p, T x) {\n\
    \        assert(0 <= p && p < _n);\n        p++;\n        while (p <= _n) {\n\
    \            data[p-1] = op(data[p-1], x);\n            p += p & -p;\n       \
    \ }\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092x \u306B\u3059\u308B O(log\
    \ n)\n    void set(int p, T x) {\n        assert(0 <= p && p < _n);\n        data[p]\
    \ = x;\n        p++;\n        p += p & -p;\n        while (p <= _n) {\n      \
    \      data[p-1] = op(data[p-1], x);\n            p += p & -p;\n        }\n  \
    \  }\n    // [0, r) \u306E\u7DCF\u548C \u3092\u6C42\u3081\u308B O(log n)\n   \
    \ T sum(int r) {\n        assert(0 <= r &&  r <= _n);\n        T re = T{};\n \
    \       while (0 < r) {\n            re = op(re, data[r-1]);\n            r -=\
    \ r & -r;\n        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCFxor\
    \ \u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r) {\n        assert(l\
    \ <= r);\n        return iop(sum(r), sum(l));\n    }\n    // p \u756A\u76EE\u306E\
    \u5024\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T get(int p) {\n        return\
    \ iop(sum(p+1), sum(p));\n    }\n    T operator[](int p) {\n        return get(p);\n\
    \    }\n    // \u5168\u4F53\u306E\u7DCFxor \u3092\u53D6\u5F97\u3059\u308B O(log\
    \ n)\n    T all_sum() {\n        return sum(_n);\n    }\n    // [l, r) \u306B\
    x \u3092\u52A0\u7B97\u3059\u308B \u4E00\u70B9\u53D6\u5F97\u306Fsum(p) \u3067\u884C\
    \u3046 \u533A\u9593\u548C\u30AF\u30A8\u30EA\u304C\u3067\u304D\u306A\u304F\u306A\
    \u308B\u306E\u3067\u6CE8\u610FO(log n)\n    void imos(int l, int r, T x) {\n \
    \       add(l, x);\n        if (r < _n) add(r, x);\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ T, auto op, auto iop>\nstruct abstractBIT {\n    int _n;\n    T _e;\n    vector<T>\
    \ data;\n    abstractBIT() = default;\n    // \u62BD\u8C61\u5316BIT \u3092\u69CB\
    \u7BC9\u3059\u308B O(n)\n    abstractBIT(int n, T e = T{}) : _n(n), data(_n),\
    \ _e(e) {}\n    // p \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\u308B\
    \ O(log n)\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n  \
    \      p++;\n        while (p <= _n) {\n            data[p-1] = op(data[p-1],\
    \ x);\n            p += p & -p;\n        }\n    }\n    // p \u756A\u76EE\u306E\
    \u5024\u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, T x) {\n      \
    \  assert(0 <= p && p < _n);\n        data[p] = x;\n        p++;\n        p +=\
    \ p & -p;\n        while (p <= _n) {\n            data[p-1] = op(data[p-1], x);\n\
    \            p += p & -p;\n        }\n    }\n    // [0, r) \u306E\u7DCF\u548C\
    \ \u3092\u6C42\u3081\u308B O(log n)\n    T sum(int r) {\n        assert(0 <= r\
    \ &&  r <= _n);\n        T re = T{};\n        while (0 < r) {\n            re\
    \ = op(re, data[r-1]);\n            r -= r & -r;\n        }\n        return re;\n\
    \    }\n    // [l, r) \u306E\u7DCFxor \u3092\u6C42\u3081\u308B O(log n)\n    T\
    \ sum(int l, int r) {\n        assert(l <= r);\n        return iop(sum(r), sum(l));\n\
    \    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log\
    \ n)\n    T get(int p) {\n        return iop(sum(p+1), sum(p));\n    }\n    T\
    \ operator[](int p) {\n        return get(p);\n    }\n    // \u5168\u4F53\u306E\
    \u7DCFxor \u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T all_sum() {\n       \
    \ return sum(_n);\n    }\n    // [l, r) \u306Bx \u3092\u52A0\u7B97\u3059\u308B\
    \ \u4E00\u70B9\u53D6\u5F97\u306Fsum(p) \u3067\u884C\u3046 \u533A\u9593\u548C\u30AF\
    \u30A8\u30EA\u304C\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\u6CE8\u610F\
    O(log n)\n    void imos(int l, int r, T x) {\n        add(l, x);\n        if (r\
    \ < _n) add(r, x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/abstractBIT.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/abstractBIT.hpp
layout: document
redirect_from:
- /library/structure/abstractBIT.hpp
- /library/structure/abstractBIT.hpp.html
title: structure/abstractBIT.hpp
---
