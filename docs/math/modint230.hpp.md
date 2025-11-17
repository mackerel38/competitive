---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint230.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nlong long modint_MOD = (1LL<<61)-1;\n// mod \u306E\u5024\u3092\u5909\u66F4\
    \u3059\u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u306F2^61-1)\nvoid setmod(long long\
    \ x) { modint_MOD = x; }\nstruct mint230 {\n    long long val;\n    mint230(long\
    \ long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n    }\n    mint230&\
    \ operator+=(const mint230& a) { val = (val + a.val) % modint_MOD; return *this;\
    \ }\n    mint230& operator-=(const mint230& a) { val = (val - a.val + modint_MOD)\
    \ % modint_MOD; return *this; }\n    mint230& operator*=(const mint230& a) { val\
    \ = (__int128_t)val * a.val % modint_MOD ; return *this; }\n    mint230& operator/=(const\
    \ mint230& a) { return *this *= a.inv(); }\n    mint230 operator+(const mint230&\
    \ a) const { return mint230(*this) += a; }\n    mint230 operator-(const mint230&\
    \ a) const { return mint230(*this) -= a; }\n    mint230 operator*(const mint230&\
    \ a) const { return mint230(*this) *= a; }\n    mint230 operator/(const mint230&\
    \ a) const { return mint230(*this) /= a; }\n    bool operator==(const mint230&\
    \ a) const { return val == a.val; }\n    bool operator!=(const mint230& a) const\
    \ { return val != a.val; }\n    mint230& operator+=(int a) { return *this += mint230(a);\
    \ }\n    mint230& operator-=(int a) { return *this -= mint230(a); }\n    mint230&\
    \ operator*=(int a) { return *this *= mint230(a); }\n    mint230& operator/=(int\
    \ a) { return *this /= mint230(a); }\n    mint230 operator+(int a) const { return\
    \ mint230(*this) += a; }\n    mint230 operator-(int a) const { return mint230(*this)\
    \ -= a; }\n    mint230 operator*(int a) const { return mint230(*this) *= a; }\n\
    \    mint230 operator/(int a) const { return mint230(*this) /= a; }\n    bool\
    \ operator==(int a) const { return val == mint230(a).val; }\n    bool operator!=(int\
    \ a) const { return val != mint230(a).val; }\n    friend mint230 operator+(int\
    \ a,const mint230& b) { return mint230(a) + b; }\n    friend mint230 operator-(int\
    \ a,const mint230& b) { return mint230(a) - b; }\n    friend mint230 operator*(int\
    \ a,const mint230& b) { return mint230(a) * b; }\n    friend mint230 operator/(int\
    \ a,const mint230& b) { return mint230(a) / b; }\n    friend bool operator==(int\
    \ a, const mint230& b) { return mint230(a) == b; }\n    friend bool operator!=(int\
    \ a, const mint230& b) { return mint230(a) != b; }\n    mint230& operator++()\
    \ { return *this += 1; }\n    mint230 operator++(int) { mint230 r = *this; *this\
    \ += 1; return r; }\n    mint230& operator--() { return *this -= 1; }\n    mint230\
    \ operator--(int) { mint230 r = *this; *this -= 1; return r; }\n    // modpow\
    \ \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\u7B97\u91CFO(log mod)\n    mint230\
    \ pow(long long n) const {\n        if (n != 0) n = ((n-2) % (modint_MOD-1) +\
    \ modint_MOD) % (modint_MOD-1) + 1;\n        mint230 r = 1, a = *this;\n     \
    \   while (n) {\n            if (n & 1) r *= a;\n            a *= a;\n       \
    \     n >>= 1;\n        }\n        return r;\n    }\n    mint230 inv() const {\
    \ return pow(-1); }\n    friend ostream& operator<<(ostream&s, const mint230&\
    \ a) { return s << a.val; }\n    friend istream& operator>>(istream&s, mint230&\
    \ a) { long long x; s >> x; a = mint230(x); return s; }\n};\nvector<mint230>fac,\
    \ ifac;\n// n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u3002O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n\
    \ + 1);\n    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n\
    \    ifac[n] = mint230(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i]\
    \ * i;\n}\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint230 comb(int n,int k) { return (0 <= k\
    \ && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\
    \u308B\u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\n\
    mint230 perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] :\
    \ 0; }\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nlong long modint_MOD\
    \ = (1LL<<61)-1;\n// mod \u306E\u5024\u3092\u5909\u66F4\u3059\u308B(\u30C7\u30D5\
    \u30A9\u30EB\u30C8\u306F2^61-1)\nvoid setmod(long long x) { modint_MOD = x; }\n\
    struct mint230 {\n    long long val;\n    mint230(long long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n\
    \    }\n    mint230& operator+=(const mint230& a) { val = (val + a.val) % modint_MOD;\
    \ return *this; }\n    mint230& operator-=(const mint230& a) { val = (val - a.val\
    \ + modint_MOD) % modint_MOD; return *this; }\n    mint230& operator*=(const mint230&\
    \ a) { val = (__int128_t)val * a.val % modint_MOD ; return *this; }\n    mint230&\
    \ operator/=(const mint230& a) { return *this *= a.inv(); }\n    mint230 operator+(const\
    \ mint230& a) const { return mint230(*this) += a; }\n    mint230 operator-(const\
    \ mint230& a) const { return mint230(*this) -= a; }\n    mint230 operator*(const\
    \ mint230& a) const { return mint230(*this) *= a; }\n    mint230 operator/(const\
    \ mint230& a) const { return mint230(*this) /= a; }\n    bool operator==(const\
    \ mint230& a) const { return val == a.val; }\n    bool operator!=(const mint230&\
    \ a) const { return val != a.val; }\n    mint230& operator+=(int a) { return *this\
    \ += mint230(a); }\n    mint230& operator-=(int a) { return *this -= mint230(a);\
    \ }\n    mint230& operator*=(int a) { return *this *= mint230(a); }\n    mint230&\
    \ operator/=(int a) { return *this /= mint230(a); }\n    mint230 operator+(int\
    \ a) const { return mint230(*this) += a; }\n    mint230 operator-(int a) const\
    \ { return mint230(*this) -= a; }\n    mint230 operator*(int a) const { return\
    \ mint230(*this) *= a; }\n    mint230 operator/(int a) const { return mint230(*this)\
    \ /= a; }\n    bool operator==(int a) const { return val == mint230(a).val; }\n\
    \    bool operator!=(int a) const { return val != mint230(a).val; }\n    friend\
    \ mint230 operator+(int a,const mint230& b) { return mint230(a) + b; }\n    friend\
    \ mint230 operator-(int a,const mint230& b) { return mint230(a) - b; }\n    friend\
    \ mint230 operator*(int a,const mint230& b) { return mint230(a) * b; }\n    friend\
    \ mint230 operator/(int a,const mint230& b) { return mint230(a) / b; }\n    friend\
    \ bool operator==(int a, const mint230& b) { return mint230(a) == b; }\n    friend\
    \ bool operator!=(int a, const mint230& b) { return mint230(a) != b; }\n    mint230&\
    \ operator++() { return *this += 1; }\n    mint230 operator++(int) { mint230 r\
    \ = *this; *this += 1; return r; }\n    mint230& operator--() { return *this -=\
    \ 1; }\n    mint230 operator--(int) { mint230 r = *this; *this -= 1; return r;\
    \ }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\u7B97\u91CFO(log\
    \ mod)\n    mint230 pow(long long n) const {\n        if (n != 0) n = ((n-2) %\
    \ (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;\n        mint230 r = 1, a\
    \ = *this;\n        while (n) {\n            if (n & 1) r *= a;\n            a\
    \ *= a;\n            n >>= 1;\n        }\n        return r;\n    }\n    mint230\
    \ inv() const { return pow(-1); }\n    friend ostream& operator<<(ostream&s, const\
    \ mint230& a) { return s << a.val; }\n    friend istream& operator>>(istream&s,\
    \ mint230& a) { long long x; s >> x; a = mint230(x); return s; }\n};\nvector<mint230>fac,\
    \ ifac;\n// n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u3002O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n\
    \ + 1);\n    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n\
    \    ifac[n] = mint230(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i]\
    \ * i;\n}\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint230 comb(int n,int k) { return (0 <= k\
    \ && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\
    \u308B\u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\n\
    mint230 perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] :\
    \ 0; }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint230.hpp
  requiredBy:
  - string/rollinghash.hpp
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint230.hpp
layout: document
redirect_from:
- /library/math/modint230.hpp
- /library/math/modint230.hpp.html
title: math/modint230.hpp
---
