#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct splaytree {
    struct Node {
        T v;
        Node* p = nullptr;
        Node* l = nullptr;
        Node* r = nullptr;
    };
    Node* root = nullptr;
    int sz = 0;
    Node* rotateright(Node* x) {
        Node* y = x->l;
        x->l = y->r;
        if (y->r) y->r->p = x;
        y->r = x;
        y->p = x->p;
        if (x->p) {
            if (x->p->l == x) x->p->l = y;
            else x->p->r = y;
        }
        x->p = y;
        if (root == x) root = y;
        return y;
    }
    Node* rotateleft(Node* x) {
        Node* y = x->r;
        x->r = y->l;
        if (y->l) y->l->p = x;
        y->l = x;
        y->p = x->p;
        if (x->p) {
            if (x->p->l == x) x->p->l = y;
            else x->p->r = y;
        }
        x->p = y;
        if (root == x) root = y;
        return y;
    }
    Node* splay(Node* x, T v) {
        if (!x) return x;
        Node* cur = x;
        while (cur && cur->v != v) {
            if (v < cur->v) cur = cur->l;
            else cur = cur->r;
        }
        if (!cur) return x;
        while (cur->p) {
            Node* p = cur->p;
            Node* g = p->p;
            if (!g) { // zig
                if (p->l == cur) rotateright(p);
                else rotateleft(p);
            } else if (g->l == p && p->l == cur) { // left zig zig
                rotateright(g);
                rotateright(p);
            } else if (g->r == p && p->r == cur) { // right zig zig
                rotateleft(g);
                rotateleft(p);
            } else if (g->l == p && p->r == cur) { // left zig zag
                rotateleft(p);
                rotateright(g);
            } else { // right zig zag
                rotateright(p);
                rotateleft(g);
            }
        }
        return cur;
    }
    Node* find(T x) {
        root = splay(root, x);
        if (root && root->v == x) return root;
        return nullptr;
    }
    bool contains(T x) {
        root = splay(root, x);
        return root != nullptr && root.v == x;
    }
    Node* innerinsert(Node* x, T v) {
        if (!x) {
            Node* y = new Node;
            y->v = v;
            return y;
        }
        if (v < x->v) {
            x->l = innerinsert(x->l, v);
            x->l->p = x;
        } else if (x->v < v) {
            x->r = innerinsert(x->r, v);
            x->r->p = x;
        }
        return x;
    }
    void insert(T x) {
        if (find(x)) return;
        root = innerinsert(root, x);
        root = splay(root, x);
        sz++;
    }
    Node* innererase(Node* x, T v) {
        x = splay(x, v);
        if (!x || x->v != v) return x;
        if (!x->l) {
            Node* r = x->r;
            if (r) r->p = nullptr;
            delete x;
            return r;
        } else {
            Node* L = x->l;
            L->p = nullptr;
            Node* m = L;
            while (m->r) m = m->r;
            L = splay(L, m->v);
            L->r = x->r;
            if (L->r) L->r->p = L;
            delete x;
            return L;
        }
    }
    void erase(T x) {
        if (!find(x)) return;
        root = innererase(root, x);
        sz--;
    }
    int size() {
        return sz;
    }
    Node* lower_bound(T x) {
        Node* c = root;
        Node* ans = nullptr;
        Node* b = nullptr;
        while (c) {
            b = c;
            if (x <= c.v) {
                ans = c;
                c = c.l;
            } else {
                c = c.r;
            }
        }
        if (ans) {
            root = splay(root, ans-v);
            return root;
        } else {
            if (b) root = splay(root, b->v);
            return nullptr;
        }
    }
    Node* upper_bound(T x) {
        Node* c = root;
        Node* ans = nullptr;
        Node* b = nullptr;
        while (c) {
            b = c;
            if (x < c.v) {
                ans = c;
                c = c.l;
            } else {
                c = c.r;
            }
        }
        if (ans) {
            root = splay(root, ans-v);
            return root;
        } else {
            if (b) root = splay(root, b->v);
            return nullptr;
        }
    }
};
