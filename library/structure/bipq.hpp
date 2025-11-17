#pragma once
#include "erasablepq"
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct bipq {
    erasablepq<T> q;
    erasablepqg<T> qg;
    void push(const T& x) { q.push(x); qg.push(x); }
    void erase(const T& x) { q.erase(x); qg.erase(x); }
    void pop_max() {
        qg.erase(q.top());
        q.pop();
    }
    void pop_min() {
        q.erase(qg.top());
        qg.pop();
    }
    T top_max() { return q.top(); }
    T top_min() { return qg.top(); }
    int size() { return q.size(); }
    bool empty() { return q.empty(); }
};
