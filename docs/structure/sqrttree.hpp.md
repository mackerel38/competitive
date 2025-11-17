---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/sqrttree.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"math/isqrt.hpp\"\nusing namespace std;\n\n// floor(sqrt(n)) \u3092\u8FD4\
    \u3059\nlong long isqrt(long long n) {\n    assert(0 <= n);\n    long long re\
    \ = sqrt(n);\n    while ((re + 1) * (re + 1) <= n) re++;\n    while (n < re *\
    \ re) re--;\n    return re;\n}\n#line 4 \"structure/sqrttree.hpp\"\nusing namespace\
    \ std;\n\ntemplate <class S, auto op, auto e, class F, auto mapping, auto mapping2>\n\
    struct sqrttree {\n    int n, bsize, m;\n    vector<S> data, block;\n    sqrttree()\
    \ = default;\n    sqrttree(int n) : sqrttree(vector<S>(n, e())) {}\n    sqrttree(vector<S>\
    \ v) {\n        n = v.size();\n        bsize = isqrt(n) + 1;\n        m = bsize\
    \ * bsize;\n        data.reserve(m);\n        block.reserve(bsize);\n        for\
    \ (int i=0; i<bsize; i++) {\n            block[i] = e();\n            for (int\
    \ j=0; j<bsize; j++) {\n                int k = i * bsize + j;\n             \
    \   if (k < n) {\n                    data[k] = v[k];\n                } else\
    \ {\n                    data[k] = e();\n                }\n                block[i]\
    \ = op(block[i], data[k]);\n            }\n        }\n    }\n    void apply(int\
    \ i, F f) {\n        assert(0<=i && i<n);\n        data[i] = mapping(f, data[i]);\n\
    \        block[i/bsize] = mapping2(f, block[i/bsize]);\n    }\n    S get(int i)\
    \ {\n        assert(0 <= i && i < n);\n        return data[i];\n    }\n    S operator[](int\
    \ i) {\n        return get(i);\n    }\n    S prod(int l, int r) {\n        assert(0<=l\
    \ && l<=r && r<=n);\n        S re = e();\n        for (int i=0; i<bsize; i++)\
    \ {\n            if (r<=i*bsize || (i+1)*bsize<=l) continue;\n            if (l<=i*bsize\
    \ && (i+1)*bsize<=r) re = op(re, block[i]);\n            else {\n            \
    \    for (int j=0; j<bsize; j++) {\n                    int k = i * bsize + j;\n\
    \                    if (l<=k && k<r) {\n                        re = op(re, data[k]);\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ re;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"isqrt\"\nusing namespace\
    \ std;\n\ntemplate <class S, auto op, auto e, class F, auto mapping, auto mapping2>\n\
    struct sqrttree {\n    int n, bsize, m;\n    vector<S> data, block;\n    sqrttree()\
    \ = default;\n    sqrttree(int n) : sqrttree(vector<S>(n, e())) {}\n    sqrttree(vector<S>\
    \ v) {\n        n = v.size();\n        bsize = isqrt(n) + 1;\n        m = bsize\
    \ * bsize;\n        data.reserve(m);\n        block.reserve(bsize);\n        for\
    \ (int i=0; i<bsize; i++) {\n            block[i] = e();\n            for (int\
    \ j=0; j<bsize; j++) {\n                int k = i * bsize + j;\n             \
    \   if (k < n) {\n                    data[k] = v[k];\n                } else\
    \ {\n                    data[k] = e();\n                }\n                block[i]\
    \ = op(block[i], data[k]);\n            }\n        }\n    }\n    void apply(int\
    \ i, F f) {\n        assert(0<=i && i<n);\n        data[i] = mapping(f, data[i]);\n\
    \        block[i/bsize] = mapping2(f, block[i/bsize]);\n    }\n    S get(int i)\
    \ {\n        assert(0 <= i && i < n);\n        return data[i];\n    }\n    S operator[](int\
    \ i) {\n        return get(i);\n    }\n    S prod(int l, int r) {\n        assert(0<=l\
    \ && l<=r && r<=n);\n        S re = e();\n        for (int i=0; i<bsize; i++)\
    \ {\n            if (r<=i*bsize || (i+1)*bsize<=l) continue;\n            if (l<=i*bsize\
    \ && (i+1)*bsize<=r) re = op(re, block[i]);\n            else {\n            \
    \    for (int j=0; j<bsize; j++) {\n                    int k = i * bsize + j;\n\
    \                    if (l<=k && k<r) {\n                        re = op(re, data[k]);\n\
    \                    }\n                }\n            }\n        }\n        return\
    \ re;\n    }\n};\n"
  dependsOn:
  - math/isqrt.hpp
  isVerificationFile: false
  path: structure/sqrttree.hpp
  requiredBy: []
  timestamp: '2025-10-18 23:02:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/sqrttree.hpp
layout: document
redirect_from:
- /library/structure/sqrttree.hpp
- /library/structure/sqrttree.hpp.html
title: structure/sqrttree.hpp
---
