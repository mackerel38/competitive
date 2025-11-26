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
  bundledCode: "#line 2 \"structure/sparsetable.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// op(op(a, b), b) = op(a, b) \u304C\u6210\u308A\u7ACB\u3064\
    \u5FC5\u8981\u304C\u3042\u308B(\u51AA\u7B49\u6027)\ntemplate<class T, auto op>\n\
    struct sparsetable {\n    int n;\n    vector<vector<T>> data;\n    sparsetable()\
    \ = default;\n    // sparsetable \u3092\u69CB\u7BC9 O(n log n)\n    sparsetable(const\
    \ vector<T>& v) : n(v.size()) {\n        int m = 1;\n        while (m < n) m <<=\
    \ 1;\n        data.assign(m, vector<T>(__lg(m)+1));\n        for (int i=0; i<n;\
    \ i++) data[i][0] = v[i];\n        for (int j=1; j<=__lg(m); j++) {\n        \
    \    for (int i=0; i+(1<<j)<=n; i++) {\n                data[i][j] = op(data[i][j-1],\
    \ data[i+(1<<(j-1))][j-1]);\n            }\n        }\n    }\n    // op([l, r))\
    \ \u306E\u5024\u3092\u53D6\u5F97 O(1)\n    T prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) return T{};\n        int j =\
    \ __lg(r-l);\n        return op(data[l][j], data[r-(1 << j)][j]);\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// op(op(a,\
    \ b), b) = op(a, b) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\u308B\
    (\u51AA\u7B49\u6027)\ntemplate<class T, auto op>\nstruct sparsetable {\n    int\
    \ n;\n    vector<vector<T>> data;\n    sparsetable() = default;\n    // sparsetable\
    \ \u3092\u69CB\u7BC9 O(n log n)\n    sparsetable(const vector<T>& v) : n(v.size())\
    \ {\n        int m = 1;\n        while (m < n) m <<= 1;\n        data.assign(m,\
    \ vector<T>(__lg(m)+1));\n        for (int i=0; i<n; i++) data[i][0] = v[i];\n\
    \        for (int j=1; j<=__lg(m); j++) {\n            for (int i=0; i+(1<<j)<=n;\
    \ i++) {\n                data[i][j] = op(data[i][j-1], data[i+(1<<(j-1))][j-1]);\n\
    \            }\n        }\n    }\n    // op([l, r)) \u306E\u5024\u3092\u53D6\u5F97\
    \ O(1)\n    T prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return T{};\n        int j = __lg(r-l);\n        return op(data[l][j],\
    \ data[r-(1 << j)][j]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/sparsetable.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/sparsetable.hpp
layout: document
redirect_from:
- /library/structure/sparsetable.hpp
- /library/structure/sparsetable.hpp.html
title: structure/sparsetable.hpp
---
