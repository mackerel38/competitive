#pragma once
#include<bits/stdc++.h>
using namespace std;

template <class T = int, bool directed = false, bool weighted = false>
vector<int> dfs_order(graph<T, weighted, directed>& g, int s = 0) {
    vector<int> re(g.size(), -1);
    stack<int> q; q.push(s);
    int cnt = 0; re[s] = cnt++;
    while (!q.empty()) {
        int x = q.top(); q.pop();
        for (auto e : g[x]) {
            if (re[e.to] == -1) {
                re[e.to] = cnt++;
                q.push(e.to);
            }
        }
    }
    return re;
}

template <class T = int, bool directed = false, bool weighted = false>
vector<int> bfs_order(graph<T, weighted, directed>& g, int s = 0) {
    vector<int> re(g.size(), -1);
    queue<int> q; q.push(s);
    int cnt = 0; re[s] = cnt++;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto e : g[x]) {
            if (re[e.to] == -1) {
                re[e.to] = cnt++;
                q.push(e.to);
            }
        }
    }
    return re;
}

template <class T = int, bool directed = false, bool weighted = false>
vector<int> distance(graph<T, weighted, directed>& g, int s = 0) {
    vector<int> re(g.size(), -1);
    queue<int> q; q.push(s);
    re[s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto e : g[x]) {
            if (re[e.to] == -1) {
                re[e.to] = re[x] + 1;
                q.push(e.to);
            }
        }
    }
    return re;
}

template <class T = int, bool directed = false, bool weighted = false>
pair<int, pair<int, int>> diameter(graph<T, weighted, directed>& g) {
    vector<int> d1 = distance(g, 0);
    int s = max_element(d1.begin(), d1.end()) - d1.begin();
    vector<int> d2 = distance(g, s);
    int t = max_element(d2.begin(), d2.end()) - d2.begin();
    return {d2[t], {s, t}};
}
