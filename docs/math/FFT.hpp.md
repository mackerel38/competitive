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
  bundledCode: "#line 2 \"math/FFT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nvector<complex<double>> FFT(vector<complex<double>> a, bool invert = false)\
    \ {\n    int n = a.size();\n    if (n == 1) return a;\n    vector<complex<double>>\
    \ even(n/2), odd(n/2);\n    for (int i=0; i<n/2; i++) {\n        even[i] = a[i*2];\n\
    \        odd[i] = a[i*2+1];\n    }\n    even = FFT(even, invert);\n    odd = FFT(odd,\
    \ invert);\n    double angle = 2 * M_PI / n * (invert ? -1 : 1);\n    complex<double>\
    \ w(1), wn = polar(1.0, angle);\n    for (int i=0; i<n/2; i++) {\n        complex<double>\
    \ t = w * odd[i];\n        a[i] = even[i] + t;\n        a[i+n/2] = even[i] - t;\n\
    \        w *= wn;\n    }\n    return a;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nvector<complex<double>>\
    \ FFT(vector<complex<double>> a, bool invert = false) {\n    int n = a.size();\n\
    \    if (n == 1) return a;\n    vector<complex<double>> even(n/2), odd(n/2);\n\
    \    for (int i=0; i<n/2; i++) {\n        even[i] = a[i*2];\n        odd[i] =\
    \ a[i*2+1];\n    }\n    even = FFT(even, invert);\n    odd = FFT(odd, invert);\n\
    \    double angle = 2 * M_PI / n * (invert ? -1 : 1);\n    complex<double> w(1),\
    \ wn = polar(1.0, angle);\n    for (int i=0; i<n/2; i++) {\n        complex<double>\
    \ t = w * odd[i];\n        a[i] = even[i] + t;\n        a[i+n/2] = even[i] - t;\n\
    \        w *= wn;\n    }\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.hpp
layout: document
redirect_from:
- /library/math/FFT.hpp
- /library/math/FFT.hpp.html
title: math/FFT.hpp
---
