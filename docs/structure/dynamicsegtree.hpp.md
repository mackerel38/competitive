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
  bundledCode: "#line 2 \"structure/dynamicsegtree.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n// op(op(a, b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\
    \u3064\u5FC5\u8981\u304C\u3042\u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto\
    \ op, auto e>\nstruct dynamicsegtree {\n    long long _n, size;\n    unordered_map<long\
    \ long, S> data;\n    dynamicsegtree() = default;\n    // \u5927\u304D\u3055n,\
    \ \u5358\u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068S{} \u306B\u306A\u308B) \u306E\
    \u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(log n)\n    dynamicsegtree(long long n)\
    \ : _n(n) {\n        size = 1;\n        while (size < _n) size <<= 1;\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(long long p, S x) {\n        assert(0 <= p && p < _n);\n       \
    \ p += size;\n        data[p] = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S get(long long p) {\n        assert(0 <= p && p < _n);\n        return\
    \ data[size+p];\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B O(1)\n    S operator[](long long p) {\n        return get(p);\n \
    \   }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\
    \ O(log n)\n    S prod(long long l, long long r) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n   \
    \     r += size;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ data.count(l) ? data[l] : e()), ++l;\n            if (r & 1) --r, smr = op(data.count(r)\
    \ ? data[r] : e(), smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n        return op(sml, smr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(1)\n    S all_prod() {\n        return data[1];\n \
    \   }\n    void update(long long p) {\n        S l = e(), r = e();\n        if\
    \ (data.count(2*p)) l = data[2*p];\n        if (data.count(2*p+1)) r = data[2*p+1];\n\
    \        data[p] = op(l, r);\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// op(op(a,\
    \ b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\
    \u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto op, auto e>\nstruct dynamicsegtree\
    \ {\n    long long _n, size;\n    unordered_map<long long, S> data;\n    dynamicsegtree()\
    \ = default;\n    // \u5927\u304D\u3055n, \u5358\u4F4D\u5143e(\u7701\u7565\u3059\
    \u308B\u3068S{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \ O(log n)\n    dynamicsegtree(long long n) : _n(n) {\n        size = 1;\n   \
    \     while (size < _n) size <<= 1;\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\
    \u3092x \u306B\u3059\u308B O(log n)\n    void set(long long p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += size;\n        data[p] = x;\n     \
    \   for (p>>=1; 0<p; p>>=1) update(p);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S get(long long p) {\n        assert(0\
    \ <= p && p < _n);\n        return data[size+p];\n    }\n    // p \u756A\u76EE\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S operator[](long long\
    \ p) {\n        return get(p);\n    }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S prod(long long l, long long r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr =\
    \ e();\n        l += size;\n        r += size;\n        while (l < r) {\n    \
    \        if (l & 1) sml = op(sml, data.count(l) ? data[l] : e()), ++l;\n     \
    \       if (r & 1) --r, smr = op(data.count(r) ? data[r] : e(), smr);\n      \
    \      l >>= 1;\n            r >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n\
    \    S all_prod() {\n        return data[1];\n    }\n    void update(long long\
    \ p) {\n        S l = e(), r = e();\n        if (data.count(2*p)) l = data[2*p];\n\
    \        if (data.count(2*p+1)) r = data[2*p+1];\n        data[p] = op(l, r);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamicsegtree.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/dynamicsegtree.hpp
layout: document
redirect_from:
- /library/structure/dynamicsegtree.hpp
- /library/structure/dynamicsegtree.hpp.html
title: structure/dynamicsegtree.hpp
---
