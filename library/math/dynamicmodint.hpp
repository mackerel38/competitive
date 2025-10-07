#pragma once
#include<bits/stdc++.h>
using namespace std;

struct dynamicmodint {
    static int mod;
    int val;
    dynamicmodint(long long x = 0, long long modint_MOD = 998244353) noexcept {
        mod = modint_MOD;
        if (mod <= x) x %= mod;
        if (x < 0) x += mod;
        val = x;
    }
    dynamicmodint operator+(const dynamicmodint x) const noexcept {
        return dynamicmodint(*this) += x;
    }
    dynamicmodint operator-(const dynamicmodint x) const noexcept {
        return dynamicmodint(*this) -= x;
    }
    dynamicmodint operator*(const dynamicmodint x) const noexcept {
        return dynamicmodint(*this) *= x;
    }
    dynamicmodint operator/(const dynamicmodint x) const noexcept {
        return dynamicmodint(*this) /= x;
    }
    dynamicmodint& operator+=(const dynamicmodint x) noexcept {
        val += x.val;
        if (mod <= val) val -= mod;
        return *this;
    }
    dynamicmodint& operator-=(const dynamicmodint x) noexcept {
        val -= x.val;
        if (val < 0) val += mod;
        return *this;
    }
    dynamicmodint& operator*=(const dynamicmodint x) noexcept {
        val = (long long)val * x.val % mod;
        return *this;
    }
    dynamicmodint& operator/=(dynamicmodint x) noexcept {
        *this *= x.inv();
        return *this;
    }
    dynamicmodint operator-() const noexcept {
        return dynamicmodint() - *this;
    }
    bool operator==(const dynamicmodint x) const noexcept {
        return val == x.val;
    }
    bool operator!=(const dynamicmodint x) const noexcept {
        return val != x.val;
    }
    dynamicmodint& operator++() noexcept {
        return *this += 1;
    }
    dynamicmodint& operator--() noexcept {
        return *this -= 1;
    }
    friend istream& operator>> (istream& i, dynamicmodint& x) noexcept {
        long long y; i >> y;
        x = dynamicmodint(y);
        return i;
    }
    friend ostream& operator<< (ostream& o, const dynamicmodint& x) noexcept {
        o << x.val;
        return o;
    }
    long long pow(long long n) const noexcept {
        dynamicmodint x = *this, re = 1;
        while (n) {
            if (n & 1) re *= x;
            x *= x;
            n >>= 1;
        }
        return re.val;
    }
    dynamicmodint inv() const noexcept {
        int a = val, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return dynamicmodint(u);
    }
};

struct dynamicmodintfactor {
    vector<dynamicmodint> fac, ifac;
    dynamicmodintfactor(int n=1, long long mod = 998244353) noexcept : fac(n+1), ifac(n+1) {
        fac[0] = 1;
        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
        ifac[n] = fac[n].inv();
        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;
    }
    dynamicmodint P(int n, int r) const noexcept {
        if (r<0 || n<r) return 0;
        return fac[n] * ifac[n-r];
    }
    dynamicmodint C(int n, int r) const noexcept {
        if (r<0 || n<r) return 0;
        return P(n, r) * ifac[r];
    }
    dynamicmodint H(int n, int r) const noexcept {
        if (n<0 || r<0) return 0;
        return C(n+r-1, r);
    }
};