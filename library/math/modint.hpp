#pragma once
#include<bits/stdc++.h>
using namespace std;
template <long long modint_MOD>
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

long long fact_MOD = 998244353;

vector<long long> fac, ifac;
template <long long factMOD>
void buildfac(int n) noexcept {
    fact_MOD = factMOD;
    fac.reserve(n+1);
    ifac.resize(n+1);
    fac.emplace_back(1);
    for (int i=1; i<=n; i++) fac.emplace_back(fac[i-1] * i % fact_MOD);
    ifac[n] = (modint<fact_MOD>(1) / fac[n]).val;
    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i % fact_MOD;
}

template<long long factMOD = fact_MOD>
modint<factMOD> comb(int n, int k) noexcept {
    return modint<factMOD>(fac[n]) * ifac[n-k] * ifac[k];
}
template<long long factMOD = fact_MOD>
modint<factMOD> perm(int n, int k) noexcept {
    return modint<factMOD>(fac[n]) * ifac[n-k];
}
