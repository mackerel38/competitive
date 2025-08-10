#pragma once
#include <bits/stdc++.h>
using namespace std;

unsigned long long inthashrand = 0;

unsigned long long inthash(unsigned long long x) {
    if (inthashrand == 0) inthashrand = chrono::steady_clock::now().time_since_epoch().count();
    x += inthashrand;
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

// https://github.com/drken1215/algorithm/blob/master/DataStructure/zobrist_hash.cpp
