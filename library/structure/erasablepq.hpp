#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct erasablepq {
    priority_queue<T> pq, del;
    void push(const T& x) {
        pq.push(x);
        normalize();
    }
    void erase(const T& x) {
        del.push(x);
        normalize();
    }
    void pop() {
        normalize();
        pq.pop();
    }
    T top() {
        normalize();
        return pq.top();
    }
    bool empty() {
        normalize();
        return pq.empty();
    }
    int size() {
        return pq.size() - del.size();
    }
    void normalize() {
        while (!del.empty() && !pq.empty() && pq.top() == del.top()) {
            pq.pop();
            del.pop();
        }
    }
};

template <class T>
struct erasablepqg {
    priority_queue<T, vector<T>, greater<T>> pq, del;
    void push(const T& x) {
        pq.push(x);
        normalize();
    }
    void erase(const T& x) {
        del.push(x);
        normalize();
    }
    void pop() {
        normalize();
        pq.pop();
    }
    T top() {
        normalize();
        return pq.top();
    }
    bool empty() {
        normalize();
        return pq.empty();
    }
    int size() {
        return pq.size() - del.size();
    }
    void normalize() {
        while (!del.empty() && !pq.empty() && pq.top() == del.top()) {
            pq.pop();
            del.pop();
        }
    }
};
