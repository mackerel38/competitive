#pragma once
#include <bits/stdc++.h>
using namespace std;

// floor(sqrt(n)) を返す
long long isqrt(long long n) {
    assert(0 <= n);
    long long re = sqrt(n);
    while ((re + 1) * (re + 1) <= n) re++;
    while (n < re * re) re--;
    return re;
}