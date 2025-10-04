#pragma once
#include<bits/stdc++.h>
using namespace std;

ll modint_MOD = 998244353;

struct modint {
    long long val;
    constexpr modint() noexcept : val(0) {}
    constexpr modint(long long x) noexcept {
        long long v = x % modint_MOD;
        if (v < 0)  v+= modint_MOD;
        val = v;
    }
    constexpr modint& operator+=(const modint& a) noexcept { val += a.val; if (modint_MOD <= val) val -= modint_MOD; return *this; }
    constexpr modint& operator-=(const modint& a) noexcept { val -= a.val; if (val < 0) val += modint_MOD; return *this; }
    constexpr modint& operator*=(const modint& a) noexcept { val = (long long)(val * a.val % modint_MOD); return *this; }
    constexpr modint& operator/=(const modint& a) noexcept { return *this *= a.inv(); }
    constexpr modint operator-() const noexcept { return modint(val ? modint_MOD - val : 0); }
    friend constexpr modint operator+(modint a,const modint& b) noexcept { return a += b; }
    friend constexpr modint operator-(modint a,const modint& b) noexcept { return a -= b; }
    friend constexpr modint operator*(modint a,const modint& b) noexcept { return a *= b; }
    friend constexpr modint operator/(modint a,const modint& b) noexcept { return a /= b; }
    constexpr bool operator==(const modint& a) noexcept { return val == a.val; }
    constexpr bool operator!=(const modint& a) noexcept { return val != a.val; }
    constexpr modint pow(long long n) const noexcept {
        n %= modint_MOD - 1;
        if (n < 0) n += modint_MOD;
        modint r = 1, a = *this;
        while (n) {
            if (n & 1) r *= a;
            a *= a;
            n >>= 1;
        }
        return r;
    }
    constexpr modint inv() const noexcept { return pow(-1); }
    friend istream& operator>>(istream& is, modint& a) { long long x; is >> x; a = modint(x); return is; }
    friend ostream& operator<<(ostream& os, const modint& a) { os << a.val; return os; }
};

template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator+(T a, modint<modint_MOD> b) noexcept { return modint<modint_MOD>(a) + b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator-(T a, modint<modint_MOD> b) noexcept { return modint<modint_MOD>(a) - b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator*(T a, modint<modint_MOD> b) noexcept { return modint<modint_MOD>(a) * b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator/(T a, modint<modint_MOD> b) noexcept { return modint<modint_MOD>(a) / b; }

template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator+(modint<modint_MOD> a, T b) noexcept { return a += b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator-(modint<modint_MOD> a, T b) noexcept { return a -= b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator*(modint<modint_MOD> a, T b) noexcept { return a *= b; }
template <long long modint_MOD, class T, class = enable_if_t<is_integral_v<T>>>
constexpr modint<modint_MOD> operator/(modint<modint_MOD> a, T b) noexcept { return a /= b; }

