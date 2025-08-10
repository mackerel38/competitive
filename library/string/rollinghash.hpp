#pragma once
#include "modint230"
#include <bits/stdc++.h>
using namespace std;
template <typename T = char>
struct RollingHash {
    mint230 generate_base() {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<uint64_t> rand(1, mint230::mod() - 1);
        return mint230(rand(mt));
    }
    mint230 base, base_inv;
    vector<mint230> bases, base_invs;
    vector<T> pre, suf;
    vector<mint230> PRE{mint230(0)}, SUF{mint230(0)};
    void expand_bases(size_t n) {
        if (bases.size() < n+1) {
            int pre_sz = (int)bases.size();
            bases.resize(n + 1);
            for (int i=pre_sz-1; i<n; i++) {
                bases[i+1] = bases[i] * base;
            }
        }
    }
    void expand_base_invs(size_t n) {
        if (base_invs.size() < n+1) {
            int pre_sz = (int)base_invs.size();
            base_invs.resize(n+1);
            for (int i=pre_sz-1; i<n; i++) {
                base_invs[i+1] = base_invs[i] * base_inv;
            }
        }
    }
    RollingHash(const string& s) {
        for (auto& c : s) push_back(c);
    }
    RollingHash(const vector<T>& s) {
        for (auto& c : s) push_back(c);
    }
    int size() { return (int)pre.size() + (int)suf.size(); }
    void push_front(T c) {
        expand_base_invs(pre.size()+1);
        PRE.push_back(PRE.back() + base_invs[pre.size()+1] * mint230(c));
        pre.push_back(c);
    }
    void push_back(T c) {
        expand_bases(suf.size());
        SUF.push_back(SUF.back() + bases[suf.size()] * mint230(c));
        suf.push_back(c);
    }
    T operator[](int k) {
        assert(0<=k && k<size());
        k -= pre.size();
        return (k < 0 ? pre[~k] : suf[k]);
    }
    mint230 get(int r) {
        assert(0<=r && r<=size());
        r -= (int)pre.size();
        expand_bases(pre.size());
        if (r < 0) {
            return bases[pre.size()] * (PRE.back() - PRE[-r]);
        } else {
            return bases[pre.size()] * (PRE.back() + SUF[r]);
        }
    }
    mint230 get(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        expand_base_invs(l);
        return base_invs[l] * (get(r) - get(l));
    }
    int lcp(const RollingHash& b) {
        int len = min(size(), b.size());
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(mid) == b.get(mid)){
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
    int lcp(const RollingHash& b, int l1, int l2) {
        assert(l1 <= size());
        assert(l2 <= b.size());
        int len = min(size() - l1, b.size() - l2);
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
            low = mid;
        else
            high = mid;
        }
        return low;
    }
    mint230 combine(mint230 h1, int h1_len, mint230 h2) {
        expand_bases(h1_len);
        return h1 + h2 * bases[h1_len];
    }
    void clear() {
        pre.clear();
        pre.shrink_to_fit();
        suf.clear();
        suf.shrink_to_fit();
        PRE = {mint230(1)};
        PRE.shrink_to_fit();
        SUF = {mint230(1)};
        SUF.shrink_to_fit();
    }
    void merge(RollingHash& b) {
        if (size() < b.size()) {
            pre.swap(b.pre);
            suf.swap(b.suf);
            PRE.swap(b.PRE);
            SUF.swap(b.SUF);
            reverse(b.suf.begin(), b.suf.end());
            for (auto& c : b.suf) push_front(c);
            for (auto& c : b.pre) push_front(c);
        } else {
            reverse(b.pre.begin(), b.pre.end());
            for (auto& c : b.pre) push_back(c);
            for (auto& c : b.suf) push_back(c);
        }
        b.clear();
    }
};