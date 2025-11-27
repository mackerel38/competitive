---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-staticrmq-1.test.cpp
    title: verify/yosupo-staticrmq-1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/sparsetable.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// op \u306F\u7D50\u5408\u5F8B\u304B\u3064\u51AA\u7B49\
    \u6027\uFF08op(x,x)=x\uFF09\u3092\u6E80\u305F\u3059\u3053\u3068\ntemplate<class\
    \ T, auto op>\nstruct sparsetable {\n    int n, k;\n    vector<vector<T>> data;\n\
    \    sparsetable() = default;\n    // sparsetable \u3092\u69CB\u7BC9 O(n log n)\n\
    \    sparsetable(const vector<T>& v) : n((int)v.size()) {\n        if (n == 0)\
    \ { k = 0; return; }\n        k = __lg(n);\n        data.assign(n, vector<T>(k\
    \ + 1));\n        for (int i=0; i<n; i++) data[i][0] = v[i];\n        for (int\
    \ j=1; j<=k; j++) {\n            int len = 1<<j;\n            for (int i=0; i+len<=n;\
    \ i++) {\n                data[i][j] = op(data[i][j-1], data[i+(1<<(j-1))][j-1]);\n\
    \            }\n        }\n    }\n    //op([l, r)) \u3092\u6C42\u3081\u308B O(1)\n\
    \    T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return T{};\n        int j = __lg(r - l);\n        return\
    \ op(data[l][j], data[r - (1 << j)][j]);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// op \u306F\
    \u7D50\u5408\u5F8B\u304B\u3064\u51AA\u7B49\u6027\uFF08op(x,x)=x\uFF09\u3092\u6E80\
    \u305F\u3059\u3053\u3068\ntemplate<class T, auto op>\nstruct sparsetable {\n \
    \   int n, k;\n    vector<vector<T>> data;\n    sparsetable() = default;\n   \
    \ // sparsetable \u3092\u69CB\u7BC9 O(n log n)\n    sparsetable(const vector<T>&\
    \ v) : n((int)v.size()) {\n        if (n == 0) { k = 0; return; }\n        k =\
    \ __lg(n);\n        data.assign(n, vector<T>(k + 1));\n        for (int i=0; i<n;\
    \ i++) data[i][0] = v[i];\n        for (int j=1; j<=k; j++) {\n            int\
    \ len = 1<<j;\n            for (int i=0; i+len<=n; i++) {\n                data[i][j]\
    \ = op(data[i][j-1], data[i+(1<<(j-1))][j-1]);\n            }\n        }\n   \
    \ }\n    //op([l, r)) \u3092\u6C42\u3081\u308B O(1)\n    T prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ T{};\n        int j = __lg(r - l);\n        return op(data[l][j], data[r - (1\
    \ << j)][j]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sparsetable.hpp
  requiredBy: []
  timestamp: '2025-11-27 14:31:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-staticrmq-1.test.cpp
documentation_of: structure/sparsetable.hpp
layout: document
redirect_from:
- /library/structure/sparsetable.hpp
- /library/structure/sparsetable.hpp.html
title: structure/sparsetable.hpp
---
