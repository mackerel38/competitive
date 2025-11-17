---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-range_affine_point_get.test.cpp
    title: verify/yosupo-range_affine_point_get.test.cpp
  - icon: ':x:'
    path: verify/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/lazysegtree.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate<class S, auto op, class F, auto mapping, auto composition>\n\
    struct lazysegtree {\n    int _n, size, sz;\n    S _e;\n    F _id;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n    lazysegtree() = default;\n    // \u5927\u304D\
    \u3055n, \u5358\u4F4D\u5143e, id(\u7701\u7565\u3059\u308B\u3068S{}, F{} \u306B\
    \u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int\
    \ n, S e = S{}, F id = F{}) : _n(n), _e(e), _id(id) { build(vector<S>(n, _e));\
    \ }\n    // \u5927\u304D\u3055v.size(), \u5358\u4F4D\u5143e, id(\u7701\u7565\u3059\
    \u308B\u3068S{}, F{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \ O(n)\n    lazysegtree(vector<S>& v, S e = S{}, F id = F{}) : _n(v.size()), _e(e),\
    \ _id(id) { build(v); }\n    void build(vector<S> v) {\n        size = __bit_ceil((unsigned\
    \ int)_n);\n        sz = __countr_zero(size);\n        data.assign(2 * size, _e);\n\
    \        lazy.assign(2 * size, _id);\n        for (int i=0; i<_n; i++) data[size+i]\
    \ = v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n    void update(int\
    \ k) {\n        data[k] = op(data[2*k], data[2*k+1]);\n    }\n    void all_apply(int\
    \ k, F f) {\n        data[k] = mapping(f, data[k]);\n        if (k < size) lazy[k]\
    \ = composition(f, lazy[k]);\n    }\n    void push(int k) {\n        all_apply(2*k,\
    \ lazy[k]);\n        all_apply(2*k+1, lazy[k]);\n        lazy[k] = _id;\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i=sz; 0<i; i--) push(p >> i);\n        data[p] = x;\n      \
    \  for (int i=p>>1; 0<i; i>>=1) update(i);\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S get(int p) {\n    \
    \    assert(0 <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i;\
    \ i--) push(p >> i);\n        return data[p];\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S operator[](int p) {\n\
    \        return get(p);\n    }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return _e;\n        l += size;\n\
    \        r += size;\n        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l)\
    \ push(l >> i);\n        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        S ll = _e, rr = _e;\n        while (l < r) {\n        \
    \    if (l & 1) ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r],\
    \ rr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(ll, rr);\n    }\n    // [0, n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B O(1)\n    S all_prod() {\n        return data[1];\n    }\n    // [0, n)\
    \ \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S>\
    \ values() {\n        vector<S> re(_n);\n        for (int i=0; i<size; i++) {\n\
    \            if (lazy[i] != _id) push(i);\n        }\n        for (int i=0; i<_n;\
    \ i++) re[i] = data[size+i];\n        return re;\n    }\n    // [l, r) \u306B\u5BFE\
    \u3057\u3066 f \u3092\u9069\u7528\u3059\u308B O(log n)\n    void apply(int l,\
    \ int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return;\n        l += size;\n        r += size;\n        for (int i=sz; 0<i;\
    \ i--) if (((l >> i) << i) != l) push(l >> i);\n        for (int i=sz; 0<i; i--)\
    \ if (((r >> i) << i) != r) push((r - 1) >> i);\n        int ll = l, rr = r;\n\
    \        while (ll < rr) {\n            if (ll & 1) all_apply(ll++, f);\n    \
    \        if (rr & 1) all_apply(--rr, f);\n            ll >>= 1;\n            rr\
    \ >>= 1;\n        }\n        for (int i=1; i<=sz; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class\
    \ S, auto op, class F, auto mapping, auto composition>\nstruct lazysegtree {\n\
    \    int _n, size, sz;\n    S _e;\n    F _id;\n    vector<S> data;\n    vector<F>\
    \ lazy;\n    lazysegtree() = default;\n    // \u5927\u304D\u3055n, \u5358\u4F4D\
    \u5143e, id(\u7701\u7565\u3059\u308B\u3068S{}, F{} \u306B\u306A\u308B) \u306E\u30BB\
    \u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int n, S e = S{}, F id =\
    \ F{}) : _n(n), _e(e), _id(id) { build(vector<S>(n, _e)); }\n    // \u5927\u304D\
    \u3055v.size(), \u5358\u4F4D\u5143e, id(\u7701\u7565\u3059\u308B\u3068S{}, F{}\
    \ \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(vector<S>&\
    \ v, S e = S{}, F id = F{}) : _n(v.size()), _e(e), _id(id) { build(v); }\n   \
    \ void build(vector<S> v) {\n        size = __bit_ceil((unsigned int)_n);\n  \
    \      sz = __countr_zero(size);\n        data.assign(2 * size, _e);\n       \
    \ lazy.assign(2 * size, _id);\n        for (int i=0; i<_n; i++) data[size+i] =\
    \ v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n    void update(int\
    \ k) {\n        data[k] = op(data[2*k], data[2*k+1]);\n    }\n    void all_apply(int\
    \ k, F f) {\n        data[k] = mapping(f, data[k]);\n        if (k < size) lazy[k]\
    \ = composition(f, lazy[k]);\n    }\n    void push(int k) {\n        all_apply(2*k,\
    \ lazy[k]);\n        all_apply(2*k+1, lazy[k]);\n        lazy[k] = _id;\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i=sz; 0<i; i--) push(p >> i);\n        data[p] = x;\n      \
    \  for (int i=p>>1; 0<i; i>>=1) update(i);\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S get(int p) {\n    \
    \    assert(0 <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i;\
    \ i--) push(p >> i);\n        return data[p];\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S operator[](int p) {\n\
    \        return get(p);\n    }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return _e;\n        l += size;\n\
    \        r += size;\n        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l)\
    \ push(l >> i);\n        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        S ll = _e, rr = _e;\n        while (l < r) {\n        \
    \    if (l & 1) ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r],\
    \ rr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(ll, rr);\n    }\n    // [0, n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B O(1)\n    S all_prod() {\n        return data[1];\n    }\n    // [0, n)\
    \ \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S>\
    \ values() {\n        vector<S> re(_n);\n        for (int i=0; i<size; i++) {\n\
    \            if (lazy[i] != _id) push(i);\n        }\n        for (int i=0; i<_n;\
    \ i++) re[i] = data[size+i];\n        return re;\n    }\n    // [l, r) \u306B\u5BFE\
    \u3057\u3066 f \u3092\u9069\u7528\u3059\u308B O(log n)\n    void apply(int l,\
    \ int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return;\n        l += size;\n        r += size;\n        for (int i=sz; 0<i;\
    \ i--) if (((l >> i) << i) != l) push(l >> i);\n        for (int i=sz; 0<i; i--)\
    \ if (((r >> i) << i) != r) push((r - 1) >> i);\n        int ll = l, rr = r;\n\
    \        while (ll < rr) {\n            if (ll & 1) all_apply(ll++, f);\n    \
    \        if (rr & 1) all_apply(--rr, f);\n            ll >>= 1;\n            rr\
    \ >>= 1;\n        }\n        for (int i=1; i<=sz; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-range_affine_range_sum.test.cpp
  - verify/yosupo-range_affine_point_get.test.cpp
documentation_of: structure/lazysegtree.hpp
layout: document
redirect_from:
- /library/structure/lazysegtree.hpp
- /library/structure/lazysegtree.hpp.html
title: structure/lazysegtree.hpp
---
