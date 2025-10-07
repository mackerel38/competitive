#pragma once
#include "modint"
#include <bits/stdc++.h>
using namespace std;

template <long long FPS_MOD>
struct FPS : vector<modint<FPS_MOD>> {
    template <class... Args> FPS(Args... args) : vector<modint<FPS_MOD>>(args...) {}
    FPS(initializer_list<modint<FPS_MOD>> v) : vector<modint<FPS_MOD>>(v.begin(), v.end()) {}
    FPS& low_(int n) { resize(n); return *this; }
    FPS low(int n) const { return FPS(*this).low_(n); }
    modint<FPS_MOD> operator[](int i) const { return i<(int)size() ? vector<modint<FPS_MOD>>::operator[](i) : 0; }
    modint<FPS_MOD>& operator[](int i) { if (i+1<n) resize(i+1); return vector<modint<FPS_MOD>>::operator[](i); }
    modint<FPS_MOD> operator()(modint<FPS_MOD> i) const {
        modint<FPS_MOD> re = 0;
        for (int i=(int)size()-1; 0<=i; i--) re = re*i + (*this)[i];
        return re;
    }
};
