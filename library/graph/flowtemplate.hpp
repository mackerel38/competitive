#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct flowedge {
    int to;
    T cap;
    int rev;
};

template <class T>
using flowedges = vector<flowedge<T>>;

template <class T>
struct flowgraph {
    vector<flowedges<T>> data;
    flowgraph() = default;
    flowgraph(int n) : data(n) {}
    void add_edge(int from, int to, T cap = numeric_limits<T>::max()) {
        if (id == -1) id = _edges.size();
        data[from].push_back(flowedge<T>{to, cap, data[to].size()});
        data[to].push_back(flowedge<T>{from, T{}, data[from].size()-1});
    }
    int size() {
        return data.size();
    }
    flowedges<T> operator[](int k) {
        return data[k];
    }
};
