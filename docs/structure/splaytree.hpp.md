---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-predecessor_problem.test.cpp
    title: verify/yosupo-predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/splaytree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class T>\nstruct splaytree {\n    struct Node {\n\
    \        T v;\n        Node* p = nullptr;\n        Node* l = nullptr;\n      \
    \  Node* r = nullptr;\n    };\n    Node* root = nullptr;\n    int sz = 0;\n  \
    \  Node* rotateright(Node* x) {\n        Node* y = x->l;\n        x->l = y->r;\n\
    \        if (y->r) y->r->p = x;\n        y->r = x;\n        y->p = x->p;\n   \
    \     if (x->p) {\n            if (x->p->l == x) x->p->l = y;\n            else\
    \ x->p->r = y;\n        }\n        x->p = y;\n        if (root == x) root = y;\n\
    \        return y;\n    }\n    Node* rotateleft(Node* x) {\n        Node* y =\
    \ x->r;\n        x->r = y->l;\n        if (y->l) y->l->p = x;\n        y->l =\
    \ x;\n        y->p = x->p;\n        if (x->p) {\n            if (x->p->l == x)\
    \ x->p->l = y;\n            else x->p->r = y;\n        }\n        x->p = y;\n\
    \        if (root == x) root = y;\n        return y;\n    }\n    Node* splay(Node*\
    \ x, T v) {\n        if (!x) return x;\n        Node* cur = x;\n        while\
    \ (cur && cur->v != v) {\n            if (v < cur->v) cur = cur->l;\n        \
    \    else cur = cur->r;\n        }\n        if (!cur) return x;\n        while\
    \ (cur->p) {\n            Node* p = cur->p;\n            Node* g = p->p;\n   \
    \         if (!g) { // zig\n                if (p->l == cur) rotateright(p);\n\
    \                else rotateleft(p);\n            } else if (g->l == p && p->l\
    \ == cur) { // left zig zig\n                rotateright(g);\n               \
    \ rotateright(p);\n            } else if (g->r == p && p->r == cur) { // right\
    \ zig zig\n                rotateleft(g);\n                rotateleft(p);\n  \
    \          } else if (g->l == p && p->r == cur) { // left zig zag\n          \
    \      rotateleft(p);\n                rotateright(g);\n            } else { //\
    \ right zig zag\n                rotateright(p);\n                rotateleft(g);\n\
    \            }\n        }\n        return cur;\n    }\n    Node* find(T x) {\n\
    \        root = splay(root, x);\n        if (root && root->v == x) return root;\n\
    \        return nullptr;\n    }\n    bool contains(T x) {\n        root = splay(root,\
    \ x);\n        return root != nullptr && root->v == x;\n    }\n    Node* innerinsert(Node*\
    \ x, T v) {\n        if (!x) {\n            Node* y = new Node;\n            y->v\
    \ = v;\n            return y;\n        }\n        if (v < x->v) {\n          \
    \  x->l = innerinsert(x->l, v);\n            x->l->p = x;\n        } else if (x->v\
    \ < v) {\n            x->r = innerinsert(x->r, v);\n            x->r->p = x;\n\
    \        }\n        return x;\n    }\n    void insert(T x) {\n        if (find(x))\
    \ return;\n        root = innerinsert(root, x);\n        root = splay(root, x);\n\
    \        sz++;\n    }\n    Node* innererase(Node* x, T v) {\n        x = splay(x,\
    \ v);\n        if (!x || x->v != v) return x;\n        if (!x->l) {\n        \
    \    Node* r = x->r;\n            if (r) r->p = nullptr;\n            delete x;\n\
    \            return r;\n        } else {\n            Node* L = x->l;\n      \
    \      L->p = nullptr;\n            Node* m = L;\n            while (m->r) m =\
    \ m->r;\n            L = splay(L, m->v);\n            L->r = x->r;\n         \
    \   if (L->r) L->r->p = L;\n            delete x;\n            return L;\n   \
    \     }\n    }\n    void erase(T x) {\n        if (!find(x)) return;\n       \
    \ root = innererase(root, x);\n        sz--;\n    }\n    int size() {\n      \
    \  return sz;\n    }\n    Node* lower_bound(T x) {\n        Node* c = root;\n\
    \        Node* ans = nullptr;\n        Node* b = nullptr;\n        while (c) {\n\
    \            b = c;\n            if (x <= c->v) {\n                ans = c;\n\
    \                c = c->l;\n            } else {\n                c = c->r;\n\
    \            }\n        }\n        if (ans) {\n            root = splay(root,\
    \ ans->v);\n            return root;\n        } else {\n            if (b) root\
    \ = splay(root, b->v);\n            return nullptr;\n        }\n    }\n    Node*\
    \ upper_bound(T x) {\n        Node* c = root;\n        Node* ans = nullptr;\n\
    \        Node* b = nullptr;\n        while (c) {\n            b = c;\n       \
    \     if (x < c->v) {\n                ans = c;\n                c = c->l;\n \
    \           } else {\n                c = c->r;\n            }\n        }\n  \
    \      if (ans) {\n            root = splay(root, ans->v);\n            return\
    \ root;\n        } else {\n            if (b) root = splay(root, b->v);\n    \
    \        return nullptr;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct splaytree {\n    struct Node {\n        T v;\n        Node* p = nullptr;\n\
    \        Node* l = nullptr;\n        Node* r = nullptr;\n    };\n    Node* root\
    \ = nullptr;\n    int sz = 0;\n    Node* rotateright(Node* x) {\n        Node*\
    \ y = x->l;\n        x->l = y->r;\n        if (y->r) y->r->p = x;\n        y->r\
    \ = x;\n        y->p = x->p;\n        if (x->p) {\n            if (x->p->l ==\
    \ x) x->p->l = y;\n            else x->p->r = y;\n        }\n        x->p = y;\n\
    \        if (root == x) root = y;\n        return y;\n    }\n    Node* rotateleft(Node*\
    \ x) {\n        Node* y = x->r;\n        x->r = y->l;\n        if (y->l) y->l->p\
    \ = x;\n        y->l = x;\n        y->p = x->p;\n        if (x->p) {\n       \
    \     if (x->p->l == x) x->p->l = y;\n            else x->p->r = y;\n        }\n\
    \        x->p = y;\n        if (root == x) root = y;\n        return y;\n    }\n\
    \    Node* splay(Node* x, T v) {\n        if (!x) return x;\n        Node* cur\
    \ = x;\n        while (cur && cur->v != v) {\n            if (v < cur->v) cur\
    \ = cur->l;\n            else cur = cur->r;\n        }\n        if (!cur) return\
    \ x;\n        while (cur->p) {\n            Node* p = cur->p;\n            Node*\
    \ g = p->p;\n            if (!g) { // zig\n                if (p->l == cur) rotateright(p);\n\
    \                else rotateleft(p);\n            } else if (g->l == p && p->l\
    \ == cur) { // left zig zig\n                rotateright(g);\n               \
    \ rotateright(p);\n            } else if (g->r == p && p->r == cur) { // right\
    \ zig zig\n                rotateleft(g);\n                rotateleft(p);\n  \
    \          } else if (g->l == p && p->r == cur) { // left zig zag\n          \
    \      rotateleft(p);\n                rotateright(g);\n            } else { //\
    \ right zig zag\n                rotateright(p);\n                rotateleft(g);\n\
    \            }\n        }\n        return cur;\n    }\n    Node* find(T x) {\n\
    \        root = splay(root, x);\n        if (root && root->v == x) return root;\n\
    \        return nullptr;\n    }\n    bool contains(T x) {\n        root = splay(root,\
    \ x);\n        return root != nullptr && root->v == x;\n    }\n    Node* innerinsert(Node*\
    \ x, T v) {\n        if (!x) {\n            Node* y = new Node;\n            y->v\
    \ = v;\n            return y;\n        }\n        if (v < x->v) {\n          \
    \  x->l = innerinsert(x->l, v);\n            x->l->p = x;\n        } else if (x->v\
    \ < v) {\n            x->r = innerinsert(x->r, v);\n            x->r->p = x;\n\
    \        }\n        return x;\n    }\n    void insert(T x) {\n        if (find(x))\
    \ return;\n        root = innerinsert(root, x);\n        root = splay(root, x);\n\
    \        sz++;\n    }\n    Node* innererase(Node* x, T v) {\n        x = splay(x,\
    \ v);\n        if (!x || x->v != v) return x;\n        if (!x->l) {\n        \
    \    Node* r = x->r;\n            if (r) r->p = nullptr;\n            delete x;\n\
    \            return r;\n        } else {\n            Node* L = x->l;\n      \
    \      L->p = nullptr;\n            Node* m = L;\n            while (m->r) m =\
    \ m->r;\n            L = splay(L, m->v);\n            L->r = x->r;\n         \
    \   if (L->r) L->r->p = L;\n            delete x;\n            return L;\n   \
    \     }\n    }\n    void erase(T x) {\n        if (!find(x)) return;\n       \
    \ root = innererase(root, x);\n        sz--;\n    }\n    int size() {\n      \
    \  return sz;\n    }\n    Node* lower_bound(T x) {\n        Node* c = root;\n\
    \        Node* ans = nullptr;\n        Node* b = nullptr;\n        while (c) {\n\
    \            b = c;\n            if (x <= c->v) {\n                ans = c;\n\
    \                c = c->l;\n            } else {\n                c = c->r;\n\
    \            }\n        }\n        if (ans) {\n            root = splay(root,\
    \ ans->v);\n            return root;\n        } else {\n            if (b) root\
    \ = splay(root, b->v);\n            return nullptr;\n        }\n    }\n    Node*\
    \ upper_bound(T x) {\n        Node* c = root;\n        Node* ans = nullptr;\n\
    \        Node* b = nullptr;\n        while (c) {\n            b = c;\n       \
    \     if (x < c->v) {\n                ans = c;\n                c = c->l;\n \
    \           } else {\n                c = c->r;\n            }\n        }\n  \
    \      if (ans) {\n            root = splay(root, ans->v);\n            return\
    \ root;\n        } else {\n            if (b) root = splay(root, b->v);\n    \
    \        return nullptr;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/splaytree.hpp
  requiredBy: []
  timestamp: '2025-11-26 14:53:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-predecessor_problem.test.cpp
documentation_of: structure/splaytree.hpp
layout: document
redirect_from:
- /library/structure/splaytree.hpp
- /library/structure/splaytree.hpp.html
title: structure/splaytree.hpp
---
