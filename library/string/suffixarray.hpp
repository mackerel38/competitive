#pragma once
#include <bits/stdc++.h>
using namespace std;

// suffix array をO(n (log n)^2) で構築する
vector<int> suffixarray(const string& s) {
    string t = s + '\0';
    vector<int> sa(t.size()), isa(t.size()), tmp(t.size());
    iota(sa.begin(), sa.end(), 0);
    for (int i=0; i<(int)t.size(); i++) isa[i] = t[i];
    for (int k=1; k<(int)t.size(); k<<=1) {
        auto cmp = [&](int a, int b) -> bool {
            if (isa[a] != isa[b]) return isa[a] < isa[b];
            int ra = (a+k<(int)t.size() ? isa[a + k] : -1);
            int rb = (b+k<(int)t.size() ? isa[b + k] : -1);
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i=1; i<(int)t.size(); i++) tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
        isa = tmp;
        if (isa[sa[t.size()-1]] == t.size()-1) break;
    }
    return sa;
}
