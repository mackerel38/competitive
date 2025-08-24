#pragma once
#include "graphtemplate"
#include<bits/stdc++.h>
using namespace std;

template <class T>
pair<graph<int, true, false>, int> cartesiantree(vector<T> & a) {
    graph<int, true, false> g(n);
    vector<int> p(a.size(), -1);
    stack<int> s;
    for (int i=0; i<(int)a.size(); i++) {
        int pre = -1;
        while (!s.empty() && a[i] < a[s.back()]) {
            pre = s.top(); s.pop();
        }
        if (pre != -1) p[pre] = i;
        if (!s.empty()) p[i] = s.top();
        s.push(i);
    }
    int r = -1;
    for (int i=0; i<(int)a.size(); i++) {
        if (p[i] != -1) {
            g.add_edge(p[i], i);
        } else {
            r = i;
        }
    }
    return {g, r};
}