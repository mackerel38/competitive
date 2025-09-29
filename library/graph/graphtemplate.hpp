#pragma once
#include<bits/stdc++.h>
using namespace std;
// 辺の構造体 edge(from, to, cost, id)
template<class T = int>
struct edge {
    int from, to;
    T cost;
    int id;
};
// 頂点の構造体 vector<edge<T>>
template<class T = int>
using edges = vector<edge<T>>;
// グラフの構造体 graph<T, directed, weighted> 
template <class T = int, bool directed = false, bool weighted = false>
struct graph {
    bool isdirected, isweighted;
    edges<T> _edges;
    vector<edges<T>> data;
    T sumcost;
    graph() = default;
    // 頂点数 n のグラフを作成する
    graph(int n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}
    // from から to へ辺を追加する
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        if (id == -1) id = _edges.size();
        data[from].push_back(edge<T>{from, to, cost, id});
        _edges.push_back(edge<T>{from, to, cost, id});
        if (!isdirected) {
            data[to].push_back(edge<T>{to, from, cost, id});
        }
        sumcost += cost;
    }
    // 辺を追加する
    void add_edge(edge<T> _e) {
        add_edge(_e.from, _e.to, _e.cost, _e.id);
    }
    // 標準入力から辺を読み込む
    void read(int m, int indexed = 1) {
        for (int i=0; i<m; i++) {
            int from, to;
            T cost = 1;
            cin >> from >> to;
            if (isweighted) cin >> cost;
            add_edge(from - indexed, to - indexed, cost);
        }
    }
    // 頂点数を返す
    int size() {
        return data.size();
    }
    // 頂点を返す
    edges<T> operator[](int k) {
        return data[k];
    }
    // パスを頂点に変換する
    vector<int> path_to_vertex(edges<T>& _e) {
        vector<int> re;
        if (_e.size() == 0) {
            return re;
        }
        if (_e.size() == 1) {
            re.push_back(_e[0].from);
            re.push_back(_e[0].to);
            return re;
        }
        int x=_e[0].from,y=_e[0].to;
        if (x==_e[1].to || x == _e[1].from) swap(x, y);
        re.push_back(x);
        for (int i=1; i<_e.size(); i++) {
            re.push_back(y);
            x = _e[i].to;
            if (x == y) x = _e[i].from;
            swap(x, y);
        }
        return re;
    }
    // 頂点をパスに変換する
    edges<T> vetex_to_path (vector<int>& v){
        edges<T> re;
        for (int i=0; i+1<v.size(); i++) {
            for (auto& _e : this[v[i]]) {
                if (_e.to == v[i+1]) {
                    re.push_back(_e);
                    break;
                }
            }
        }
        return re;
    }
};
