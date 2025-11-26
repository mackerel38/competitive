---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/FPS.hpp
    title: math/FPS.hpp
  - icon: ':warning:'
    path: math/FPSbase.hpp
    title: math/FPSbase.hpp
  - icon: ':warning:'
    path: math/NTT.hpp
    title: math/NTT.hpp
  - icon: ':warning:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <long long modint_MOD>\nstruct modint {\n    long long val;\n\
    \    constexpr modint(long long x=0) noexcept {\n        x %= modint_MOD;\n  \
    \      if (x < 0) x += modint_MOD;\n        val = x;\n    }\n    explicit constexpr\
    \ operator long long() const noexcept { return val; }\n    template<typename Int>\n\
    \    static constexpr long long adjust(Int x) noexcept {\n        static_assert(std::is_integral<Int>::value,\
    \ \"Int must be integral\");\n        __int128 t = static_cast<__int128>(x);\n\
    \        __int128 m = static_cast<__int128>(modint_MOD);\n        t %= m;\n  \
    \      if (t < 0) t += m;\n        return static_cast<long long>(t);\n    }\n\
    \    constexpr modint operator+(const modint& x) const noexcept { return modint(*this)\
    \ += x; }\n    constexpr modint operator-(const modint& x) const noexcept { return\
    \ modint(*this) -= x; }\n    constexpr modint operator*(const modint& x) const\
    \ noexcept { return modint(*this) *= x; }\n    constexpr modint operator/(const\
    \ modint& x) const noexcept { return modint(*this) /= x; }\n    constexpr modint&\
    \ operator+=(const modint& x) noexcept {\n        if (modint_MOD <= (val += x.val))\
    \ val -= modint_MOD;\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint& x) noexcept {\n        if ((val -= x.val) < 0) val += modint_MOD;\n\
    \        return *this;\n    }\n    constexpr modint& operator*=(const modint&\
    \ x) noexcept {\n        __int128 t = (__int128)val * x.val;\n        val = (long\
    \ long)(t % modint_MOD);\n        if (val < 0) val += modint_MOD;\n        return\
    \ *this;\n    }\n    constexpr modint& operator/=(modint x) noexcept {\n     \
    \   *this *= x.inv();\n        return *this;\n    }\n    constexpr modint operator-()\
    \ const noexcept { return modint() - *this; }\n    constexpr modint& operator++()\
    \ noexcept { return *this += 1; }\n    constexpr modint& operator--() noexcept\
    \ { return *this -= 1; }\n    constexpr modint operator++(int) noexcept { modint\
    \ tmp = *this; ++*this; return tmp; }\n    constexpr modint operator--(int) noexcept\
    \ { modint tmp = *this; --*this; return tmp; }\n    constexpr bool operator==(const\
    \ modint& x) const noexcept { return val == x.val; }\n    constexpr bool operator!=(const\
    \ modint& x) const noexcept { return val != x.val; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr modint&\
    \ operator+=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n      \
    \  if (modint_MOD <= (val += y)) val -= modint_MOD;\n        return *this;\n \
    \   }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator-=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        if ((val -= y) < 0) val += modint_MOD;\n        return *this;\n    }\n\
    \    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator*=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        __int128 t = (__int128)val * y;\n        val = (long long)(t % modint_MOD);\n\
    \        if (val < 0) val += modint_MOD;\n        return *this;\n    }\n    template<typename\
    \ Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr\
    \ modint& operator/=(Int x) noexcept {\n        modint t = modint(adjust<Int>(x));\n\
    \        *this /= t;\n        return *this;\n    }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator+(const modint& a, Int b) noexcept { modint t = a; t += b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator+(Int a, const modint& b) noexcept { modint\
    \ t = b; t += a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(const modint& a, Int b) noexcept { modint\
    \ t = a; t -= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t -= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator*(const modint& a, Int b) noexcept { modint t = a; t *= b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator*(Int a, const modint& b) noexcept { modint\
    \ t = b; t *= a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(const modint& a, Int b) noexcept { modint\
    \ t = a; t /= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t /= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ bool operator==(const modint& a, Int b) noexcept { return a.val == adjust<Int>(b);\
    \ }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator==(Int a, const modint& b) noexcept { return\
    \ adjust<Int>(a) == b.val; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(const modint& a, Int b) noexcept { return\
    \ !(a == b); }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(Int a, const modint& b) noexcept { return\
    \ !(a == b); }\n    friend constexpr istream& operator>> (istream& i, modint&\
    \ x) { long long y; i >> y; x = modint(y); return i; }\n    friend constexpr ostream&\
    \ operator<< (ostream& o, const modint& x) { o << x.val; return o; }\n    constexpr\
    \ modint pow(long long n) const noexcept {\n        if (n < 0) return inv().pow(-n);\n\
    \        modint x = *this, re = 1;\n        while (0 < n){\n            if (n\
    \ & 1) re *= x;\n            x *= x;\n            n >>= 1;\n        }\n      \
    \  return re;\n    }\n    constexpr modint inv() const noexcept { return pow(modint_MOD\
    \ - 2); }\n};\n\ntemplate <long long modint_MOD>\nstruct factor {\n    vector<modint<modint_MOD>>\
    \ fac, ifac;\n    factor(int n) : fac(n+1), ifac(n+1) {\n        fac[0] = 1;\n\
    \        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n        ifac[n] = fac[n].inv();\n\
    \        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;\n    }\n    modint<modint_MOD>\
    \ P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r];\
    \ }\n    modint<modint_MOD> C(int n, int r) const noexcept { return (r<0 || n<r)\
    \ ? 0 : P(n, r) * ifac[r]; }\n    modint<modint_MOD> H(int n, int r) const noexcept\
    \ { return (n==0 && r==0) ? 1 : C(n+r-1, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <long long modint_MOD>\nstruct modint {\n    long long val;\n    constexpr modint(long\
    \ long x=0) noexcept {\n        x %= modint_MOD;\n        if (x < 0) x += modint_MOD;\n\
    \        val = x;\n    }\n    explicit constexpr operator long long() const noexcept\
    \ { return val; }\n    template<typename Int>\n    static constexpr long long\
    \ adjust(Int x) noexcept {\n        static_assert(std::is_integral<Int>::value,\
    \ \"Int must be integral\");\n        __int128 t = static_cast<__int128>(x);\n\
    \        __int128 m = static_cast<__int128>(modint_MOD);\n        t %= m;\n  \
    \      if (t < 0) t += m;\n        return static_cast<long long>(t);\n    }\n\
    \    constexpr modint operator+(const modint& x) const noexcept { return modint(*this)\
    \ += x; }\n    constexpr modint operator-(const modint& x) const noexcept { return\
    \ modint(*this) -= x; }\n    constexpr modint operator*(const modint& x) const\
    \ noexcept { return modint(*this) *= x; }\n    constexpr modint operator/(const\
    \ modint& x) const noexcept { return modint(*this) /= x; }\n    constexpr modint&\
    \ operator+=(const modint& x) noexcept {\n        if (modint_MOD <= (val += x.val))\
    \ val -= modint_MOD;\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint& x) noexcept {\n        if ((val -= x.val) < 0) val += modint_MOD;\n\
    \        return *this;\n    }\n    constexpr modint& operator*=(const modint&\
    \ x) noexcept {\n        __int128 t = (__int128)val * x.val;\n        val = (long\
    \ long)(t % modint_MOD);\n        if (val < 0) val += modint_MOD;\n        return\
    \ *this;\n    }\n    constexpr modint& operator/=(modint x) noexcept {\n     \
    \   *this *= x.inv();\n        return *this;\n    }\n    constexpr modint operator-()\
    \ const noexcept { return modint() - *this; }\n    constexpr modint& operator++()\
    \ noexcept { return *this += 1; }\n    constexpr modint& operator--() noexcept\
    \ { return *this -= 1; }\n    constexpr modint operator++(int) noexcept { modint\
    \ tmp = *this; ++*this; return tmp; }\n    constexpr modint operator--(int) noexcept\
    \ { modint tmp = *this; --*this; return tmp; }\n    constexpr bool operator==(const\
    \ modint& x) const noexcept { return val == x.val; }\n    constexpr bool operator!=(const\
    \ modint& x) const noexcept { return val != x.val; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr modint&\
    \ operator+=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n      \
    \  if (modint_MOD <= (val += y)) val -= modint_MOD;\n        return *this;\n \
    \   }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator-=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        if ((val -= y) < 0) val += modint_MOD;\n        return *this;\n    }\n\
    \    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator*=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        __int128 t = (__int128)val * y;\n        val = (long long)(t % modint_MOD);\n\
    \        if (val < 0) val += modint_MOD;\n        return *this;\n    }\n    template<typename\
    \ Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr\
    \ modint& operator/=(Int x) noexcept {\n        modint t = modint(adjust<Int>(x));\n\
    \        *this /= t;\n        return *this;\n    }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator+(const modint& a, Int b) noexcept { modint t = a; t += b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator+(Int a, const modint& b) noexcept { modint\
    \ t = b; t += a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(const modint& a, Int b) noexcept { modint\
    \ t = a; t -= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t -= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator*(const modint& a, Int b) noexcept { modint t = a; t *= b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator*(Int a, const modint& b) noexcept { modint\
    \ t = b; t *= a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(const modint& a, Int b) noexcept { modint\
    \ t = a; t /= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t /= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ bool operator==(const modint& a, Int b) noexcept { return a.val == adjust<Int>(b);\
    \ }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator==(Int a, const modint& b) noexcept { return\
    \ adjust<Int>(a) == b.val; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(const modint& a, Int b) noexcept { return\
    \ !(a == b); }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(Int a, const modint& b) noexcept { return\
    \ !(a == b); }\n    friend constexpr istream& operator>> (istream& i, modint&\
    \ x) { long long y; i >> y; x = modint(y); return i; }\n    friend constexpr ostream&\
    \ operator<< (ostream& o, const modint& x) { o << x.val; return o; }\n    constexpr\
    \ modint pow(long long n) const noexcept {\n        if (n < 0) return inv().pow(-n);\n\
    \        modint x = *this, re = 1;\n        while (0 < n){\n            if (n\
    \ & 1) re *= x;\n            x *= x;\n            n >>= 1;\n        }\n      \
    \  return re;\n    }\n    constexpr modint inv() const noexcept { return pow(modint_MOD\
    \ - 2); }\n};\n\ntemplate <long long modint_MOD>\nstruct factor {\n    vector<modint<modint_MOD>>\
    \ fac, ifac;\n    factor(int n) : fac(n+1), ifac(n+1) {\n        fac[0] = 1;\n\
    \        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n        ifac[n] = fac[n].inv();\n\
    \        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;\n    }\n    modint<modint_MOD>\
    \ P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r];\
    \ }\n    modint<modint_MOD> C(int n, int r) const noexcept { return (r<0 || n<r)\
    \ ? 0 : P(n, r) * ifac[r]; }\n    modint<modint_MOD> H(int n, int r) const noexcept\
    \ { return (n==0 && r==0) ? 1 : C(n+r-1, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/convolution.hpp
  - math/NTT.hpp
  - math/FPSbase.hpp
  - math/FPS.hpp
  timestamp: '2025-10-08 04:52:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
