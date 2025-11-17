---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/dynamicsegtree.hpp
    title: structure/dynamicsegtree.hpp
  - icon: ':question:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo-point_add_range_sum_2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n#line 2 \"\
    util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n\
    #else\n#define debug(x)\n#endif\n#include<bits/stdc++.h>\nusing namespace std;\n\
    using ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\nusing\
    \ pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\ntemplate<class\
    \ T>using vec=vector<T>;\nusing vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using\
    \ vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using\
    \ vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using\
    \ vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\n\
    using vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using\
    \ vvvvvpll=vec<vvvvpll>;\ntemplate<class T>using pq=priority_queue<T,vector<T>>;\n\
    template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define per(i,n) for(int i=(int)(n)-1;0<=i;i--)\n#define per1(i,n) for(int i=(int)(n);0<i;i--)\n\
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
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(auto&i:v)s<<i<<'\
    \ ';s<<'\\n';return s;}\ntemplate<class F>long long bsearch(long long ok,long\
    \ long ng,F&f){while(abs(ok-ng)>1){long long mid=(ok+ng)/2;if(f(mid))ok=mid;else\
    \ ng=mid;}return ok;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\n#define nl '\\n'\n#define sp ' '\n#define\
    \ inf ((1<<30)-(1<<15))\n#define INF (1LL<<61)\n#define mod 998244353\n\nvoid\
    \ IO() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n// poe\n#line 3 \"structure/dynamicsegtree.hpp\"\nusing namespace\
    \ std;\n// op(op(a, b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\
    \u8981\u304C\u3042\u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto op, auto\
    \ e>\nstruct dynamicsegtree {\n    long long _n, size;\n    unordered_map<long\
    \ long, S> data;\n    dynamicsegtree() = default;\n    // \u5927\u304D\u3055n,\
    \ \u5358\u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068S{} \u306B\u306A\u308B) \u306E\
    \u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(log n)\n    dynamicsegtree(long long n)\
    \ : _n(n) {\n        size = 1;\n        while (size < _n) size <<= 1;\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(long long p, S x) {\n        assert(0 <= p && p < _n);\n       \
    \ p += size;\n        data[p] = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S get(long long p) {\n        assert(0 <= p && p < _n);\n        return\
    \ data[size+p];\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B O(1)\n    S operator[](long long p) {\n        return get(p);\n \
    \   }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\
    \ O(log n)\n    S prod(long long l, long long r) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n   \
    \     r += size;\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ data.count(l) ? data[l] : e()), ++l;\n            if (r & 1) --r, smr = op(data.count(r)\
    \ ? data[r] : e(), smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n        return op(sml, smr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(1)\n    S all_prod() {\n        return data[1];\n \
    \   }\n    void update(long long p) {\n        S l = e(), r = e();\n        if\
    \ (data.count(2*p)) l = data[2*p];\n        if (data.count(2*p+1)) r = data[2*p+1];\n\
    \        data[p] = op(l, r);\n    }\n};\n#line 4 \"verify/yosupo-point_add_range_sum_2.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    auto\
    \ op=[](ll x,ll y)->ll{return x+y;};\r\n    auto e=[]()->ll{return 0;};\r\n  \
    \  dynamicsegtree<ll, op, e> s(n);\r\n    rep(i, n) {\r\n        int x; cin >>\
    \ x;\r\n        s.set(i, x);\r\n    }\r\n    while (q--) {\r\n        int x, y,\
    \ z; cin >> x >> y >> z;\r\n        if (x == 0) {\r\n            s.set(y, z+s.get(y));\r\
    \n        } else {\r\n            cout << s.prod(y, z) << nl;\r\n        }\r\n\
    \    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n#include \"template\"\r\n#include \"dynamicsegtree\"\r\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    auto op=[](ll x,ll y)->ll{return\
    \ x+y;};\r\n    auto e=[]()->ll{return 0;};\r\n    dynamicsegtree<ll, op, e> s(n);\r\
    \n    rep(i, n) {\r\n        int x; cin >> x;\r\n        s.set(i, x);\r\n    }\r\
    \n    while (q--) {\r\n        int x, y, z; cin >> x >> y >> z;\r\n        if\
    \ (x == 0) {\r\n            s.set(y, z+s.get(y));\r\n        } else {\r\n    \
    \        cout << s.prod(y, z) << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/dynamicsegtree.hpp
  isVerificationFile: true
  path: verify/yosupo-point_add_range_sum_2.test.cpp
  requiredBy: []
  timestamp: '2025-08-10 21:02:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-point_add_range_sum_2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_add_range_sum_2.test.cpp
- /verify/verify/yosupo-point_add_range_sum_2.test.cpp.html
title: verify/yosupo-point_add_range_sum_2.test.cpp
---
