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
        pq.pop();
        normalize();
    }
    T top() {
        return pq.top();
        normalize();
    }
    bool empty() {
        return pq.empty();
        normalize();
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
        pq.pop();
        normalize();
    }
    T top() {
        return pq.top();
        normalize();
    }
    bool empty() {
        return pq.empty();
        normalize();
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
