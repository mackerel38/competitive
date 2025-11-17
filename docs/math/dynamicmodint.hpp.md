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
  bundledCode: "#line 2 \"math/dynamicmodint.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct dynamicmodint {\n    static long long dynamicmodint_MOD;\n\
    \    long long val;\n    static void setmod(long long m) {\n        dynamicmodint_MOD\
    \ = m;\n    }\n    static long long mod() noexcept { return dynamicmodint_MOD;\
    \ }\n    dynamicmodint(long long x = 0) noexcept {\n        if (dynamicmodint_MOD\
    \ == 0) dynamicmodint_MOD = 998244353;\n        val = adjust<long long>(x);\n\
    \    }\n    explicit operator long long() const noexcept { return val; }\n   \
    \ template<typename Int>\n    static long long adjust(Int x) noexcept {\n    \
    \    static_assert(std::is_integral<Int>::value, \"Int must be integral\");\n\
    \        if (dynamicmodint_MOD == 0) dynamicmodint_MOD = 998244353;\n        __int128\
    \ t = static_cast<__int128>(x);\n        __int128 m = static_cast<__int128>(dynamicmodint_MOD);\n\
    \        t %= m;\n        if (t < 0) t += m;\n        return static_cast<long\
    \ long>(t);\n    }\n    dynamicmodint operator+(const dynamicmodint& o) const\
    \ noexcept { return dynamicmodint(*this) += o; }\n    dynamicmodint operator-(const\
    \ dynamicmodint& o) const noexcept { return dynamicmodint(*this) -= o; }\n   \
    \ dynamicmodint operator*(const dynamicmodint& o) const noexcept { return dynamicmodint(*this)\
    \ *= o; }\n    dynamicmodint operator/(const dynamicmodint& o) const noexcept\
    \ { return dynamicmodint(*this) /= o; }\n    dynamicmodint& operator+=(const dynamicmodint&\
    \ o) noexcept {\n        val += o.val;\n        if (val >= dynamicmodint_MOD)\
    \ val -= dynamicmodint_MOD;\n        return *this;\n    }\n    dynamicmodint&\
    \ operator-=(const dynamicmodint& o) noexcept {\n        val -= o.val;\n     \
    \   if (val < 0) val += dynamicmodint_MOD;\n        return *this;\n    }\n   \
    \ dynamicmodint& operator*=(const dynamicmodint& o) noexcept {\n        __int128\
    \ t = ( __int128 )val * o.val;\n        val = (long long)(t % dynamicmodint_MOD);\n\
    \        if (val < 0) val += dynamicmodint_MOD;\n        return *this;\n    }\n\
    \    dynamicmodint& operator/=(dynamicmodint o) noexcept {\n        *this *= o.inv();\n\
    \        return *this;\n    }\n    dynamicmodint operator-() const noexcept {\
    \ return dynamicmodint() - *this; }\n    dynamicmodint& operator++() noexcept\
    \ { return *this += 1; }\n    dynamicmodint operator++(int) noexcept { dynamicmodint\
    \ tmp = *this; ++*this; return tmp; }\n    dynamicmodint& operator--() noexcept\
    \ { return *this -= 1; }\n    dynamicmodint operator--(int) noexcept { dynamicmodint\
    \ tmp = *this; --*this; return tmp; }\n    bool operator==(const dynamicmodint&\
    \ o) const noexcept { return val == o.val; }\n    bool operator!=(const dynamicmodint&\
    \ o) const noexcept { return val != o.val; }\n    friend istream& operator>>(istream&\
    \ in, dynamicmodint& x) {\n        long long y; in >> y;\n        x = dynamicmodint(y);\n\
    \        return in;\n    }\n    friend ostream& operator<<(ostream& out, const\
    \ dynamicmodint& x) {\n        out << x.val;\n        return out;\n    }\n   \
    \ dynamicmodint pow(long long n) const noexcept {\n        if (n < 0) return inv().pow(-n);\n\
    \        dynamicmodint base = *this, res = 1;\n        while (n > 0) {\n     \
    \       if (n & 1) res *= base;\n            base *= base;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n    dynamicmodint inv() const noexcept\
    \ {\n        long long a = val;\n        long long m = dynamicmodint_MOD;\n  \
    \      long long b = m;\n        long long u = 1, v = 0;\n        while (b) {\n\
    \            long long t = a / b;\n            a -= t * b; swap(a, b);\n     \
    \       u -= t * v; swap(u, v);\n        }\n        long long res = u % m;\n \
    \       if (res < 0) res += m;\n        return dynamicmodint(res);\n    }\n  \
    \  template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n \
    \   dynamicmodint& operator+=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        val += y;\n        if (val >= dynamicmodint_MOD) val -= dynamicmodint_MOD;\n\
    \        return *this;\n    }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator-=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        val -= y;\n        if (val < 0) val += dynamicmodint_MOD;\n        return\
    \ *this;\n    }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator*=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        __int128 t = (__int128)val * y;\n        val = (long long)(t % dynamicmodint_MOD);\n\
    \        if (val < 0) val += dynamicmodint_MOD;\n        return *this;\n    }\n\
    \    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator/=(Int x) noexcept {\n        dynamicmodint t = dynamicmodint(adjust<Int>(x));\n\
    \        *this /= t;\n        return *this;\n    }\n    template<typename Int,\
    \ typename = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator+(dynamicmodint\
    \ a, Int b) noexcept { a += b; return a; }\n    template<typename Int, typename\
    \ = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator+(Int\
    \ a, dynamicmodint b) noexcept { b += a; return b; }\n    template<typename Int,\
    \ typename = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator-(dynamicmodint\
    \ a, Int b) noexcept { a -= b; return a; }\n    template<typename Int, typename\
    \ = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator-(Int\
    \ a, dynamicmodint b) noexcept { dynamicmodint t(a); t -= b; return t; }\n   \
    \ template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n  \
    \  friend dynamicmodint operator*(dynamicmodint a, Int b) noexcept { a *= b; return\
    \ a; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator*(Int a, dynamicmodint b) noexcept { b *= a;\
    \ return b; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator/(dynamicmodint a, Int b) noexcept { a /= b;\
    \ return a; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator/(Int a, dynamicmodint b) noexcept { dynamicmodint\
    \ t(a); t /= b; return t; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator==(const dynamicmodint& a, Int b) noexcept { return a.val\
    \ == adjust<Int>(b); }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator==(Int a, const dynamicmodint& b) noexcept { return adjust<Int>(a)\
    \ == b.val; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator!=(const dynamicmodint& a, Int b) noexcept { return !(a\
    \ == b); }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator!=(Int a, const dynamicmodint& b) noexcept { return !(a\
    \ == b); }\n};\nlong long dynamicmodint::dynamicmodint_MOD = 0;\n\nstruct dynamicmodintfactor\
    \ {\n    vector<dynamicmodint> fac, ifac;\n    dynamicmodintfactor(int n = 0)\
    \ : fac(n+1), ifac(n+1) {\n        fac[0] = 1;\n        for (int i=1; i<=n; i++)\
    \ fac[i] = fac[i-1] * i;\n        ifac[n] = fac[n].inv();\n        for (int i=n;\
    \ 1<=i; i--) ifac[i-1] = ifac[i] * i;\n    }\n    dynamicmodint P(int n, int r)\
    \ const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r]; }\n    dynamicmodint\
    \ C(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : P(n, r) * ifac[r];\
    \ }\n    dynamicmodint H(int n, int r) const noexcept { return (n==0 && r==0)\
    \ ? 1 : C(n+r-1, r); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct dynamicmodint\
    \ {\n    static long long dynamicmodint_MOD;\n    long long val;\n    static void\
    \ setmod(long long m) {\n        dynamicmodint_MOD = m;\n    }\n    static long\
    \ long mod() noexcept { return dynamicmodint_MOD; }\n    dynamicmodint(long long\
    \ x = 0) noexcept {\n        if (dynamicmodint_MOD == 0) dynamicmodint_MOD = 998244353;\n\
    \        val = adjust<long long>(x);\n    }\n    explicit operator long long()\
    \ const noexcept { return val; }\n    template<typename Int>\n    static long\
    \ long adjust(Int x) noexcept {\n        static_assert(std::is_integral<Int>::value,\
    \ \"Int must be integral\");\n        if (dynamicmodint_MOD == 0) dynamicmodint_MOD\
    \ = 998244353;\n        __int128 t = static_cast<__int128>(x);\n        __int128\
    \ m = static_cast<__int128>(dynamicmodint_MOD);\n        t %= m;\n        if (t\
    \ < 0) t += m;\n        return static_cast<long long>(t);\n    }\n    dynamicmodint\
    \ operator+(const dynamicmodint& o) const noexcept { return dynamicmodint(*this)\
    \ += o; }\n    dynamicmodint operator-(const dynamicmodint& o) const noexcept\
    \ { return dynamicmodint(*this) -= o; }\n    dynamicmodint operator*(const dynamicmodint&\
    \ o) const noexcept { return dynamicmodint(*this) *= o; }\n    dynamicmodint operator/(const\
    \ dynamicmodint& o) const noexcept { return dynamicmodint(*this) /= o; }\n   \
    \ dynamicmodint& operator+=(const dynamicmodint& o) noexcept {\n        val +=\
    \ o.val;\n        if (val >= dynamicmodint_MOD) val -= dynamicmodint_MOD;\n  \
    \      return *this;\n    }\n    dynamicmodint& operator-=(const dynamicmodint&\
    \ o) noexcept {\n        val -= o.val;\n        if (val < 0) val += dynamicmodint_MOD;\n\
    \        return *this;\n    }\n    dynamicmodint& operator*=(const dynamicmodint&\
    \ o) noexcept {\n        __int128 t = ( __int128 )val * o.val;\n        val =\
    \ (long long)(t % dynamicmodint_MOD);\n        if (val < 0) val += dynamicmodint_MOD;\n\
    \        return *this;\n    }\n    dynamicmodint& operator/=(dynamicmodint o)\
    \ noexcept {\n        *this *= o.inv();\n        return *this;\n    }\n    dynamicmodint\
    \ operator-() const noexcept { return dynamicmodint() - *this; }\n    dynamicmodint&\
    \ operator++() noexcept { return *this += 1; }\n    dynamicmodint operator++(int)\
    \ noexcept { dynamicmodint tmp = *this; ++*this; return tmp; }\n    dynamicmodint&\
    \ operator--() noexcept { return *this -= 1; }\n    dynamicmodint operator--(int)\
    \ noexcept { dynamicmodint tmp = *this; --*this; return tmp; }\n    bool operator==(const\
    \ dynamicmodint& o) const noexcept { return val == o.val; }\n    bool operator!=(const\
    \ dynamicmodint& o) const noexcept { return val != o.val; }\n    friend istream&\
    \ operator>>(istream& in, dynamicmodint& x) {\n        long long y; in >> y;\n\
    \        x = dynamicmodint(y);\n        return in;\n    }\n    friend ostream&\
    \ operator<<(ostream& out, const dynamicmodint& x) {\n        out << x.val;\n\
    \        return out;\n    }\n    dynamicmodint pow(long long n) const noexcept\
    \ {\n        if (n < 0) return inv().pow(-n);\n        dynamicmodint base = *this,\
    \ res = 1;\n        while (n > 0) {\n            if (n & 1) res *= base;\n   \
    \         base *= base;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    dynamicmodint inv() const noexcept {\n        long long a = val;\n\
    \        long long m = dynamicmodint_MOD;\n        long long b = m;\n        long\
    \ long u = 1, v = 0;\n        while (b) {\n            long long t = a / b;\n\
    \            a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n  \
    \      }\n        long long res = u % m;\n        if (res < 0) res += m;\n   \
    \     return dynamicmodint(res);\n    }\n    template<typename Int, typename =\
    \ enable_if_t<is_integral<Int>::value>>\n    dynamicmodint& operator+=(Int x)\
    \ noexcept {\n        long long y = adjust<Int>(x);\n        val += y;\n     \
    \   if (val >= dynamicmodint_MOD) val -= dynamicmodint_MOD;\n        return *this;\n\
    \    }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator-=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        val -= y;\n        if (val < 0) val += dynamicmodint_MOD;\n        return\
    \ *this;\n    }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator*=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        __int128 t = (__int128)val * y;\n        val = (long long)(t % dynamicmodint_MOD);\n\
    \        if (val < 0) val += dynamicmodint_MOD;\n        return *this;\n    }\n\
    \    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    dynamicmodint& operator/=(Int x) noexcept {\n        dynamicmodint t = dynamicmodint(adjust<Int>(x));\n\
    \        *this /= t;\n        return *this;\n    }\n    template<typename Int,\
    \ typename = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator+(dynamicmodint\
    \ a, Int b) noexcept { a += b; return a; }\n    template<typename Int, typename\
    \ = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator+(Int\
    \ a, dynamicmodint b) noexcept { b += a; return b; }\n    template<typename Int,\
    \ typename = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator-(dynamicmodint\
    \ a, Int b) noexcept { a -= b; return a; }\n    template<typename Int, typename\
    \ = enable_if_t<is_integral<Int>::value>>\n    friend dynamicmodint operator-(Int\
    \ a, dynamicmodint b) noexcept { dynamicmodint t(a); t -= b; return t; }\n   \
    \ template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n  \
    \  friend dynamicmodint operator*(dynamicmodint a, Int b) noexcept { a *= b; return\
    \ a; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator*(Int a, dynamicmodint b) noexcept { b *= a;\
    \ return b; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator/(dynamicmodint a, Int b) noexcept { a /= b;\
    \ return a; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend dynamicmodint operator/(Int a, dynamicmodint b) noexcept { dynamicmodint\
    \ t(a); t /= b; return t; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator==(const dynamicmodint& a, Int b) noexcept { return a.val\
    \ == adjust<Int>(b); }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator==(Int a, const dynamicmodint& b) noexcept { return adjust<Int>(a)\
    \ == b.val; }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator!=(const dynamicmodint& a, Int b) noexcept { return !(a\
    \ == b); }\n    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>\n\
    \    friend bool operator!=(Int a, const dynamicmodint& b) noexcept { return !(a\
    \ == b); }\n};\nlong long dynamicmodint::dynamicmodint_MOD = 0;\n\nstruct dynamicmodintfactor\
    \ {\n    vector<dynamicmodint> fac, ifac;\n    dynamicmodintfactor(int n = 0)\
    \ : fac(n+1), ifac(n+1) {\n        fac[0] = 1;\n        for (int i=1; i<=n; i++)\
    \ fac[i] = fac[i-1] * i;\n        ifac[n] = fac[n].inv();\n        for (int i=n;\
    \ 1<=i; i--) ifac[i-1] = ifac[i] * i;\n    }\n    dynamicmodint P(int n, int r)\
    \ const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r]; }\n    dynamicmodint\
    \ C(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : P(n, r) * ifac[r];\
    \ }\n    dynamicmodint H(int n, int r) const noexcept { return (n==0 && r==0)\
    \ ? 1 : C(n+r-1, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamicmodint.hpp
  requiredBy: []
  timestamp: '2025-10-07 20:44:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamicmodint.hpp
layout: document
redirect_from:
- /library/math/dynamicmodint.hpp
- /library/math/dynamicmodint.hpp.html
title: math/dynamicmodint.hpp
---
