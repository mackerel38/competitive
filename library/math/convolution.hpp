#pragma once
#include "NTT"
#include <bits/stdc++.h>
using namespace std;

template<long long convolution_MOD>
vector<modint<convolution_MOD>> convolution(vector<modint<convolution_MOD>> a,vector<modint<convolution_MOD>> b){
    int n = 1;
    int s = (int)(a.size()+b.size()-1);
    while (n < s) n<<=1;
    a.resize(n);
    b.resize(n);
    NTT(a);
    NTT(b);
    for (int i=0; i<n; i++) a[i] *= b[i];
    NTT(a,true);
    a.resize(s);
    return a;
}