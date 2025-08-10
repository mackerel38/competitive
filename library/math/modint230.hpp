#pragma once
#include<bits/stdc++.h>
using namespace std;
long long modint_MOD = (1LL<<61)-1;
// mod の値を変更する(デフォルトは2^61-1)
void setmod(long long x) { modint_MOD = x; }
struct mint230 {
    long long val;
    mint230(long long x=0) {
        val=(x%modint_MOD+modint_MOD)%modint_MOD;
    }
    mint230& operator+=(const mint230& a) { val = (val + a.val) % modint_MOD; return *this; }
    mint230& operator-=(const mint230& a) { val = (val - a.val + modint_MOD) % modint_MOD; return *this; }
    mint230& operator*=(const mint230& a) { val = (__int128_t)val * a.val % modint_MOD ; return *this; }
    mint230& operator/=(const mint230& a) { return *this *= a.inv(); }
    mint230 operator+(const mint230& a) const { return mint230(*this) += a; }
    mint230 operator-(const mint230& a) const { return mint230(*this) -= a; }
    mint230 operator*(const mint230& a) const { return mint230(*this) *= a; }
    mint230 operator/(const mint230& a) const { return mint230(*this) /= a; }
    bool operator==(const mint230& a) const { return val == a.val; }
    bool operator!=(const mint230& a) const { return val != a.val; }
    mint230& operator+=(int a) { return *this += mint230(a); }
    mint230& operator-=(int a) { return *this -= mint230(a); }
    mint230& operator*=(int a) { return *this *= mint230(a); }
    mint230& operator/=(int a) { return *this /= mint230(a); }
    mint230 operator+(int a) const { return mint230(*this) += a; }
    mint230 operator-(int a) const { return mint230(*this) -= a; }
    mint230 operator*(int a) const { return mint230(*this) *= a; }
    mint230 operator/(int a) const { return mint230(*this) /= a; }
    bool operator==(int a) const { return val == mint230(a).val; }
    bool operator!=(int a) const { return val != mint230(a).val; }
    friend mint230 operator+(int a,const mint230& b) { return mint230(a) + b; }
    friend mint230 operator-(int a,const mint230& b) { return mint230(a) - b; }
    friend mint230 operator*(int a,const mint230& b) { return mint230(a) * b; }
    friend mint230 operator/(int a,const mint230& b) { return mint230(a) / b; }
    friend bool operator==(int a, const mint230& b) { return mint230(a) == b; }
    friend bool operator!=(int a, const mint230& b) { return mint230(a) != b; }
    mint230& operator++() { return *this += 1; }
    mint230 operator++(int) { mint230 r = *this; *this += 1; return r; }
    mint230& operator--() { return *this -= 1; }
    mint230 operator--(int) { mint230 r = *this; *this -= 1; return r; }
    // modpow を計算する。計算量O(log mod)
    mint230 pow(long long n) const {
        if (n != 0) n = ((n-2) % (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;
        mint230 r = 1, a = *this;
        while (n) {
            if (n & 1) r *= a;
            a *= a;
            n >>= 1;
        }
        return r;
    }
    mint230 inv() const { return pow(-1); }
    friend ostream& operator<<(ostream&s, const mint230& a) { return s << a.val; }
    friend istream& operator>>(istream&s, mint230& a) { long long x; s >> x; a = mint230(x); return s; }
};
vector<mint230>fac, ifac;
// n までの階乗を前計算する。O(n)
void buildfac(int n) {
    fac.resize(n + 1);
    ifac.resize(n + 1);
    fac[0] = 1;
    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
    ifac[n] = mint230(1) / fac[n];
    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i;
}
// nCk を求める。buildfacの呼び出しが必須。O(1)
mint230 comb(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }
// nPk を求める。buildfacの呼び出しが必須。O(1)
mint230 perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }
