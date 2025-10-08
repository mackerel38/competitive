#pragma once
#include "convolution"
#include <bits/stdc++.h>
using namespace std;

template <long long FPS_MOD>
struct FPS : vector<modint<FPS_MOD>> {
    using mint = modint<FPS_MOD>;
    using vector<mint>::vector;
    using vector<mint>::size;
    using vector<mint>::empty;
    using vector<mint>::resize;
    using vector<mint>::operator[];
    FPS(const vector<mint>& v) : vector<mint>(v) {}
    FPS(vector<mint>&& v) : vector<mint>(move(v)) {}
    FPS low(int n) const {
        return FPS(this->begin(), this->begin() + min<int>(n, size()));
    }
    FPS& shrink() {
        while (!this->empty() && this->back() == mint(0)) this->pop_back();
        return *this;
    }
    FPS operator-() const {
        FPS res = *this;
        for (auto& x : res) x = -x;
        return res;
    }
    FPS& operator+=(const FPS& x) {
        if (size() < x.size()) resize(x.size());
        for (int i = 0; i < (int)x.size(); i++) (*this)[i] += x[i];
        return *this;
    }
    FPS& operator-=(const FPS& x) {
        if (size() < x.size()) resize(x.size());
        for (int i = 0; i < (int)x.size(); i++) (*this)[i] -= x[i];
        return *this;
    }
    FPS& operator*=(const FPS& x) {
        *this = convolution(*this, x);
        return *this;
    }
    FPS& operator*=(const mint& c) {
        for (auto& y : *this) y *= c;
        return *this;
    }
    FPS& operator/=(const mint& c) {
        mint invc = c.inv();
        for (auto& y : *this) y *= invc;
        return *this;
    }
    FPS operator+(const FPS& x) const { return FPS(*this) += x; }
    FPS operator-(const FPS& x) const { return FPS(*this) -= x; }
    FPS operator*(const FPS& x) const { return FPS(*this) *= x; }
    FPS operator*(const mint& x) const { return FPS(*this) *= x; }
    FPS operator/(const mint& x) const { return FPS(*this) /= x; }
    FPS diff() const {
        if (empty()) return {};
        FPS g(size() - 1);
        for (int i = 1; i < (int)size(); i++) g[i - 1] = (*this)[i] * mint(i);
        return g;
    }
    FPS integ() const {
        FPS g(size() + 1);
        static vector<mint> invs = {0, 1};
        int n = g.size();
        for (int i = invs.size(); i < n; i++)
            invs.push_back(-invs[FPS_MOD % i] * mint(FPS_MOD / i));
        for (int i = 0; i < (int)size(); i++)
            g[i + 1] = (*this)[i] * invs[i + 1];
        return g;
    }
    FPS inv(int deg = -1) const {
        assert(!this->empty() && (*this)[0] != 0);
        int n = this->size();
        if (deg == -1) deg = n;
        FPS res({(*this)[0].inv()});
        int m = 1;
        while (m < deg) {
            m <<= 1;
            FPS f_low = this->low(2 * m);
            FPS t = FPS(convolution(convolution(res, res), f_low)).low(2 * m);
            res.resize(2 * m);
            for (int i = 0; i < 2 * m; i++) {
                t[i] = (i < (int)t.size() ? t[i] : 0);
                res[i] = res[i] * 2 - t[i];
            }
            res = res.low(2 * m);
        }
        res.resize(deg);
        return res;
    }
    pair<FPS, FPS> divmod(const FPS& g) const {
        FPS f = *this;
        if (f.size() < g.size()) return {FPS{0}, f};
        int n = f.size(), m = g.size();
        FPS rf = f, rg = g;
        reverse(rf.begin(), rf.end());
        reverse(rg.begin(), rg.end());
        FPS q = (rf * rg.inv(n - m + 1)).low(n - m + 1);
        reverse(q.begin(), q.end());
        FPS r = f - g * q;
        r.resize(m - 1);
        return {q, r};
    }
};
