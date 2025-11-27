---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum-3.test.cpp
    title: verify/yosupo-point_add_range_sum-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite-2.test.cpp
    title: verify/yosupo-point_set_range_composite-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_point_get-1.test.cpp
    title: verify/yosupo-range_affine_point_get-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum-1.test.cpp
    title: verify/yosupo-range_affine_range_sum-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_sum-3.test.cpp
    title: verify/yosupo-static_range_sum-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-staticrmq-3.test.cpp
    title: verify/yosupo-staticrmq-3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/lazysegtree.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class S, auto op, auto e, class F, auto mapping,\
    \ auto composition, auto id>\nstruct lazysegtree {\n    int _n, size, sz;\n  \
    \  vector<S> data;\n    vector<F> lazy;\n    lazysegtree() = default;\n    //\
    \ \u5927\u304D\u3055n \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int\
    \ n) : _n(n) { build(vector<S>(n, e())); }\n    // \u5927\u304D\u3055v.size()\
    \ \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(vector<S>&\
    \ v) : _n((int)v.size()) { build(v); }\n    void build(vector<S> v) {\n      \
    \  size = __bit_ceil((unsigned int)_n);\n        sz = __countr_zero(size);\n \
    \       data.assign(2 * size, e());\n        lazy.assign(2 * size, id());\n  \
    \      for (int i=0; i<_n; i++) data[size+i] = v[i];\n        for (int i=size-1;\
    \ 0<i; i--) update(i);\n    }\n    void update(int k) { data[k] = op(data[2*k],\
    \ data[2*k+1]); }\n    void all_apply(int k, F f) {\n        data[k] = mapping(f,\
    \ data[k]);\n        if (k < size) lazy[k] = composition(f, lazy[k]);\n    }\n\
    \    void push(int k) {\n        all_apply(2*k, lazy[k]);\n        all_apply(2*k+1,\
    \ lazy[k]);\n        lazy[k] = id();\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i;\
    \ i--) push(p >> i);\n        data[p] = x;\n        for (int i=p>>1; 0<i; i>>=1)\
    \ update(i);\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B O(log n)\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i=sz; 0<i; i--) push(p >> i);\n        return\
    \ data[p];\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B O(log n)\n    S operator[](int p) { return get(p); }\n    // [l, r) \u306E\
    \u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n        l += size;\n        r += size;\n        for (int i=sz;\
    \ 0<i; i--) if (((l >> i) << i) != l) push(l >> i);\n        for (int i=sz; 0<i;\
    \ i--) if (((r >> i) << i) != r) push((r - 1) >> i);\n        S ll = e(), rr =\
    \ e();\n        while (l < r) {\n            if (l & 1) ll = op(ll, data[l++]);\n\
    \            if (r & 1) rr = op(data[--r], rr);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n        return op(ll, rr);\n    }\n    // [0, n) \u306E\
    \u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n    S all_prod() const { return\
    \ data[1]; }\n    // [0, n) \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\
    \u308B O(n)\n    vector<S> values() {\n        vector<S> re(_n);\n        for\
    \ (int i=0; i<size; i++) if (lazy[i] != id()) push(i);\n        for (int i=0;\
    \ i<_n; i++) re[i] = data[size+i];\n        return re;\n    }\n    // [l, r) \u306B\
    \u5BFE\u3057\u3066 f \u3092\u9069\u7528\u3059\u308B O(log n)\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l\
    \ == r) return;\n        l += size;\n        r += size;\n        for (int i=sz;\
    \ 0<i; i--) if (((l >> i) << i) != l) push(l >> i);\n        for (int i=sz; 0<i;\
    \ i--) if (((r >> i) << i) != r) push((r - 1) >> i);\n        int ll = l, rr =\
    \ r;\n        while (ll < rr) {\n            if (ll & 1) all_apply(ll++, f);\n\
    \            if (rr & 1) all_apply(--rr, f);\n            ll >>= 1;\n        \
    \    rr >>= 1;\n        }\n        for (int i=1; i<=sz; i++) {\n            if\
    \ (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r)\
    \ update((r - 1) >> i);\n        }\n    }\n    // f(op([l, r)))==true \u3068\u306A\
    \u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059\n    template<class G>\n    int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if (l == _n) return _n;\n        l += size;\n        for (int i=sz; i >=\
    \ 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, data[l]))) {\n            \
    \    while (l < size) {\n                    push(l);\n                    l =\
    \ (2 * l);\n                    if (g(op(sm, data[l]))) {\n                  \
    \      sm = op(sm, data[l]);\n                        l++;\n                 \
    \   }\n                }\n                return l - size;\n            }\n  \
    \          sm = op(sm, data[l]);\n            l++;\n        } while ((l & -l)\
    \ != l);\n        return _n;\n    }\n    // f(op([l, r)))==true \u3068\u306A\u308B\
    \u6700\u5C0F\u306El \u3092\u8FD4\u3059\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n   \
    \     if (r == 0) return 0;\n        r += size;\n        for (int i=sz; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(data[r],\
    \ sm))) {\n                while (r < size) {\n                    push(r);\n\
    \                    r = (2 * r + 1);\n                    if (g(op(data[r], sm)))\
    \ {\n                        sm = op(data[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(data[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ S, auto op, auto e, class F, auto mapping, auto composition, auto id>\nstruct\
    \ lazysegtree {\n    int _n, size, sz;\n    vector<S> data;\n    vector<F> lazy;\n\
    \    lazysegtree() = default;\n    // \u5927\u304D\u3055n \u306E\u30BB\u30B0\u6728\
    \u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int n) : _n(n) { build(vector<S>(n, e()));\
    \ }\n    // \u5927\u304D\u3055v.size() \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9\
    \ O(n)\n    lazysegtree(vector<S>& v) : _n((int)v.size()) { build(v); }\n    void\
    \ build(vector<S> v) {\n        size = __bit_ceil((unsigned int)_n);\n       \
    \ sz = __countr_zero(size);\n        data.assign(2 * size, e());\n        lazy.assign(2\
    \ * size, id());\n        for (int i=0; i<_n; i++) data[size+i] = v[i];\n    \
    \    for (int i=size-1; 0<i; i--) update(i);\n    }\n    void update(int k) {\
    \ data[k] = op(data[2*k], data[2*k+1]); }\n    void all_apply(int k, F f) {\n\
    \        data[k] = mapping(f, data[k]);\n        if (k < size) lazy[k] = composition(f,\
    \ lazy[k]);\n    }\n    void push(int k) {\n        all_apply(2*k, lazy[k]);\n\
    \        all_apply(2*k+1, lazy[k]);\n        lazy[k] = id();\n    }\n    // p\
    \ \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void\
    \ set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n \
    \       for (int i=sz; 0<i; i--) push(p >> i);\n        data[p] = x;\n       \
    \ for (int i=p>>1; 0<i; i>>=1) update(i);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i; i--) push(p\
    \ >> i);\n        return data[p];\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S operator[](int p) { return get(p);\
    \ }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\
    \ O(log n)\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if (l == r) return e();\n        l += size;\n        r += size;\n\
    \        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >> i);\n  \
    \      for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        S ll = e(), rr = e();\n        while (l < r) {\n            if (l & 1)\
    \ ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r], rr);\n  \
    \          l >>= 1;\n            r >>= 1;\n        }\n        return op(ll, rr);\n\
    \    }\n    // [0, n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n\
    \    S all_prod() const { return data[1]; }\n    // [0, n) \u306E\u533A\u9593\u306E\
    \u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S> values() {\n        vector<S>\
    \ re(_n);\n        for (int i=0; i<size; i++) if (lazy[i] != id()) push(i);\n\
    \        for (int i=0; i<_n; i++) re[i] = data[size+i];\n        return re;\n\
    \    }\n    // [l, r) \u306B\u5BFE\u3057\u3066 f \u3092\u9069\u7528\u3059\u308B\
    \ O(log n)\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        if (l == r) return;\n        l += size;\n        r +=\
    \ size;\n        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >>\
    \ i);\n        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        int ll = l, rr = r;\n        while (ll < rr) {\n           \
    \ if (ll & 1) all_apply(ll++, f);\n            if (rr & 1) all_apply(--rr, f);\n\
    \            ll >>= 1;\n            rr >>= 1;\n        }\n        for (int i=1;\
    \ i<=sz; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n     \
    \       if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n  \
    \  // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059\
    \n    template<class G>\n    int max_right(int l, G g) {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(g(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        for (int i=sz; i >= 1; i--) push(l >> i);\n      \
    \  S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n      \
    \      if (!g(op(sm, data[l]))) {\n                while (l < size) {\n      \
    \              push(l);\n                    l = (2 * l);\n                  \
    \  if (g(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \    // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\
    \u3059\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i=sz; i >= 1; i--) push((r - 1) >> i);\n  \
    \      S sm = e();\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r % 2)) r >>= 1;\n            if (!g(op(data[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(data[r], sm))) {\n                       \
    \ sm = op(data[r], sm);\n                        r--;\n                    }\n\
    \                }\n                return r + 1 - size;\n            }\n    \
    \        sm = op(data[r], sm);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazysegtree.hpp
  requiredBy: []
  timestamp: '2025-11-27 18:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-point_add_range_sum-3.test.cpp
  - verify/yosupo-staticrmq-3.test.cpp
  - verify/yosupo-range_affine_point_get-1.test.cpp
  - verify/yosupo-point_set_range_composite-2.test.cpp
  - verify/yosupo-static_range_sum-3.test.cpp
  - verify/yosupo-range_affine_range_sum-1.test.cpp
documentation_of: structure/lazysegtree.hpp
layout: document
redirect_from:
- /library/structure/lazysegtree.hpp
- /library/structure/lazysegtree.hpp.html
title: structure/lazysegtree.hpp
---
