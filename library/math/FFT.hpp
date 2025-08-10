#pragma once
#include <bits/stdc++.h>
using namespace std;
vector<complex<double>> FFT(vector<complex<double>> a, bool invert = false) {
    int n = a.size();
    if (n == 1) return a;
    vector<complex<double>> even(n/2), odd(n/2);
    for (int i=0; i<n/2; i++) {
        even[i] = a[i*2];
        odd[i] = a[i*2+1];
    }
    even = FFT(even, invert);
    odd = FFT(odd, invert);
    double angle = 2 * M_PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn = polar(1.0, angle);
    for (int i=0; i<n/2; i++) {
        complex<double> t = w * odd[i];
        a[i] = even[i] + t;
        a[i+n/2] = even[i] - t;
        w *= wn;
    }
    return a;
}