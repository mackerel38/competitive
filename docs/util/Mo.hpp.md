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
  bundledCode: "#line 2 \"util/Mo.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n// Mo's algorithm\nstruct Mo {\n    int n;\n    vector<pair<int, int>>\
    \ queries;\n    explicit Mo(int n) : n(n) {}\n    // \u30AF\u30A8\u30EA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add(int l, int r) {\n        queries.push_back({l,\
    \ r});\n    }\n    void add(vector<pair<int, int>>& qs) {\n        for(auto& q\
    \ : qs) {\n            queries.push_back(q);\n        }\n    }\n    long long\
    \ hilbert_order(int x, int y, int p=20, int rotate = 0) {\n        long long d\
    \ = 0;\n        for (int s=1<<(p-1); 0<s; s>>=1) {\n            int rx = 0 < (x\
    \ & s);\n            int ry = 0 < (y & s);\n            int r = (rx << 1) | ry;\n\
    \            r = (r + rotate) & 3;\n            d = (d << 2) | r;\n          \
    \  const int rd[4] = {3, 0, 0, 1};\n            rotate = (rotate + rd[r]) & 3;\n\
    \        }\n        return d;\n    }\n    // \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\
    \u3059\u308B O((n+q) sqrt(n))\n    template <class AL, class AR, class EL, class\
    \ ER, class OUT>\n    void build(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER &erase_right, const OUT &out) {\n        int q = queries.size();\n\
    \        vector<int> ord(q);\n        iota(begin(ord), end(ord), 0);\n       \
    \ vector<long long> hs(q);\n        for (int i=0; i<q; i++) {\n            hs[i]\
    \ = hilbert_order(queries[i].first, queries[i].second);\n        }\n        sort(begin(ord),\
    \ end(ord), [&](int a, int b) {\n            return hs[a] < hs[b];\n        });\n\
    \        int l = 0, r = 0;\n        for(auto idx : ord) {\n            while(l\
    \ > queries[idx].first) add_left(--l);\n            while(r < queries[idx].second)\
    \ add_right(r++);\n            while(l < queries[idx].first) erase_left(l++);\n\
    \            while(r > queries[idx].second) erase_right(--r);\n            out(idx);\n\
    \        }\n    }\n    // \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B O((n+q)\
    \ sqrt(n))\n    template <class A, class E, class OUT>\n    void build(const A\
    \ &add, const E &erase, const OUT &out) {\n        build(add, add, erase, erase,\
    \ out);\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// Mo's algorithm\n\
    struct Mo {\n    int n;\n    vector<pair<int, int>> queries;\n    explicit Mo(int\
    \ n) : n(n) {}\n    // \u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\u3059\u308B\n    void\
    \ add(int l, int r) {\n        queries.push_back({l, r});\n    }\n    void add(vector<pair<int,\
    \ int>>& qs) {\n        for(auto& q : qs) {\n            queries.push_back(q);\n\
    \        }\n    }\n    long long hilbert_order(int x, int y, int p=20, int rotate\
    \ = 0) {\n        long long d = 0;\n        for (int s=1<<(p-1); 0<s; s>>=1) {\n\
    \            int rx = 0 < (x & s);\n            int ry = 0 < (y & s);\n      \
    \      int r = (rx << 1) | ry;\n            r = (r + rotate) & 3;\n          \
    \  d = (d << 2) | r;\n            const int rd[4] = {3, 0, 0, 1};\n          \
    \  rotate = (rotate + rd[r]) & 3;\n        }\n        return d;\n    }\n    //\
    \ \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B O((n+q) sqrt(n))\n    template\
    \ <class AL, class AR, class EL, class ER, class OUT>\n    void build(const AL\
    \ &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right,\
    \ const OUT &out) {\n        int q = queries.size();\n        vector<int> ord(q);\n\
    \        iota(begin(ord), end(ord), 0);\n        vector<long long> hs(q);\n  \
    \      for (int i=0; i<q; i++) {\n            hs[i] = hilbert_order(queries[i].first,\
    \ queries[i].second);\n        }\n        sort(begin(ord), end(ord), [&](int a,\
    \ int b) {\n            return hs[a] < hs[b];\n        });\n        int l = 0,\
    \ r = 0;\n        for(auto idx : ord) {\n            while(l > queries[idx].first)\
    \ add_left(--l);\n            while(r < queries[idx].second) add_right(r++);\n\
    \            while(l < queries[idx].first) erase_left(l++);\n            while(r\
    \ > queries[idx].second) erase_right(--r);\n            out(idx);\n        }\n\
    \    }\n    // \u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B O((n+q) sqrt(n))\n\
    \    template <class A, class E, class OUT>\n    void build(const A &add, const\
    \ E &erase, const OUT &out) {\n        build(add, add, erase, erase, out);\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/Mo.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/Mo.hpp
layout: document
redirect_from:
- /library/util/Mo.hpp
- /library/util/Mo.hpp.html
title: util/Mo.hpp
---
