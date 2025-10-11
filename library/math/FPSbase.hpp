#pragma once
#include "convolution"
#include <bits/stdc++.h>
using namespace std;

template <long long FPS_MOD>
struct FPS : vector<modint<FPS_MOD>> {
    using mint = modint<FPS_MOD>;
    using vector<mint>::size;
    using vector<mint>::empty;
    using vector<mint>::resize;
    using vector<mint>::operator[];
    FPS() : vector<mint>() {}
    FPS(size_t n) : vector<mint>(n) {}
    FPS(size_t n, const mint& x) : vector<mint>(n, x) {}
    FPS(const initializer_list<mint>& il) : vector<mint>(il) {}
    template<class It>
    FPS(It first, It last) : vector<mint>(first, last) {}
    FPS(const vector<mint>& v) : vector<mint>(v) {}
    FPS(vector<mint>&& v) : vector<mint>(move(v)) {}
    static vector<mint> to_vec(const FPS& f) {
        return vector<mint>(f.begin(), f.end());
    }
    static FPS from_vec(const vector<mint>& v) { return FPS(v); }
    static FPS from_vec(vector<mint>&& v) { return FPS(move(v)); }
    FPS low(int n) const {
        int take = min(n, (int)this->size());
        return FPS(this->begin(), this->begin() + take);
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
        auto va = to_vec(*this);
        auto vb = to_vec(x);
        *this = from_vec(convolution(va, vb));
        return *this;
    }
    FPS operator*(const FPS& x) const { FPS t = *this; t *= x; return t; }
    FPS& operator*=(const mint& c) {
        for (auto& y : *this) y *= c;
        return *this;
    }
    FPS operator*(const mint& x) const { FPS t = *this; t *= x; return t; }
    FPS& operator/=(const mint& c) {
        mint invc = c.inv();
        for (auto& y : *this) y *= invc;
        return *this;
    }
    FPS operator/(const mint& x) const { FPS t = *this; t /= x; return t; }
    FPS operator+(const FPS& x) const { return FPS(*this) += x; }
    FPS operator-(const FPS& x) const { return FPS(*this) -= x; }
    FPS diff() const {
        if (empty()) return FPS();
        FPS g(size() - 1);
        for (int i = 1; i < (int)size(); i++) g[i - 1] = (*this)[i] * mint(i);
        return g;
    }
    FPS integ() const {
        FPS g(size() + 1);
        static vector<mint> invs = {mint(0), mint(1)};
        int n = g.size();
        for (int i = (int)invs.size(); i < n; ++i)
            invs.push_back(-invs[FPS_MOD % i] * mint(FPS_MOD / i));
        for (int i = 0; i < (int)size(); i++)
            g[i + 1] = (*this)[i] * invs[i + 1];
        return g;
    }
    FPS inv(int deg = -1) const {
        assert(!this->empty() && (*this)[0] != 0);
        int n = this->size();
        if (deg == -1) deg = n;
        FPS res; res.resize(1); res[0] = (*this)[0].inv();
        for (int m = 1; m < deg; m <<= 1) {
            int cut = 2 * m;
            FPS f_low = this->low(cut);
            auto vres = to_vec(res);
            auto vres2 = vres; // copy
            auto v_f_low = to_vec(f_low);
            auto t1 = convolution(vres, vres2);
            auto t2 = convolution(t1, v_f_low);
            FPS t = from_vec(move(t2));
            t.resize(cut);
            res.resize(cut);
            for (int i = 0; i < cut; ++i) {
                mint ti = (i < (int)t.size() ? t[i] : mint(0));
                res[i] = res[i] * mint(2) - ti;
            }
            res = res.low(cut);
        }
        res.resize(deg);
        return res;
    }
    pair<FPS, FPS> divmod(const FPS& g) const {
        FPS f = *this;
        if (f.size() < g.size()) return {FPS{mint(0)}, f};
        int n = f.size(), m = g.size();
        FPS rf = f, rg = g;
        reverse(rf.begin(), rf.end());
        reverse(rg.begin(), rg.end());
        auto vrf = to_vec(rf);
        auto vrg = to_vec(rg);
        FPS tmp = from_vec(convolution(vrf, to_vec(rg.inv(n - m + 1))));
        FPS q = tmp.low(n - m + 1);
        reverse(q.begin(), q.end());
        FPS r = f - g * q;
        r.resize(m - 1);
        return {q, r};
    }
    FPS log(int deg = -1) const {
        assert(!this->empty() && (*this)[0] == mint(1));
        int n = this->size();
        if (deg == -1) deg = n;
        FPS f = diff();
        FPS invf = this->inv(deg);
        auto vf = to_vec(f), vinvf = to_vec(invf);
        FPS g = from_vec(convolution(vf, vinvf)).low(deg - 1).integ();
        g.resize(deg);
        return g;
    }
    FPS exp(int deg = -1) const {
        assert(!this->empty() && (*this)[0] == mint(0));
        int n = this->size();
        if (deg == -1) deg = n;
        FPS g; g.resize(1); g[0] = mint(1);
        for (int m=1; m<deg; m<<=1) {
            int cut = 2 * m;
            FPS g_log = g.log(cut);
            FPS q = this->low(cut) - g_log;
            q[0] += mint(1);
            auto vg = to_vec(g), vq = to_vec(q);
            FPS ng = from_vec(convolution(vg, vq)).low(cut);
            g = move(ng);
        }
        g.resize(deg);
        return g;
    }
    FPS pow(long long k, int n=-1) const {
        int v = 0;
        while(v < (int)this->size() && (*this)[v].val == 0) v++;
        if (v == (int)this->size()) return FPS(n, mint(0));
        if (n == -1) n = this->size();
    }
};
