#pragma once
#include <bits/stdc++.h>
using namespace std;

struct dynamicmodint {
    static long long dynamicmodint_MOD;
    long long val;
    static void setmod(long long m) {
        dynamicmodint_MOD = m;
    }
    static long long mod() noexcept { return dynamicmodint_MOD; }
    dynamicmodint(long long x = 0) noexcept {
        if (dynamicmodint_MOD == 0) dynamicmodint_MOD = 998244353;
        val = adjust<long long>(x);
    }
    explicit operator long long() const noexcept { return val; }
    template<typename Int>
    static long long adjust(Int x) noexcept {
        static_assert(std::is_integral<Int>::value, "Int must be integral");
        if (dynamicmodint_MOD == 0) dynamicmodint_MOD = 998244353;
        __int128 t = static_cast<__int128>(x);
        __int128 m = static_cast<__int128>(dynamicmodint_MOD);
        t %= m;
        if (t < 0) t += m;
        return static_cast<long long>(t);
    }
    dynamicmodint operator+(const dynamicmodint& o) const noexcept { return dynamicmodint(*this) += o; }
    dynamicmodint operator-(const dynamicmodint& o) const noexcept { return dynamicmodint(*this) -= o; }
    dynamicmodint operator*(const dynamicmodint& o) const noexcept { return dynamicmodint(*this) *= o; }
    dynamicmodint operator/(const dynamicmodint& o) const noexcept { return dynamicmodint(*this) /= o; }
    dynamicmodint& operator+=(const dynamicmodint& o) noexcept {
        val += o.val;
        if (val >= dynamicmodint_MOD) val -= dynamicmodint_MOD;
        return *this;
    }
    dynamicmodint& operator-=(const dynamicmodint& o) noexcept {
        val -= o.val;
        if (val < 0) val += dynamicmodint_MOD;
        return *this;
    }
    dynamicmodint& operator*=(const dynamicmodint& o) noexcept {
        __int128 t = ( __int128 )val * o.val;
        val = (long long)(t % dynamicmodint_MOD);
        if (val < 0) val += dynamicmodint_MOD;
        return *this;
    }
    dynamicmodint& operator/=(dynamicmodint o) noexcept {
        *this *= o.inv();
        return *this;
    }
    dynamicmodint operator-() const noexcept { return dynamicmodint() - *this; }
    dynamicmodint& operator++() noexcept { return *this += 1; }
    dynamicmodint operator++(int) noexcept { dynamicmodint tmp = *this; ++*this; return tmp; }
    dynamicmodint& operator--() noexcept { return *this -= 1; }
    dynamicmodint operator--(int) noexcept { dynamicmodint tmp = *this; --*this; return tmp; }
    bool operator==(const dynamicmodint& o) const noexcept { return val == o.val; }
    bool operator!=(const dynamicmodint& o) const noexcept { return val != o.val; }
    friend istream& operator>>(istream& in, dynamicmodint& x) {
        long long y; in >> y;
        x = dynamicmodint(y);
        return in;
    }
    friend ostream& operator<<(ostream& out, const dynamicmodint& x) {
        out << x.val;
        return out;
    }
    dynamicmodint pow(long long n) const noexcept {
        if (n < 0) return inv().pow(-n);
        dynamicmodint base = *this, res = 1;
        while (n > 0) {
            if (n & 1) res *= base;
            base *= base;
            n >>= 1;
        }
        return res;
    }
    dynamicmodint inv() const noexcept {
        long long a = val;
        long long m = dynamicmodint_MOD;
        long long b = m;
        long long u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        long long res = u % m;
        if (res < 0) res += m;
        return dynamicmodint(res);
    }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    dynamicmodint& operator+=(Int x) noexcept {
        long long y = adjust<Int>(x);
        val += y;
        if (val >= dynamicmodint_MOD) val -= dynamicmodint_MOD;
        return *this;
    }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    dynamicmodint& operator-=(Int x) noexcept {
        long long y = adjust<Int>(x);
        val -= y;
        if (val < 0) val += dynamicmodint_MOD;
        return *this;
    }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    dynamicmodint& operator*=(Int x) noexcept {
        long long y = adjust<Int>(x);
        __int128 t = (__int128)val * y;
        val = (long long)(t % dynamicmodint_MOD);
        if (val < 0) val += dynamicmodint_MOD;
        return *this;
    }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    dynamicmodint& operator/=(Int x) noexcept {
        dynamicmodint t = dynamicmodint(adjust<Int>(x));
        *this /= t;
        return *this;
    }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator+(dynamicmodint a, Int b) noexcept { a += b; return a; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator+(Int a, dynamicmodint b) noexcept { b += a; return b; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator-(dynamicmodint a, Int b) noexcept { a -= b; return a; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator-(Int a, dynamicmodint b) noexcept { dynamicmodint t(a); t -= b; return t; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator*(dynamicmodint a, Int b) noexcept { a *= b; return a; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator*(Int a, dynamicmodint b) noexcept { b *= a; return b; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator/(dynamicmodint a, Int b) noexcept { a /= b; return a; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend dynamicmodint operator/(Int a, dynamicmodint b) noexcept { dynamicmodint t(a); t /= b; return t; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend bool operator==(const dynamicmodint& a, Int b) noexcept { return a.val == adjust<Int>(b); }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend bool operator==(Int a, const dynamicmodint& b) noexcept { return adjust<Int>(a) == b.val; }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend bool operator!=(const dynamicmodint& a, Int b) noexcept { return !(a == b); }
    template<typename Int, typename = enable_if_t<is_integral<Int>::value>>
    friend bool operator!=(Int a, const dynamicmodint& b) noexcept { return !(a == b); }
};
long long dynamicmodint::dynamicmodint_MOD = 0;

struct dynamicmodintfactor {
    vector<dynamicmodint> fac, ifac;
    dynamicmodintfactor(int n = 0) : fac(n+1), ifac(n+1) {
        fac[0] = 1;
        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
        ifac[n] = fac[n].inv();
        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;
    }
    dynamicmodint P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r]; }
    dynamicmodint C(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : P(n, r) * ifac[r]; }
    dynamicmodint H(int n, int r) const noexcept { return (n==0 && r==0) ? 1 : C(n+r-1, r); }
};
