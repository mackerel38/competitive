---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/sqrttree.hpp
    title: structure/sqrttree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/isqrt.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// floor(sqrt(n)) \u3092\u8FD4\u3059\nlong long isqrt(long long n) {\n\
    \    assert(0 <= n);\n    long long re = sqrt(n);\n    while ((re + 1) * (re +\
    \ 1) <= n) re++;\n    while (n < re * re) re--;\n    return re;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// floor(sqrt(n))\
    \ \u3092\u8FD4\u3059\nlong long isqrt(long long n) {\n    assert(0 <= n);\n  \
    \  long long re = sqrt(n);\n    while ((re + 1) * (re + 1) <= n) re++;\n    while\
    \ (n < re * re) re--;\n    return re;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/isqrt.hpp
  requiredBy:
  - structure/sqrttree.hpp
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/isqrt.hpp
layout: document
redirect_from:
- /library/math/isqrt.hpp
- /library/math/isqrt.hpp.html
title: math/isqrt.hpp
---
