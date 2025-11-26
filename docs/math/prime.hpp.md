---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-enumerate_primes.test.cpp
    title: verify/yosupo-enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n// \u7D20\u6570\u5224\u5B9A O(log n)\nbool isprime(long long n) {\n  \
    \  if (n <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0)\
    \ return false;\n    int flag = 1;\n    if (n < 4759123141LL) flag = 0;\n    vector<vector<long\
    \ long>> tests = {{2, 7, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};\n\
    \    long long s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n   \
    \     d >>= 1;\n    }\n    for (auto a : tests[flag]) {\n        if (n <= a) return\
    \ true;\n        __int128_t x = 1, a2=a%n, d2 = d;\n        while (d2) {\n   \
    \         if (d2 & 1) x = x * a2 % n;\n            a2 = a2 * a2 % n;\n       \
    \     d2 >>= 1;\n        }\n        if (x != 1) {\n            long long t;\n\
    \            for (t = 0; t < s; ++t) {\n                if (x == n - 1) break;\n\
    \                x = x * x % n;\n            }\n            if (t == s) return\
    \ false;\n        }\n    }\n    return true;\n}\n// n \u4EE5\u4E0B\u306E\u7D20\
    \u6570\u3092\u5217\u6319\u3059\u308B O(n log log n)\nvector<int> enumprimes(long\
    \ long n) {\n    vector<char> primeflag(n+1);\n    vector<int> re;\n    for (long\
    \ long i=2; i<=n; i++) {\n        if (primeflag[i]) continue;\n        re.push_back(i);\n\
    \        for (long long j=i*i; j<=n; j+=i) {\n            primeflag[j] = true;\n\
    \        }\n    }\n    return re;\n}\nvoid inner_factorize(long long n, vector<long\
    \ long>& factors) {\n    if (n <= 1) return;\n    if (isprime(n)) {\n        factors.push_back(n);\n\
    \        return;\n    }\n    if (n % 2 == 0) {\n        while (n % 2 == 0) {\n\
    \            factors.push_back(2);\n            n /= 2;\n        }\n        inner_factorize(n,\
    \ factors);\n        return;\n    }\n    while (true) {\n        __int128_t x\
    \ = rand() % (n - 2) + 2;\n        __int128_t y = x;\n        __int128_t c = rand()\
    \ % (n - 1) + 1;\n        __int128_t m = 1;\n        while (m == 1) {\n      \
    \      x = (x * x + c) % n;\n            y = (y * y + c) % n;\n            y =\
    \ (y * y + c) % n;\n            m = gcd((long long)(x - y + n), n);\n        \
    \    if (m == n) break;\n        }\n        if (m != n) {\n            inner_factorize(m,\
    \ factors);\n            inner_factorize(n / m, factors);\n            return;\n\
    \        }\n    }\n}\n// \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B O(n^0.25)\n\
    vector<long long> factorize(long long n) {\n    vector<long long> re;\n    inner_factorize(n,\
    \ re);\n    return re;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n// \u7D20\u6570\
    \u5224\u5B9A O(log n)\nbool isprime(long long n) {\n    if (n <= 1) return false;\n\
    \    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n    int flag\
    \ = 1;\n    if (n < 4759123141LL) flag = 0;\n    vector<vector<long long>> tests\
    \ = {{2, 7, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};\n    long\
    \ long s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n        d >>=\
    \ 1;\n    }\n    for (auto a : tests[flag]) {\n        if (n <= a) return true;\n\
    \        __int128_t x = 1, a2=a%n, d2 = d;\n        while (d2) {\n           \
    \ if (d2 & 1) x = x * a2 % n;\n            a2 = a2 * a2 % n;\n            d2 >>=\
    \ 1;\n        }\n        if (x != 1) {\n            long long t;\n           \
    \ for (t = 0; t < s; ++t) {\n                if (x == n - 1) break;\n        \
    \        x = x * x % n;\n            }\n            if (t == s) return false;\n\
    \        }\n    }\n    return true;\n}\n// n \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\
    \u5217\u6319\u3059\u308B O(n log log n)\nvector<int> enumprimes(long long n) {\n\
    \    vector<char> primeflag(n+1);\n    vector<int> re;\n    for (long long i=2;\
    \ i<=n; i++) {\n        if (primeflag[i]) continue;\n        re.push_back(i);\n\
    \        for (long long j=i*i; j<=n; j+=i) {\n            primeflag[j] = true;\n\
    \        }\n    }\n    return re;\n}\nvoid inner_factorize(long long n, vector<long\
    \ long>& factors) {\n    if (n <= 1) return;\n    if (isprime(n)) {\n        factors.push_back(n);\n\
    \        return;\n    }\n    if (n % 2 == 0) {\n        while (n % 2 == 0) {\n\
    \            factors.push_back(2);\n            n /= 2;\n        }\n        inner_factorize(n,\
    \ factors);\n        return;\n    }\n    while (true) {\n        __int128_t x\
    \ = rand() % (n - 2) + 2;\n        __int128_t y = x;\n        __int128_t c = rand()\
    \ % (n - 1) + 1;\n        __int128_t m = 1;\n        while (m == 1) {\n      \
    \      x = (x * x + c) % n;\n            y = (y * y + c) % n;\n            y =\
    \ (y * y + c) % n;\n            m = gcd((long long)(x - y + n), n);\n        \
    \    if (m == n) break;\n        }\n        if (m != n) {\n            inner_factorize(m,\
    \ factors);\n            inner_factorize(n / m, factors);\n            return;\n\
    \        }\n    }\n}\n// \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B O(n^0.25)\n\
    vector<long long> factorize(long long n) {\n    vector<long long> re;\n    inner_factorize(n,\
    \ re);\n    return re;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2025-11-27 00:16:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-enumerate_primes.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
