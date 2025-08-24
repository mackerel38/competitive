#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T = char>
struct rollinghash {
    static long long generate_base() noexcept {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<uint64_t> rand(1, 2305843009213693950);
        return rand(mt);
    }
    static long long base, invbase;
    static vector<long long> bases, invbases;
    vector<T> pre, suf;
    vector<long long> prenum(1), sufnum(1);
    static void buildbases(int n) noexcept {
        if ((int)bases.size() < n+1) {
            int presize = (int)bases.size()
            bases.resize(n+1);
            for (int i=presize-1; i<n; i++) {
                bases[i+1] = bases[i] * base[i] % 2305843009213693951;
            }
        }
    }
    static void buildinvbases(int n) noexcept {
        if ((int)invbases.size() < n+1) {
            int presize = (int)invbases.size();
            invbases.resize(n+1);
            for (int i=presize-1; i<n; i++) {
                invbases[i+1] = invbases[i] * invbase % 2305843009213693951;
            }
        }
    }
    rollinghash() = default;
    explicit rollinghash(const string& s) noexcept {
        ;
    }
};