---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-suffixarray.test.cpp
    title: verify/yosupo-suffixarray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffixarray.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// suffix array \u3092O(n (log n)^2) \u3067\u69CB\u7BC9\u3059\
    \u308B\nvector<int> suffixarray(const string& s) {\n    string t = s + '\\0';\n\
    \    vector<int> sa(t.size()), isa(t.size()), tmp(t.size());\n    iota(sa.begin(),\
    \ sa.end(), 0);\n    for (int i=0; i<(int)t.size(); i++) isa[i] = t[i];\n    for\
    \ (int k=1; k<(int)t.size(); k<<=1) {\n        auto cmp = [&](int a, int b) ->\
    \ bool {\n            if (isa[a] != isa[b]) return isa[a] < isa[b];\n        \
    \    int ra = (a+k<(int)t.size() ? isa[a + k] : -1);\n            int rb = (b+k<(int)t.size()\
    \ ? isa[b + k] : -1);\n            return ra < rb;\n        };\n        sort(sa.begin(),\
    \ sa.end(), cmp);\n        tmp[sa[0]] = 0;\n        for (int i=1; i<(int)t.size();\
    \ i++) tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);\n        isa = tmp;\n\
    \        if (isa[sa[t.size()-1]] == t.size()-1) break;\n    }\n    return sa;\n\
    }\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// suffix\
    \ array \u3092O(n (log n)^2) \u3067\u69CB\u7BC9\u3059\u308B\nvector<int> suffixarray(const\
    \ string& s) {\n    string t = s + '\\0';\n    vector<int> sa(t.size()), isa(t.size()),\
    \ tmp(t.size());\n    iota(sa.begin(), sa.end(), 0);\n    for (int i=0; i<(int)t.size();\
    \ i++) isa[i] = t[i];\n    for (int k=1; k<(int)t.size(); k<<=1) {\n        auto\
    \ cmp = [&](int a, int b) -> bool {\n            if (isa[a] != isa[b]) return\
    \ isa[a] < isa[b];\n            int ra = (a+k<(int)t.size() ? isa[a + k] : -1);\n\
    \            int rb = (b+k<(int)t.size() ? isa[b + k] : -1);\n            return\
    \ ra < rb;\n        };\n        sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]]\
    \ = 0;\n        for (int i=1; i<(int)t.size(); i++) tmp[sa[i]] = tmp[sa[i-1]]\
    \ + cmp(sa[i-1], sa[i]);\n        isa = tmp;\n        if (isa[sa[t.size()-1]]\
    \ == t.size()-1) break;\n    }\n    return sa;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffixarray.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-suffixarray.test.cpp
documentation_of: string/suffixarray.hpp
layout: document
redirect_from:
- /library/string/suffixarray.hpp
- /library/string/suffixarray.hpp.html
title: string/suffixarray.hpp
---
