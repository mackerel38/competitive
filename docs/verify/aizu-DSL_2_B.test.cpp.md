---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/BIT.hpp
    title: structure/BIT.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"verify/aizu-DSL_2_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \r\n#line 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\":\
    \ \"<<x<<endl\n#else\n#define debug(x)\n#endif\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long\
    \ double;\nusing pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\n\
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
    // poe\n#line 3 \"structure/BIT.hpp\"\nusing namespace std;\ntemplate<class T>\n\
    struct BIT {\n    int _n;\n    vector<T> data;\n    BIT() = default;\n    // BIT\
    \ \u30920-indexed \u3067\u69CB\u7BC9\u3059\u308B O(n)\n    BIT(int n) : _n(n),\
    \ data(_n) {}\n    // p \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\
    \u308B O(log n)\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n\
    \        p++;\n        while (p <= _n) {\n            data[p-1] += x;\n      \
    \      p += p & -p;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\
    x \u306B\u3059\u308B O(log n)\n    void set(int p, T x) {\n        add(p, x -\
    \ get(p));\n    }\n    // [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log\
    \ n)\n    T sum(int r) {\n        assert(0 <= r &&  r <= _n);\n        T re =\
    \ T{};\n        while (0 < r) {\n            re += data[r-1];\n            r -=\
    \ r & -r;\n        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r) {\n        assert(l\
    \ <= r);\n        return sum(r) - sum(l);\n    }\n    // p \u756A\u76EE\u306E\u5024\
    \u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T get(int p) {\n        return sum(p+1)\
    \ - sum(p);\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(log n)\n    T operator[](int p) {\n        return get(p);\n    }\n    // \u5168\
    \u4F53\u306E\u7DCF\u548C\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T all_sum()\
    \ {\n        return sum(_n);\n    }\n    // [l, r) \u306Bx \u3092\u52A0\u7B97\u3059\
    \u308B \u4E00\u70B9\u53D6\u5F97\u306Fsum(p) \u3067\u884C\u3046 \u533A\u9593\u548C\
    \u30AF\u30A8\u30EA\u304C\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\u6CE8\
    \u610F O(log n)\n    void imos(int l, int r, T x) {\n        add(l, x);\n    \
    \    if (r < _n) add(r, T{}-x);\n    }\n    // x <= sum(p) \u3068\u306A\u308B\u6700\
    \u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log n)\n    int lower_bound(T x) {\n\
    \        if (x <= 0) return 0;\n        int re = 0, t = 1;\n        while (t <\
    \ _n) t <<= 1;\n        while (t) {\n            if (re + t < _n && data[re+t]\
    \ < x) {\n                x -= data[re+t];\n                re += t;\n       \
    \         t >>= 1;\n            }\n        }\n        return re;\n    }\n    //\
    \ x < sum(p) \u3068\u306A\u308B\u6700\u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log\
    \ n)\n    int upper_bound(T x) {\n        if (x < 0) return 0;\n        int re\
    \ = 0, t = 1;\n        while (t < _n) t <<= 1;\n        while (t) {\n        \
    \    if (re + t < _n && data[re+t] <= x) {\n                x -= data[re+t];\n\
    \                re += t;\n                t >>= 1;\n            }\n        }\n\
    \        return re;\n    }\n};\n#line 4 \"verify/aizu-DSL_2_B.test.cpp\"\n\r\n\
    int main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    BIT<int> s(n);\r\
    \n    while (q--) {\r\n        int x, y, z; cin >> x >> y >> z; y--;\r\n     \
    \   if (x == 0) {\r\n            s.add(y, z);\r\n        } else {\r\n        \
    \    cout << s.sum(y, z) << nl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \r\n#include \"template\"\r\n#include \"BIT\"\r\n\r\nint main() { IO();\r\n  \
    \  int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid solve()\
    \ {\r\n    int n, q; cin >> n >> q;\r\n    BIT<int> s(n);\r\n    while (q--) {\r\
    \n        int x, y, z; cin >> x >> y >> z; y--;\r\n        if (x == 0) {\r\n \
    \           s.add(y, z);\r\n        } else {\r\n            cout << s.sum(y, z)\
    \ << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/BIT.hpp
  isVerificationFile: true
  path: verify/aizu-DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:24:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu-DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu-DSL_2_B.test.cpp
- /verify/verify/aizu-DSL_2_B.test.cpp.html
title: verify/aizu-DSL_2_B.test.cpp
---
