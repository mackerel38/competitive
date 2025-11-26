---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/wordsizetree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nstruct wordsizetree {\n    int size;\n    vector<vector<unsigned\
    \ long long>> a;\n    static int highbit(unsigned long long x){\n        if(x\
    \ == 0) return 0;\n        return 63 - __builtin_clzll(x);\n    }\n    static\
    \ int lowbit(unsigned long long x){\n        if(x == 0) return 64;\n        return\
    \ __builtin_ctzll(x);\n    }\n    wordsizetree() = default;\n    wordsizetree(int\
    \ n){\n        size = n;\n        int t = n;\n        do {\n            vector<unsigned\
    \ long long> b(t/64+1);\n            a.emplace_back(move(b));\n            t /=\
    \ 64;\n        } while(t);\n    }\n    wordsizetree(vector<int> v) : wordsizetree(v.size())\
    \ {\n        for (int i=0; i<(int)v.size(); i++) {\n            if (v[i]) {\n\
    \                insert(i);\n            }\n        }\n    }\n    void insert(int\
    \ x){\n        for(auto& a : a){\n            a[x/64] |= 1ULL << (x % 64);\n \
    \           x /= 64;\n        }\n    }\n    void erase(int x){\n        for(auto&\
    \ a : a){\n        a[x/64] &= ~(1ULL << (x % 64));\n        if(a[x/64]) return;\n\
    \        x /= 64;\n        }\n    }\n    int count(int x) {\n        return (int)((a[0][x/64]\
    \ >> (x%64)) & 1);\n    }\n    // x<=y \u3068\u306A\u308B\u6700\u5C0F\u306Ey \u3092\
    \u8FD4\u3059\n    int minright(int x) {\n        if(x < 0) x = 0;\n        if(size\
    \ <= x) return size;\n        int d = 0, i = x;\n        while(true){\n      \
    \      if(d >= (int)a.size()) return size;\n            if(i/64 >= (int)a[d].size())\
    \ return size;\n            unsigned long long m = a[d][i/64] & ((~(unsigned long\
    \ long)0) << (i%64));\n            if(!m){d++; i/=64; i++;}\n            else{\n\
    \                int to = lowbit(m);\n                i = i/64*64 + to;\n    \
    \            if(d == 0) break;\n                i *= 64;\n                d--;\n\
    \            }\n        }\n        return i;\n    }\n    // x<=y \u3092\u6E80\u305F\
    \u3059\u6700\u5C0F\u306Ey \u3092\u8FD4\u3059\n    int maxleft(int x) {\n     \
    \   if(x < 0) return -1;\n        if(size <= x) x = size-1;\n        int d = 0,\
    \ i = x;\n        while(true){\n            if(i < 0) return -1;\n           \
    \ if(d >= (int)a.size()) return -1;\n            unsigned long long m = a[d][i/64]\
    \ & ~((~(unsigned long long)1) << (i%64));\n            if(!m){ d++; i /= 64;\
    \ i--; }\n            else{\n                int to = highbit(m);\n          \
    \      i = i/64*64 + to;\n                if(d == 0) break;\n                i\
    \ *= 64;\n                i += 64-1;\n                d--;\n            }\n  \
    \      }\n        return i;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nstruct wordsizetree {\n \
    \   int size;\n    vector<vector<unsigned long long>> a;\n    static int highbit(unsigned\
    \ long long x){\n        if(x == 0) return 0;\n        return 63 - __builtin_clzll(x);\n\
    \    }\n    static int lowbit(unsigned long long x){\n        if(x == 0) return\
    \ 64;\n        return __builtin_ctzll(x);\n    }\n    wordsizetree() = default;\n\
    \    wordsizetree(int n){\n        size = n;\n        int t = n;\n        do {\n\
    \            vector<unsigned long long> b(t/64+1);\n            a.emplace_back(move(b));\n\
    \            t /= 64;\n        } while(t);\n    }\n    wordsizetree(vector<int>\
    \ v) : wordsizetree(v.size()) {\n        for (int i=0; i<(int)v.size(); i++) {\n\
    \            if (v[i]) {\n                insert(i);\n            }\n        }\n\
    \    }\n    void insert(int x){\n        for(auto& a : a){\n            a[x/64]\
    \ |= 1ULL << (x % 64);\n            x /= 64;\n        }\n    }\n    void erase(int\
    \ x){\n        for(auto& a : a){\n        a[x/64] &= ~(1ULL << (x % 64));\n  \
    \      if(a[x/64]) return;\n        x /= 64;\n        }\n    }\n    int count(int\
    \ x) {\n        return (int)((a[0][x/64] >> (x%64)) & 1);\n    }\n    // x<=y\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306Ey \u3092\u8FD4\u3059\n    int minright(int\
    \ x) {\n        if(x < 0) x = 0;\n        if(size <= x) return size;\n       \
    \ int d = 0, i = x;\n        while(true){\n            if(d >= (int)a.size())\
    \ return size;\n            if(i/64 >= (int)a[d].size()) return size;\n      \
    \      unsigned long long m = a[d][i/64] & ((~(unsigned long long)0) << (i%64));\n\
    \            if(!m){d++; i/=64; i++;}\n            else{\n                int\
    \ to = lowbit(m);\n                i = i/64*64 + to;\n                if(d ==\
    \ 0) break;\n                i *= 64;\n                d--;\n            }\n \
    \       }\n        return i;\n    }\n    // x<=y \u3092\u6E80\u305F\u3059\u6700\
    \u5C0F\u306Ey \u3092\u8FD4\u3059\n    int maxleft(int x) {\n        if(x < 0)\
    \ return -1;\n        if(size <= x) x = size-1;\n        int d = 0, i = x;\n \
    \       while(true){\n            if(i < 0) return -1;\n            if(d >= (int)a.size())\
    \ return -1;\n            unsigned long long m = a[d][i/64] & ~((~(unsigned long\
    \ long)1) << (i%64));\n            if(!m){ d++; i /= 64; i--; }\n            else{\n\
    \                int to = highbit(m);\n                i = i/64*64 + to;\n   \
    \             if(d == 0) break;\n                i *= 64;\n                i +=\
    \ 64-1;\n                d--;\n            }\n        }\n        return i;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/wordsizetree.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/wordsizetree.hpp
layout: document
redirect_from:
- /library/structure/wordsizetree.hpp
- /library/structure/wordsizetree.hpp.html
title: structure/wordsizetree.hpp
---
