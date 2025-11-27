---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: util/generalsegtree.hpp
    title: util/generalsegtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-predecessor_problem-2.test.cpp
    title: verify/yosupo-predecessor_problem-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_sum-1.test.cpp
    title: verify/yosupo-static_range_sum-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-staticrmq-2.test.cpp
    title: verify/yosupo-staticrmq-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// op(op(a, b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\
    \u3064\u5FC5\u8981\u304C\u3042\u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto\
    \ op, auto e>\nstruct segtree {\n    int _n, size;\n    vector<S> data;\n    segtree()\
    \ = default;\n    // \u5927\u304D\u3055n \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \ O(n)\n    explicit segtree(int n) : _n(n) { build(vector<S>(n, e())); }\n  \
    \  // \u5927\u304D\u3055v.size() \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n\
    \    explicit segtree(const vector<S>& v) : _n(v.size()) { build(v); }\n    void\
    \ build(const vector<S>& v) {\n        size = __bit_ceil((unsigned int)_n);\n\
    \        data.assign(2 * size, e());\n        for (int i=0; i<_n; i++) data[size+i]\
    \ = v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n    // p \u756A\
    \u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        data[p]\
    \ = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n    }\n    // p \u756A\u76EE\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S get(int p) const\
    \ {\n        assert(0 <= p && p < _n);\n        return data[size+p];\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n\
    \    S operator[](int p) const { return get(p); }\n    // [l, r) \u306E\u533A\u9593\
    \u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r)\
    \ const {\n        assert(0<=l && l<=r && r<=_n);\n        S ll = e(), rr = e();\n\
    \        l += size;\n        r += size;\n        while (l < r) {\n           \
    \ if (l & 1) ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r],\
    \ rr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(ll, rr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B O(1)\n    S all_prod() const { return data.size() > 1 ? data[1] : e();\
    \ }\n    // [0, _n) \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(n)\n    vector<S> values() const {\n        vector<S> re(_n);\n        for\
    \ (int i=0; i<_n; i++) re[i] = data[size+i];\n        return re;\n    }\n    void\
    \ update(int p) { data[p] = op(data[2*p], data[2*p+1]); }\n    // f(op([l, r)))==true\
    \ \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059\n    template <class\
    \ F>\n    int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, data[l]))) {\n                while (l < size) {\n\
    \                    l = (2 * l);\n                    if (f(op(sm, data[l])))\
    \ {\n                        sm = op(sm, data[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, data[l]);\n            l++;\n        }\
    \ while ((l & -l) != l);\n        return _n;\n    }\n    // f(op([l, r)))==true\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\u3059\n    template <class\
    \ F>\n    int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(data[r], sm))) {\n             \
    \   while (r < size) {\n                    r = (2 * r + 1);\n               \
    \     if (f(op(data[r], sm))) {\n                        sm = op(data[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(data[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// op(op(a,\
    \ b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\
    \u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto op, auto e>\nstruct segtree\
    \ {\n    int _n, size;\n    vector<S> data;\n    segtree() = default;\n    //\
    \ \u5927\u304D\u3055n \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    explicit\
    \ segtree(int n) : _n(n) { build(vector<S>(n, e())); }\n    // \u5927\u304D\u3055\
    v.size() \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    explicit segtree(const\
    \ vector<S>& v) : _n(v.size()) { build(v); }\n    void build(const vector<S>&\
    \ v) {\n        size = __bit_ceil((unsigned int)_n);\n        data.assign(2 *\
    \ size, e());\n        for (int i=0; i<_n; i++) data[size+i] = v[i];\n       \
    \ for (int i=size-1; 0<i; i--) update(i);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += size;\n        data[p] = x;\n     \
    \   for (p>>=1; 0<p; p>>=1) update(p);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S get(int p) const {\n        assert(0\
    \ <= p && p < _n);\n        return data[size+p];\n    }\n    // p \u756A\u76EE\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S operator[](int p)\
    \ const { return get(p); }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r) const {\n        assert(0<=l\
    \ && l<=r && r<=_n);\n        S ll = e(), rr = e();\n        l += size;\n    \
    \    r += size;\n        while (l < r) {\n            if (l & 1) ll = op(ll, data[l++]);\n\
    \            if (r & 1) rr = op(data[--r], rr);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n        return op(ll, rr);\n    }\n    // [0, _n)\
    \ \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n    S all_prod() const\
    \ { return data.size() > 1 ? data[1] : e(); }\n    // [0, _n) \u306E\u533A\u9593\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S> values() const\
    \ {\n        vector<S> re(_n);\n        for (int i=0; i<_n; i++) re[i] = data[size+i];\n\
    \        return re;\n    }\n    void update(int p) { data[p] = op(data[2*p], data[2*p+1]);\
    \ }\n    // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\
    \u3059\n    template <class F>\n    int max_right(int l, F f) const {\n      \
    \  assert(0 <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return\
    \ _n;\n        l += size;\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, data[l]))) {\n            \
    \    while (l < size) {\n                    l = (2 * l);\n                  \
    \  if (f(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \    // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\
    \u3059\n    template <class F>\n    int min_left(int r, F f) const {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(data[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(data[r], sm))) {\n                     \
    \   sm = op(data[r], sm);\n                        r--;\n                    }\n\
    \                }\n                return r + 1 - size;\n            }\n    \
    \        sm = op(data[r], sm);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy:
  - util/generalsegtree.hpp
  timestamp: '2025-11-27 11:42:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-static_range_sum-1.test.cpp
  - verify/yosupo-predecessor_problem-2.test.cpp
  - verify/yosupo-staticrmq-2.test.cpp
documentation_of: structure/segtree.hpp
layout: document
redirect_from:
- /library/structure/segtree.hpp
- /library/structure/segtree.hpp.html
title: structure/segtree.hpp
---
