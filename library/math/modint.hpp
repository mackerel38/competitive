#pragma once
#include<bits/stdc++.h>
using namespace std;

template <long long modint_MOD>
struct modint {
    long long val;
    constexpr modint(long long x = 0) noexcept {
        x %= modint_MOD;
        if (x < 0) x += modint_MOD;
        val = x;
    }
    explicit constexpr operator long long() const noexcept { return val; }
    constexpr modint operator+(const modint& x) const noexcept { return modint(*this) += x; }
    constexpr modint operator-(const modint& x) const noexcept { return modint(*this) -= x; }
    constexpr modint operator*(const modint& x) const noexcept { return modint(*this) *= x; }
    constexpr modint operator/(const modint& x) const noexcept { return modint(*this) /= x; }
    constexpr modint& operator+=(const modint& x) noexcept {
        if (modint_MOD <= (val += x.val)) val -= modint_MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint& x) noexcept {
        if ((val -= x.val) < 0) val += modint_MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint& x) noexcept {
        val = val * x.val % modint_MOD;
        return *this;
    }
    constexpr modint& operator/=(modint& x) noexcept {
        *this *= x.inv();
        return *this;
    }
    constexpr modint operator-() const noexcept { return modint() - *this; }
    constexpr bool operator==(const modint& x) const noexcept { return val == x.val; }
    constexpr bool operator!=(const modint& x) const noexcept { return val != x.val; }
    constexpr modint& operator++() noexcept { return *this += 1; }
    constexpr modint& operator--() noexcept { return *this -= 1; }
    constexpr modint operator++(int) noexcept { modint tmp = *this; ++*this; return tmp; }
    constexpr modint operator--(int) noexcept { modint tmp = *this; --*this; return tmp; }
    friend constexpr istream& operator>> (istream& i, modint& x) { long long y; i >> y; x = modint(y); return i; }
    friend constexpr ostream& operator<< (ostream& o, const modint& x) { o << x.val; return o; }
    constexpr modint pow(long long n) const noexcept {
        modint x = *this, re = 1;
        while (0 < n){
            if (n & 1) re *= x;
            x *= x;
            n >>= 1;
        }
        return re;
    }
    constexpr modint inv() const noexcept { return pow(modint_MOD - 2); }
};

template <long long modint_MOD>
struct factor {
    vector<modint<modint_MOD>> fac, ifac;
    factor(int n) : fac(n+1), ifac(n+1) {
        fac[0] = 1;
        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
        ifac[n] = fac[n].inv();
        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;
    }
    modint<modint_MOD> P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r]; }
    modint<modint_MOD> C(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : P(n, r) * ifac[r]; }
    modint<modint_MOD> H(int n, int r) const noexcept { return (n==0 && r==0) ? 1 : C(n+r-1, r); }
};
