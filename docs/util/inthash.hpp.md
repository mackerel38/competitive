---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/drken1215/algorithm/blob/master/DataStructure/zobrist_hash.cpp
  bundledCode: "#line 2 \"util/inthash.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nunsigned long long inthashrand = 0;\n\nunsigned long long inthash(unsigned\
    \ long long x) {\n    if (inthashrand == 0) inthashrand = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += inthashrand;\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30))\
    \ * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return\
    \ x ^ (x >> 31);\n}\n\n// https://github.com/drken1215/algorithm/blob/master/DataStructure/zobrist_hash.cpp\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nunsigned\
    \ long long inthashrand = 0;\n\nunsigned long long inthash(unsigned long long\
    \ x) {\n    if (inthashrand == 0) inthashrand = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += inthashrand;\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30))\
    \ * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return\
    \ x ^ (x >> 31);\n}\n\n// https://github.com/drken1215/algorithm/blob/master/DataStructure/zobrist_hash.cpp\n"
  dependsOn: []
  isVerificationFile: false
  path: util/inthash.hpp
  requiredBy: []
  timestamp: '2025-08-10 12:06:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/inthash.hpp
layout: document
redirect_from:
- /library/util/inthash.hpp
- /library/util/inthash.hpp.html
title: util/inthash.hpp
---
