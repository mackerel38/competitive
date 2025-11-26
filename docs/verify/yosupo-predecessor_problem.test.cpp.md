---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/splaytree.hpp
    title: structure/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/yosupo-predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\n#line 2 \"util/template.hpp\"\
    \n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n#else\n#define debug(x)\n\
    #endif\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\nusing\
    \ ull=unsigned long long;\nusing ld=long double;\nusing pi=pair<int,int>;\nusing\
    \ pll=pair<ll,ll>;\nusing str=string;\ntemplate<class T>using vec=vector<T>;\n\
    using vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using\
    \ vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using vvvll=vec<vvll>;using\
    \ vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using vvpi=vec<vpi>;using\
    \ vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\nusing vpll=vec<pll>;using\
    \ vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;\n\
    template<class T>using pq=priority_queue<T,vector<T>>;\ntemplate<class T>using\
    \ pqg=priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define loop(i, l, r) for (int\
    \ i=(int)(l); i<(int)(r); i++)\n#define per(i,n) for(int i=(int)(n)-1;0<=i;i--)\n\
    #define per1(i,n) for(int i=(int)(n);0<i;i--)\n#define range(i,x) for(auto&i:x)\n\
    #define range2(i,j,x) for(auto&[i,j]:x)\n#define all(x) (x).begin(),(x).end()\n\
    #define rall(x) (x).rbegin(),(x).rend()\n#define Sort(x) sort((x).begin(),(x).end())\n\
    #define troS(x) sort((x).rbegin(),(x).rend())\n#define Reverse(x) reverse((x).begin(),(x).end())\n\
    #define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())\n\
    #define nextp(x) next_permutation((x).begin(),(x).end())\n#define nextc(x,k) next_combination((x).begin(),(x).end(),k)\n\
    #define bit(x,i) (((x)>>(i))&1)\n#define pf push_front\n#define pb push_back\n\
    #define df pop_front\n#define db pop_back\n#define fi first\n#define se second\n\
    #define elif else if\n#define Yes cout<<\"Yes\"<<'\\n'\n#define No cout<<\"No\"\
    <<'\\n'\n#define YN(x) cout<<((x)?\"Yes\":\"No\")<<'\\n'\n#define O(x) cout<<(x)<<'\\\
    n'\n#define ismid(a,b,c) ((a)<=(b)&&(b)<(c))\ntemplate<class S,class T>bool chmin(S&a,T\
    \ b){if(a>b){a=b;return true;}return false;}\ntemplate<class S,class T>bool chmax(S&a,T\
    \ b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool next_combination(T\
    \ l,T r,int k){T m=l+k;if(l==r||l==m||r==m)return false;T t=m;while(l!=t){t--;if(*t<*(r-1)){T\
    \ d=m;while(*t>=*d)d++;iter_swap(t,d);rotate(t+1,d+1,r);rotate(m,m+(r-d)-1,r);return\
    \ true;}}rotate(l,m,r);return false;}\ntemplate<class T>T Min(T a,T b){return\
    \ a<b?a:b;}\ntemplate<class T,class...Args>T Min(T a,T b,Args...args){return Min(Min(a,b),args...);}\n\
    template<class T>T Max(T a,T b){return a>b?a:b;}\ntemplate<class T,class...Args>T\
    \ Max(T a,T b,Args...args){return Max(Max(a,b),args...);}\ntemplate<class T>T\
    \ Sum(T a){return a;}\ntemplate<class T,class... Args>T Sum(T a,Args... args){return\
    \ a+Sum(args...);}\ntemplate<class T>T Max(const vector<T>&v){return *max_element(all(v));}\n\
    template<class T>T Min(const vector<T>&v){return *min_element(all(v));}\ntemplate<class\
    \ T>T Sum(const vector<T>&v){return accumulate(all(v),T(0));}\ntemplate<class\
    \ S,class T>T Max(const pair<S,T>&p){return max(p.first,p.second);}\ntemplate<class\
    \ S,class T>T Min(const pair<S,T>&p){return min(p.first,p.second);}\ntemplate<class\
    \ S,class T>T Sum(const pair<S,T>&p){return p.first+p.second;}\ntemplate<class\
    \ S,class T>istream&operator>>(istream&s,pair<S,T>&p){s>>p.first>>p.second;return\
    \ s;}\ntemplate<class S,class T>ostream&operator<<(ostream&s,pair<S,T>&p){s<<p.first<<'\
    \ '<<p.second<<'\\n';return s;}\ntemplate<class T>istream&operator>>(istream&s,vector<T>&v){for(auto&i:v)s>>i;return\
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++)s<<v[i]<<\"\
    \ \\n\"[i==(int)v.size()-1];return s;}\nconst int dxy[5]={0,1,0,-1,0};\nconst\
    \ int dx[8]={0,1,0,-1,1,1,-1,-1};\nconst int dy[8]={1,0,-1,0,1,-1,1,-1};\n#define\
    \ nl '\\n'\n#define sp ' '\nconst int inf = (1<<30)-(1<<15);\nconst ll INF = 1LL<<61;\n\
    const ll mod = 998244353;\nconst ll MOD = 1000000007;\nconst ld EPS = 1e-9;\n\
    const ld PI = acos(-1);\n\nvoid IO() {\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n}\n\nvoid solve();\n\
    // poe\n#line 3 \"structure/splaytree.hpp\"\nusing namespace std;\n\ntemplate<class\
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
    \        return nullptr;\n        }\n    }\n};\n#line 5 \"verify/yosupo-predecessor_problem.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    str\
    \ s; cin >> s;\r\n    splaytree<int> t, T;\r\n    rep(i, n) if (s[i] == '1') {\
    \ t.insert(i); T.insert(-i); }\r\n    while (q--) {\r\n        int x, y; cin >>\
    \ x >> y;\r\n        if (x == 0) { t.insert(y); T.insert(-y); }\r\n        elif\
    \ (x == 1) { t.erase(y); T.erase(-y); }\r\n        elif (x == 2) { cout << t.contains(y)\
    \ << nl;}\r\n        elif (x == 3) {\r\n            auto z = t.lower_bound(y);\r\
    \n            cout << (z==nullptr ? -1 : z->v) << nl;\r\n        } else {\r\n\
    \            auto z = T.lower_bound(-y);\r\n            cout << (z==nullptr ?\
    \ -1 : -(z->v)) << nl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include \"template\"\r\n#include \"splaytree\"\r\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    str s; cin >> s;\r\n    splaytree<int>\
    \ t, T;\r\n    rep(i, n) if (s[i] == '1') { t.insert(i); T.insert(-i); }\r\n \
    \   while (q--) {\r\n        int x, y; cin >> x >> y;\r\n        if (x == 0) {\
    \ t.insert(y); T.insert(-y); }\r\n        elif (x == 1) { t.erase(y); T.erase(-y);\
    \ }\r\n        elif (x == 2) { cout << t.contains(y) << nl;}\r\n        elif (x\
    \ == 3) {\r\n            auto z = t.lower_bound(y);\r\n            cout << (z==nullptr\
    \ ? -1 : z->v) << nl;\r\n        } else {\r\n            auto z = T.lower_bound(-y);\r\
    \n            cout << (z==nullptr ? -1 : -(z->v)) << nl;\r\n        }\r\n    }\r\
    \n}"
  dependsOn:
  - util/template.hpp
  - structure/splaytree.hpp
  isVerificationFile: true
  path: verify/yosupo-predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-11-26 23:28:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-predecessor_problem.test.cpp
- /verify/verify/yosupo-predecessor_problem.test.cpp.html
title: verify/yosupo-predecessor_problem.test.cpp
---
