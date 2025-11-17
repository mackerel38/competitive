---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/FWT.hpp
    title: math/FWT.hpp
  _extendedRequiredBy: []
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
    \ {\n            a[i] /= (int)a.size();\n        }\n    }\n}\n#line 4 \"math/xorconvolution.hpp\"\
    \nusing namespace std;\ntemplate <class T>\nvector<T> xorconvolution(vector<T>&\
    \ a, vector<T>& b) {\n    int n=1;\n    while (n < max((int)a.size(), (int)b.size()))\
    \ n<<=1;\n    vector<T> A(n), B(n);\n    for (int i=0; i<(int)a.size(); i++) {\n\
    \        A[i] = a[i];\n    }\n    for (int i=0; i<(int)b.size(); i++) {\n    \
    \    B[i] = b[i];\n    }\n    FWT(A, false);\n    FWT(B, false);\n    for (int\
    \ i=0; i<n; i++) {\n        A[i] *= B[i];\n    }\n    FWT(A, true);\n    vector<T>\
    \ re(max((int)a.size(), (int)b.size()));\n    for (int i=0; i<max((int)a.size(),\
    \ (int)b.size()); i++) {\n        re[i] = A[i];\n    }\n    return re;\n}\n"
  code: "#pragma once\n#include \"FWT\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T>\nvector<T> xorconvolution(vector<T>& a, vector<T>&\
    \ b) {\n    int n=1;\n    while (n < max((int)a.size(), (int)b.size())) n<<=1;\n\
    \    vector<T> A(n), B(n);\n    for (int i=0; i<(int)a.size(); i++) {\n      \
    \  A[i] = a[i];\n    }\n    for (int i=0; i<(int)b.size(); i++) {\n        B[i]\
    \ = b[i];\n    }\n    FWT(A, false);\n    FWT(B, false);\n    for (int i=0; i<n;\
    \ i++) {\n        A[i] *= B[i];\n    }\n    FWT(A, true);\n    vector<T> re(max((int)a.size(),\
    \ (int)b.size()));\n    for (int i=0; i<max((int)a.size(), (int)b.size()); i++)\
    \ {\n        re[i] = A[i];\n    }\n    return re;\n}"
  dependsOn:
  - math/FWT.hpp
  isVerificationFile: false
  path: math/xorconvolution.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-bitwise_xor_convolution.test.cpp
documentation_of: math/xorconvolution.hpp
layout: document
redirect_from:
- /library/math/xorconvolution.hpp
- /library/math/xorconvolution.hpp.html
title: math/xorconvolution.hpp
---
