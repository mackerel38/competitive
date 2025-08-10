#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class T>
void FWT(vector<T>& a, bool invert = false) {
    for (int i=1; i<(int)a.size(); i<<=1) {
        for (int j=0; j<(int)a.size(); j++) {
            if ((i & j) == 0) {
                T x = a[j], y = a[i+j];
                a[j] = x + y;
                a[i+j] = x - y;
            }
        }
    }
    if (invert) {
        for (int i=0; i<(int)a.size(); i++) {
            a[i] /= (int)a.size();
        }
    }
}