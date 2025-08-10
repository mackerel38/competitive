#pragma once
#include "modint"
#include <bits/stdc++.h>
using namespace std;
void NTT(vector<mint>& a, bool invert=false) {
    int n = a.size();
    for (int i=1, j=0; i<n; i++) {
        int b;
        for (b=n>>1; j&b; b>>=1) j ^= b;
        j ^= b;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        mint wlen = mint(3).pow((998244353 - 1) / len);
        if (invert) wlen = wlen.inv();
        for (int i=0; i<n; i+=len) {
            mint w = 1;
            for (int j=0; j<len/2; j++) {
                mint u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        mint inv_n = mint(n).inv();
        for (auto& x : a) x *= inv_n;
    }
}