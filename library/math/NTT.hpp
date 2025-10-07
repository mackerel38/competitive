#pragma once
#include "modint.hpp"
#include <bits/stdc++.h>
using namespace std;

template <long long NTT_MOD>
void NTT(vector<modint<NTT_MOD>>& a, bool inv=false) {
    int n = (int)a.size();
    for (int i=1, j=0; i<n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    modint<NTT_MOD> g = 3;
    for (int len=2; len<=n; len<<=1) {
        modint<NTT_MOD> wlen = g.pow((NTT_MOD - 1) / len);
        if (inv) wlen = wlen.inv();
        for (int i=0; i<n; i+=len) {
            modint<NTT_MOD> w = 1;
            for (int j=0; j<len/2; j++) {
                modint<NTT_MOD> u = a[i+j];
                modint<NTT_MOD> v = a[i+j+len/2]*w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        modint<NTT_MOD> inv_n = modint<NTT_MOD>(n).inv();
        for (auto& x : a) x *= inv_n;
    }
}
