#pragma once
#include "FWT"
#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<T> xorconvolution(vector<T>& a, vector<T>& b) {
    int n=1;
    while (n < max((int)a.size(), (int)b.size())) n<<=1;
    vector<T> A(n), B(n);
    for (int i=0; i<(int)a.size(); i++) {
        A[i] = a[i];
    }
    for (int i=0; i<(int)b.size(); i++) {
        B[i] = b[i];
    }
    FWT(A, false);
    FWT(B, false);
    for (int i=0; i<n; i++) {
        A[i] *= B[i];
    }
    FWT(A, true);
    vector<T> re(max((int)a.size(), (int)b.size()));
    for (int i=0; i<max((int)a.size(), (int)b.size()); i++) {
        re[i] = A[i];
    }
    return re;
}