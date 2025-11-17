---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/xorconvolution.hpp
    title: math/xorconvolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-bitwise_xor_convolution.test.cpp
    title: verify/yosupo-bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/FWT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T>\nvoid FWT(vector<T>& a, bool invert = false) {\n  \
    \  for (int i=1; i<(int)a.size(); i<<=1) {\n        for (int j=0; j<(int)a.size();\
    \ j++) {\n            if ((i & j) == 0) {\n                T x = a[j], y = a[i+j];\n\
    \                a[j] = x + y;\n                a[i+j] = x - y;\n            }\n\
    \        }\n    }\n    if (invert) {\n        for (int i=0; i<(int)a.size(); i++)\
    \ {\n            a[i] /= (int)a.size();\n        }\n    }\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ T>\nvoid FWT(vector<T>& a, bool invert = false) {\n    for (int i=1; i<(int)a.size();\
    \ i<<=1) {\n        for (int j=0; j<(int)a.size(); j++) {\n            if ((i\
    \ & j) == 0) {\n                T x = a[j], y = a[i+j];\n                a[j]\
    \ = x + y;\n                a[i+j] = x - y;\n            }\n        }\n    }\n\
    \    if (invert) {\n        for (int i=0; i<(int)a.size(); i++) {\n          \
    \  a[i] /= (int)a.size();\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FWT.hpp
  requiredBy:
  - math/xorconvolution.hpp
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-bitwise_xor_convolution.test.cpp
documentation_of: math/FWT.hpp
layout: document
redirect_from:
- /library/math/FWT.hpp
- /library/math/FWT.hpp.html
title: math/FWT.hpp
---
