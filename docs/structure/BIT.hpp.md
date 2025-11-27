---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_sum-2.test.cpp
    title: verify/yosupo-static_range_sum-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<class T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n\
    \    BIT() = default;\n    // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(int n) : _n(n),\
    \ data(_n, T{}) {}\n    // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(vector<T>& v)\
    \ : _n((int)v.size()), data(v) {\n        for (int i=1; i<=_n; i++) {\n      \
    \      int j = i+(i&-i);\n            if (j <= _n) data[j-1] += data[i-1];\n \
    \       }\n    }\n    // p \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\
    \u308B O(log n)\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n\
    \        int i = p + 1;\n        while (i <= _n) {\n            data[i-1] += x;\n\
    \            i += i & -i;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\
    \u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, T x) { add(p, x - get(p));\
    \ }\n    // [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log n)\n    T\
    \ sum(int r) const {\n        assert(0 <= r && r <= _n);\n        T re = T{};\n\
    \        int i = r;\n        while (i > 0) {\n            re += data[i-1];\n \
    \           i -= i & -i;\n        }\n        return re;\n    }\n    // [l, r)\
    \ \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r)\
    \ - sum(l);\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(log n)\n    T get(int p) const { return sum(p+1) - sum(p); }\n    // p \u756A\
    \u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T operator[](int\
    \ p) const { return get(p); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n    BIT() = default;\n \
    \   // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(int n) : _n(n), data(_n, T{}) {}\n\
    \    // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(vector<T>& v) : _n((int)v.size()),\
    \ data(v) {\n        for (int i=1; i<=_n; i++) {\n            int j = i+(i&-i);\n\
    \            if (j <= _n) data[j-1] += data[i-1];\n        }\n    }\n    // p\
    \ \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\u308B O(log n)\n  \
    \  void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        int i =\
    \ p + 1;\n        while (i <= _n) {\n            data[i-1] += x;\n           \
    \ i += i & -i;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092x \u306B\
    \u3059\u308B O(log n)\n    void set(int p, T x) { add(p, x - get(p)); }\n    //\
    \ [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int r)\
    \ const {\n        assert(0 <= r && r <= _n);\n        T re = T{};\n        int\
    \ i = r;\n        while (i > 0) {\n            re += data[i-1];\n            i\
    \ -= i & -i;\n        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r) const {\n   \
    \     assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log\
    \ n)\n    T get(int p) const { return sum(p+1) - sum(p); }\n    // p \u756A\u76EE\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T operator[](int p) const\
    \ { return get(p); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2025-11-27 14:20:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-static_range_sum-2.test.cpp
documentation_of: structure/BIT.hpp
layout: document
redirect_from:
- /library/structure/BIT.hpp
- /library/structure/BIT.hpp.html
title: structure/BIT.hpp
---
