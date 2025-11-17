---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/NTT.hpp
    title: math/NTT.hpp
  - icon: ':x:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  - icon: ':x:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
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
    \ { return (n==0 && r==0) ? 1 : C(n+r-1, r); }\n};\n#line 4 \"math/NTT.hpp\"\n\
    using namespace std;\n\ntemplate <long long NTT_MOD>\nvoid NTT(vector<modint<NTT_MOD>>&\
    \ a, bool inv=false, int g_=3) {\n    modint<NTT_MOD> g = g_;\n    int n = (int)a.size();\n\
    \    for (int i=1, j=0; i<n; i++) {\n        int bit = n >> 1;\n        for (;\
    \ j&bit; bit>>=1) j ^= bit;\n        j ^= bit;\n        if (i < j) swap(a[i],\
    \ a[j]);\n    }\n    for (int len=2; len<=n; len<<=1) {\n        modint<NTT_MOD>\
    \ wlen = g.pow((NTT_MOD - 1) / len);\n        if (inv) wlen = wlen.inv();\n  \
    \      for (int i=0; i<n; i+=len) {\n            modint<NTT_MOD> w = 1;\n    \
    \        for (int j=0; j<len/2; j++) {\n                modint<NTT_MOD> u = a[i+j];\n\
    \                modint<NTT_MOD> v = a[i+j+len/2]*w;\n                a[i+j] =\
    \ u + v;\n                a[i+j+len/2] = u - v;\n                w *= wlen;\n\
    \            }\n        }\n    }\n    if (inv) {\n        modint<NTT_MOD> inv_n\
    \ = modint<NTT_MOD>(n).inv();\n        for (auto& x : a) x *= inv_n;\n    }\n\
    }\n#line 4 \"math/convolution.hpp\"\nusing namespace std;\n\ntemplate<long long\
    \ convolution_MOD>\nvector<modint<convolution_MOD>> convolution(vector<modint<convolution_MOD>>\
    \ a,vector<modint<convolution_MOD>> b){\n    int n = 1;\n    int s = (int)(a.size()+b.size()-1);\n\
    \    while (n < s) n<<=1;\n    a.resize(n);\n    b.resize(n);\n    NTT(a);\n \
    \   NTT(b);\n    for (int i=0; i<n; i++) a[i] *= b[i];\n    NTT(a,true);\n   \
    \ a.resize(s);\n    return a;\n}\n#line 4 \"math/FPSbase.hpp\"\nusing namespace\
    \ std;\n\ntemplate <long long FPS_MOD>\nstruct FPS : vector<modint<FPS_MOD>> {\n\
    \    using mint = modint<FPS_MOD>;\n    using vector<mint>::size;\n    using vector<mint>::empty;\n\
    \    using vector<mint>::resize;\n    using vector<mint>::operator[];\n    FPS()\
    \ : vector<mint>() {}\n    FPS(size_t n) : vector<mint>(n) {}\n    FPS(size_t\
    \ n, const mint& x) : vector<mint>(n, x) {}\n    FPS(const initializer_list<mint>&\
    \ il) : vector<mint>(il) {}\n    template<class It>\n    FPS(It first, It last)\
    \ : vector<mint>(first, last) {}\n    FPS(const vector<mint>& v) : vector<mint>(v)\
    \ {}\n    FPS(vector<mint>&& v) : vector<mint>(move(v)) {}\n    static vector<mint>\
    \ to_vec(const FPS& f) {\n        return vector<mint>(f.begin(), f.end());\n \
    \   }\n    static FPS from_vec(const vector<mint>& v) { return FPS(v); }\n   \
    \ static FPS from_vec(vector<mint>&& v) { return FPS(move(v)); }\n    FPS low(int\
    \ n) const {\n        int take = min(n, (int)this->size());\n        return FPS(this->begin(),\
    \ this->begin() + take);\n    }\n    FPS& shrink() {\n        while (!this->empty()\
    \ && this->back() == mint(0)) this->pop_back();\n        return *this;\n    }\n\
    \    FPS operator-() const {\n        FPS res = *this;\n        for (auto& x :\
    \ res) x = -x;\n        return res;\n    }\n    FPS& operator+=(const FPS& x)\
    \ {\n        if (size() < x.size()) resize(x.size());\n        for (int i = 0;\
    \ i < (int)x.size(); i++) (*this)[i] += x[i];\n        return *this;\n    }\n\
    \    FPS& operator-=(const FPS& x) {\n        if (size() < x.size()) resize(x.size());\n\
    \        for (int i = 0; i < (int)x.size(); i++) (*this)[i] -= x[i];\n       \
    \ return *this;\n    }\n    FPS& operator*=(const FPS& x) {\n        auto va =\
    \ to_vec(*this);\n        auto vb = to_vec(x);\n        *this = from_vec(convolution(va,\
    \ vb));\n        return *this;\n    }\n    FPS operator*(const FPS& x) const {\
    \ FPS t = *this; t *= x; return t; }\n    FPS& operator*=(const mint& c) {\n \
    \       for (auto& y : *this) y *= c;\n        return *this;\n    }\n    FPS operator*(const\
    \ mint& x) const { FPS t = *this; t *= x; return t; }\n    FPS& operator/=(const\
    \ mint& c) {\n        mint invc = c.inv();\n        for (auto& y : *this) y *=\
    \ invc;\n        return *this;\n    }\n    FPS operator/(const mint& x) const\
    \ { FPS t = *this; t /= x; return t; }\n    FPS operator+(const FPS& x) const\
    \ { return FPS(*this) += x; }\n    FPS operator-(const FPS& x) const { return\
    \ FPS(*this) -= x; }\n    FPS diff() const {\n        if (empty()) return FPS();\n\
    \        FPS g(size() - 1);\n        for (int i = 1; i < (int)size(); i++) g[i\
    \ - 1] = (*this)[i] * mint(i);\n        return g;\n    }\n    FPS integ() const\
    \ {\n        FPS g(size() + 1);\n        static vector<mint> invs = {mint(0),\
    \ mint(1)};\n        int n = g.size();\n        for (int i=(int)invs.size(); i<n;\
    \ i++) invs.push_back(-invs[FPS_MOD % i] * mint(FPS_MOD / i));\n        for (int\
    \ i=0; i<(int)size(); i++) g[i+1] = (*this)[i] * invs[i+1];\n        return g;\n\
    \    }\n    FPS inv(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ != 0);\n        int n = this->size();\n        if (deg == -1) deg = n;\n   \
    \     FPS res; res.resize(1); res[0] = (*this)[0].inv();\n        for (int m=1;\
    \ m<deg; m<<=1) {\n            int cut = 2 * m;\n            FPS f_low = this->low(cut);\n\
    \            auto vres = to_vec(res);\n            auto vres2 = vres;\n      \
    \      auto v_f_low = to_vec(f_low);\n            auto t1 = convolution(vres,\
    \ vres2);\n            auto t2 = convolution(t1, v_f_low);\n            FPS t\
    \ = from_vec(move(t2));\n            t.resize(cut);\n            res.resize(cut);\n\
    \            for (int i=0; i<cut; i++) {\n                mint ti = (i < (int)t.size()\
    \ ? t[i] : mint(0));\n                res[i] = res[i] * mint(2) - ti;\n      \
    \      }\n            res = res.low(cut);\n        }\n        res.resize(deg);\n\
    \        return res;\n    }\n    pair<FPS, FPS> divmod(const FPS& g) const {\n\
    \        FPS f = *this;\n        if (f.size() < g.size()) return {FPS{mint(0)},\
    \ f};\n        int n = f.size(), m = g.size();\n        FPS rf = f, rg = g;\n\
    \        reverse(rf.begin(), rf.end());\n        reverse(rg.begin(), rg.end());\n\
    \        auto vrf = to_vec(rf);\n        auto vrg = to_vec(rg);\n        FPS tmp\
    \ = from_vec(convolution(vrf, to_vec(rg.inv(n - m + 1))));\n        FPS q = tmp.low(n\
    \ - m + 1);\n        reverse(q.begin(), q.end());\n        FPS r = f - g * q;\n\
    \        r.resize(m - 1);\n        return {q, r};\n    }\n    FPS log(int deg\
    \ = -1) const {\n        assert(!this->empty() && (*this)[0] == mint(1));\n  \
    \      int n = this->size();\n        if (deg == -1) deg = n;\n        FPS f =\
    \ diff();\n        FPS invf = this->inv(deg);\n        auto vf = to_vec(f), vinvf\
    \ = to_vec(invf);\n        FPS g = from_vec(convolution(vf, vinvf)).low(deg -\
    \ 1).integ();\n        g.resize(deg);\n        return g;\n    }\n    FPS exp(int\
    \ deg = -1) const {\n        assert(!this->empty() && (*this)[0] == mint(0));\n\
    \        int n = this->size();\n        if (deg == -1) deg = n;\n        FPS g;\
    \ g.resize(1); g[0] = mint(1);\n        for (int m=1; m<deg; m<<=1) {\n      \
    \      int cut = 2 * m;\n            FPS g_log = g.log(cut);\n            FPS\
    \ q = this->low(cut) - g_log;\n            q[0] += mint(1);\n            auto\
    \ vg = to_vec(g), vq = to_vec(q);\n            FPS ng = from_vec(convolution(vg,\
    \ vq)).low(cut);\n            g = move(ng);\n        }\n        g.resize(deg);\n\
    \        return g;\n    }\n    FPS pow(long long k, int n=-1) const {\n      \
    \  int v = 0;\n        while(v < (int)this->size() && (*this)[v].val == 0) v++;\n\
    \        if (v == (int)this->size()) return FPS(n, mint(0));\n        if (n ==\
    \ -1) n = this->size();\n    }\n};\n"
  code: "#pragma once\n#include \"convolution\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <long long FPS_MOD>\nstruct FPS : vector<modint<FPS_MOD>> {\n\
    \    using mint = modint<FPS_MOD>;\n    using vector<mint>::size;\n    using vector<mint>::empty;\n\
    \    using vector<mint>::resize;\n    using vector<mint>::operator[];\n    FPS()\
    \ : vector<mint>() {}\n    FPS(size_t n) : vector<mint>(n) {}\n    FPS(size_t\
    \ n, const mint& x) : vector<mint>(n, x) {}\n    FPS(const initializer_list<mint>&\
    \ il) : vector<mint>(il) {}\n    template<class It>\n    FPS(It first, It last)\
    \ : vector<mint>(first, last) {}\n    FPS(const vector<mint>& v) : vector<mint>(v)\
    \ {}\n    FPS(vector<mint>&& v) : vector<mint>(move(v)) {}\n    static vector<mint>\
    \ to_vec(const FPS& f) {\n        return vector<mint>(f.begin(), f.end());\n \
    \   }\n    static FPS from_vec(const vector<mint>& v) { return FPS(v); }\n   \
    \ static FPS from_vec(vector<mint>&& v) { return FPS(move(v)); }\n    FPS low(int\
    \ n) const {\n        int take = min(n, (int)this->size());\n        return FPS(this->begin(),\
    \ this->begin() + take);\n    }\n    FPS& shrink() {\n        while (!this->empty()\
    \ && this->back() == mint(0)) this->pop_back();\n        return *this;\n    }\n\
    \    FPS operator-() const {\n        FPS res = *this;\n        for (auto& x :\
    \ res) x = -x;\n        return res;\n    }\n    FPS& operator+=(const FPS& x)\
    \ {\n        if (size() < x.size()) resize(x.size());\n        for (int i = 0;\
    \ i < (int)x.size(); i++) (*this)[i] += x[i];\n        return *this;\n    }\n\
    \    FPS& operator-=(const FPS& x) {\n        if (size() < x.size()) resize(x.size());\n\
    \        for (int i = 0; i < (int)x.size(); i++) (*this)[i] -= x[i];\n       \
    \ return *this;\n    }\n    FPS& operator*=(const FPS& x) {\n        auto va =\
    \ to_vec(*this);\n        auto vb = to_vec(x);\n        *this = from_vec(convolution(va,\
    \ vb));\n        return *this;\n    }\n    FPS operator*(const FPS& x) const {\
    \ FPS t = *this; t *= x; return t; }\n    FPS& operator*=(const mint& c) {\n \
    \       for (auto& y : *this) y *= c;\n        return *this;\n    }\n    FPS operator*(const\
    \ mint& x) const { FPS t = *this; t *= x; return t; }\n    FPS& operator/=(const\
    \ mint& c) {\n        mint invc = c.inv();\n        for (auto& y : *this) y *=\
    \ invc;\n        return *this;\n    }\n    FPS operator/(const mint& x) const\
    \ { FPS t = *this; t /= x; return t; }\n    FPS operator+(const FPS& x) const\
    \ { return FPS(*this) += x; }\n    FPS operator-(const FPS& x) const { return\
    \ FPS(*this) -= x; }\n    FPS diff() const {\n        if (empty()) return FPS();\n\
    \        FPS g(size() - 1);\n        for (int i = 1; i < (int)size(); i++) g[i\
    \ - 1] = (*this)[i] * mint(i);\n        return g;\n    }\n    FPS integ() const\
    \ {\n        FPS g(size() + 1);\n        static vector<mint> invs = {mint(0),\
    \ mint(1)};\n        int n = g.size();\n        for (int i=(int)invs.size(); i<n;\
    \ i++) invs.push_back(-invs[FPS_MOD % i] * mint(FPS_MOD / i));\n        for (int\
    \ i=0; i<(int)size(); i++) g[i+1] = (*this)[i] * invs[i+1];\n        return g;\n\
    \    }\n    FPS inv(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ != 0);\n        int n = this->size();\n        if (deg == -1) deg = n;\n   \
    \     FPS res; res.resize(1); res[0] = (*this)[0].inv();\n        for (int m=1;\
    \ m<deg; m<<=1) {\n            int cut = 2 * m;\n            FPS f_low = this->low(cut);\n\
    \            auto vres = to_vec(res);\n            auto vres2 = vres;\n      \
    \      auto v_f_low = to_vec(f_low);\n            auto t1 = convolution(vres,\
    \ vres2);\n            auto t2 = convolution(t1, v_f_low);\n            FPS t\
    \ = from_vec(move(t2));\n            t.resize(cut);\n            res.resize(cut);\n\
    \            for (int i=0; i<cut; i++) {\n                mint ti = (i < (int)t.size()\
    \ ? t[i] : mint(0));\n                res[i] = res[i] * mint(2) - ti;\n      \
    \      }\n            res = res.low(cut);\n        }\n        res.resize(deg);\n\
    \        return res;\n    }\n    pair<FPS, FPS> divmod(const FPS& g) const {\n\
    \        FPS f = *this;\n        if (f.size() < g.size()) return {FPS{mint(0)},\
    \ f};\n        int n = f.size(), m = g.size();\n        FPS rf = f, rg = g;\n\
    \        reverse(rf.begin(), rf.end());\n        reverse(rg.begin(), rg.end());\n\
    \        auto vrf = to_vec(rf);\n        auto vrg = to_vec(rg);\n        FPS tmp\
    \ = from_vec(convolution(vrf, to_vec(rg.inv(n - m + 1))));\n        FPS q = tmp.low(n\
    \ - m + 1);\n        reverse(q.begin(), q.end());\n        FPS r = f - g * q;\n\
    \        r.resize(m - 1);\n        return {q, r};\n    }\n    FPS log(int deg\
    \ = -1) const {\n        assert(!this->empty() && (*this)[0] == mint(1));\n  \
    \      int n = this->size();\n        if (deg == -1) deg = n;\n        FPS f =\
    \ diff();\n        FPS invf = this->inv(deg);\n        auto vf = to_vec(f), vinvf\
    \ = to_vec(invf);\n        FPS g = from_vec(convolution(vf, vinvf)).low(deg -\
    \ 1).integ();\n        g.resize(deg);\n        return g;\n    }\n    FPS exp(int\
    \ deg = -1) const {\n        assert(!this->empty() && (*this)[0] == mint(0));\n\
    \        int n = this->size();\n        if (deg == -1) deg = n;\n        FPS g;\
    \ g.resize(1); g[0] = mint(1);\n        for (int m=1; m<deg; m<<=1) {\n      \
    \      int cut = 2 * m;\n            FPS g_log = g.log(cut);\n            FPS\
    \ q = this->low(cut) - g_log;\n            q[0] += mint(1);\n            auto\
    \ vg = to_vec(g), vq = to_vec(q);\n            FPS ng = from_vec(convolution(vg,\
    \ vq)).low(cut);\n            g = move(ng);\n        }\n        g.resize(deg);\n\
    \        return g;\n    }\n    FPS pow(long long k, int n=-1) const {\n      \
    \  int v = 0;\n        while(v < (int)this->size() && (*this)[v].val == 0) v++;\n\
    \        if (v == (int)this->size()) return FPS(n, mint(0));\n        if (n ==\
    \ -1) n = this->size();\n    }\n};\n"
  dependsOn:
  - math/convolution.hpp
  - math/NTT.hpp
  - math/modint.hpp
  isVerificationFile: false
  path: math/FPSbase.hpp
  requiredBy: []
  timestamp: '2025-10-21 09:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FPSbase.hpp
layout: document
redirect_from:
- /library/math/FPSbase.hpp
- /library/math/FPSbase.hpp.html
title: math/FPSbase.hpp
---
