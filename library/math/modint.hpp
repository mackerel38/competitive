#pragma once
#include<bits/stdc++.h>
using namespace std;
long long modint_MOD = 998244353;
// mod の値を変更する(デフォルトは998244353)
void setmod(long long x) { modint_MOD = x; }
struct mint {
    long long val;
    mint(long long x=0) {
        val=(x%modint_MOD+modint_MOD)%modint_MOD;
    }
    mint& operator+=(const mint& a) { val = (val + a.val) % modint_MOD; return *this; }
    mint& operator-=(const mint& a) { val = (val - a.val + modint_MOD) % modint_MOD; return *this; }
    mint& operator*=(const mint& a) { val = val * a.val % modint_MOD ; return *this; }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    mint operator+(const mint& a) const { return mint(*this) += a; }
    mint operator-(const mint& a) const { return mint(*this) -= a; }
    mint operator*(const mint& a) const { return mint(*this) *= a; }
    mint operator/(const mint& a) const { return mint(*this) /= a; }
    bool operator==(const mint& a) const { return val == a.val; }
    bool operator!=(const mint& a) const { return val != a.val; }
    mint& operator+=(int a) { return *this += mint(a); }
    mint& operator-=(int a) { return *this -= mint(a); }
    mint& operator*=(int a) { return *this *= mint(a); }
    mint& operator/=(int a) { return *this /= mint(a); }
    mint operator+(int a) const { return mint(*this) += a; }
    mint operator-(int a) const { return mint(*this) -= a; }
    mint operator*(int a) const { return mint(*this) *= a; }
    mint operator/(int a) const { return mint(*this) /= a; }
    bool operator==(int a) const { return val == mint(a).val; }
    bool operator!=(int a) const { return val != mint(a).val; }
    friend mint operator+(int a,const mint& b) { return mint(a) + b; }
    friend mint operator-(int a,const mint& b) { return mint(a) - b; }
    friend mint operator*(int a,const mint& b) { return mint(a) * b; }
    friend mint operator/(int a,const mint& b) { return mint(a) / b; }
    friend bool operator==(int a, const mint& b) { return mint(a) == b; }
    friend bool operator!=(int a, const mint& b) { return mint(a) != b; }
    mint& operator++() { return *this += 1; }
    mint operator++(int) { mint r = *this; *this += 1; return r; }
    mint& operator--() { return *this -= 1; }
    mint operator--(int) { mint r = *this; *this -= 1; return r; }
    // modpow を計算する。計算量O(log mod)
    mint pow(long long n) const {
        if (n != 0) n %= modint_MOD - 1;
        mint r = 1, a = *this;
        while (n) {
            if (n & 1) r *= a;
            a *= a;
            n >>= 1;
        }
        return r;
    }
    mint inv() const { return pow(modint_MOD-2); }
    friend ostream& operator<<(ostream&s, const mint& a) { return s << a.val; }
    friend istream& operator>>(istream&s, mint& a) { long long x; s >> x; a = mint(x); return s; }
};
vector<mint>fac, ifac;
// n までの階乗を前計算する。O(n)
void buildfac(int n) {
    fac.resize(n + 1);
    ifac.resize(n + 1);
    fac[0] = 1;
    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
    ifac[n] = mint(1) / fac[n];
    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i;
}
// nCk を求める。buildfacの呼び出しが必須。O(1)
mint comb(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }
// nPk を求める。buildfacの呼び出しが必須。O(1)
mint perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }
