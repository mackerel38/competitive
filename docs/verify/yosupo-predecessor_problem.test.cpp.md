---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/wordsizetree.hpp
    title: structure/wordsizetree.hpp
  - icon: ':x:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/yosupo-predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n#line 1 \"structure/wordsizetree.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nstruct wordsizetree {\n    int\
    \ size;\n    vector<vector<unsigned long long>> a;\n    static int highbit(unsigned\
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
    \   }\n};\n#line 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\"\
    : \"<<x<<endl\n#else\n#define debug(x)\n#endif\n#line 8 \"util/template.hpp\"\n\
    using namespace std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing\
    \ ld=long double;\nusing pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\n\
    template<class T>using vec=vector<T>;\nusing vi=vec<int>;using vvi=vec<vi>;using\
    \ vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using\
    \ vvll=vec<vll>;using vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\n\
    using vpi=vec<pi>;using vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using\
    \ vvvvvpi=vec<vvvvpi>;\nusing vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using\
    \ vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;\ntemplate<class T>using pq=priority_queue<T,vector<T>>;\n\
    template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define loop(i, l, r) for (int i=(int)(l); i<(int)(r); i++)\n#define per(i,n)\
    \ for(int i=(int)(n)-1;0<=i;i--)\n#define per1(i,n) for(int i=(int)(n);0<i;i--)\n\
    #define range(i,x) for(auto&i:x)\n#define range2(i,j,x) for(auto&[i,j]:x)\n#define\
    \ all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n#define\
    \ Sort(x) sort((x).begin(),(x).end())\n#define troS(x) sort((x).rbegin(),(x).rend())\n\
    #define Reverse(x) reverse((x).begin(),(x).end())\n#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())\n\
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
    // poe\n#line 4 \"verify/yosupo-predecessor_problem.test.cpp\"\n\r\nint main()\
    \ { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n\
    }\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    vi a(n);\r\n  \
    \  str st; cin >> st;\r\n    rep(i, n) if (st[i] == '1') a[i] = 1;\r\n    wordsizetree\
    \ s(a);\r\n    while (q--) {\r\n        int x, y; cin >> x >> y;\r\n        if\
    \ (x == 0) {\r\n            s.insert(y);\r\n        } elif (x == 1) {\r\n    \
    \        s.erase(y);\r\n        } elif (x == 2) {\r\n            cout << s.count(y)\
    \ << nl;\r\n        } elif (x == 3) {\r\n            int z = s.minright(y);\r\n\
    \            cout << (z<n ? z : -1) << nl;\r\n        } else {\r\n           \
    \ int z = s.maxleft(y);\r\n            cout << (0<=z ? z : -1) << nl;\r\n    \
    \    }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n#include \"wordsizetree\"\r\n#include \"template\"\r\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    vi a(n);\r\n    str st; cin\
    \ >> st;\r\n    rep(i, n) if (st[i] == '1') a[i] = 1;\r\n    wordsizetree s(a);\r\
    \n    while (q--) {\r\n        int x, y; cin >> x >> y;\r\n        if (x == 0)\
    \ {\r\n            s.insert(y);\r\n        } elif (x == 1) {\r\n            s.erase(y);\r\
    \n        } elif (x == 2) {\r\n            cout << s.count(y) << nl;\r\n     \
    \   } elif (x == 3) {\r\n            int z = s.minright(y);\r\n            cout\
    \ << (z<n ? z : -1) << nl;\r\n        } else {\r\n            int z = s.maxleft(y);\r\
    \n            cout << (0<=z ? z : -1) << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - structure/wordsizetree.hpp
  - util/template.hpp
  isVerificationFile: true
  path: verify/yosupo-predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:24:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-predecessor_problem.test.cpp
- /verify/verify/yosupo-predecessor_problem.test.cpp.html
title: verify/yosupo-predecessor_problem.test.cpp
---
