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
  bundledCode: "#line 2 \"string/rollinghash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <typename T = char>\nstruct rollinghash {\n    static\
    \ long long generate_base() noexcept {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand(1, 2305843009213693950);\n  \
    \      return rand(mt);\n    }\n    static long long base, invbase;\n    static\
    \ vector<long long> bases, invbases;\n    vector<T> pre, suf;\n    vector<long\
    \ long> prenum(1), sufnum(1);\n    static void buildbases(int n) noexcept {\n\
    \        if ((int)bases.size() < n+1) {\n            int presize = (int)bases.size()\n\
    \            bases.resize(n+1);\n            for (int i=presize-1; i<n; i++) {\n\
    \                bases[i+1] = bases[i] * base[i] % 2305843009213693951;\n    \
    \        }\n        }\n    }\n    static void buildinvbases(int n) noexcept {\n\
    \        if ((int)invbases.size() < n+1) {\n            int presize = (int)invbases.size();\n\
    \            invbases.resize(n+1);\n            for (int i=presize-1; i<n; i++)\
    \ {\n                invbases[i+1] = invbases[i] * invbase % 2305843009213693951;\n\
    \            }\n        }\n    }\n    rollinghash() = default;\n    explicit rollinghash(const\
    \ string& s) noexcept {\n        ;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T = char>\nstruct rollinghash {\n    static long long generate_base()\
    \ noexcept {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand(1, 2305843009213693950);\n  \
    \      return rand(mt);\n    }\n    static long long base, invbase;\n    static\
    \ vector<long long> bases, invbases;\n    vector<T> pre, suf;\n    vector<long\
    \ long> prenum(1), sufnum(1);\n    static void buildbases(int n) noexcept {\n\
    \        if ((int)bases.size() < n+1) {\n            int presize = (int)bases.size()\n\
    \            bases.resize(n+1);\n            for (int i=presize-1; i<n; i++) {\n\
    \                bases[i+1] = bases[i] * base[i] % 2305843009213693951;\n    \
    \        }\n        }\n    }\n    static void buildinvbases(int n) noexcept {\n\
    \        if ((int)invbases.size() < n+1) {\n            int presize = (int)invbases.size();\n\
    \            invbases.resize(n+1);\n            for (int i=presize-1; i<n; i++)\
    \ {\n                invbases[i+1] = invbases[i] * invbase % 2305843009213693951;\n\
    \            }\n        }\n    }\n    rollinghash() = default;\n    explicit rollinghash(const\
    \ string& s) noexcept {\n        ;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2025-08-21 20:51:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
