---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  - icon: ':x:'
    path: structure/sqrttree.hpp
    title: structure/sqrttree.hpp
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
  bundledCode: "#line 1 \"verify/yosupo-point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n#line 2 \"util/template.hpp\"\
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
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define per(i,n) for(int i=(int)(n)-1;0<=i;i--)\n\
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
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(auto&i:v)s<<i<<'\
    \ ';s<<'\\n';return s;}\ntemplate<class F>long long bsearch(long long ok,long\
    \ long ng,F&f){while(abs(ok-ng)>1){long long mid=(ok+ng)/2;if(f(mid))ok=mid;else\
    \ ng=mid;}return ok;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\n#define nl '\\n'\n#define sp ' '\n#define\
    \ inf ((1<<30)-(1<<15))\n#define INF (1LL<<61)\n#define mod 998244353\n\nvoid\
    \ IO() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n// poe\n#line 3 \"math/isqrt.hpp\"\nusing namespace std;\n\
    \n// floor(sqrt(n)) \u3092\u8FD4\u3059\nlong long isqrt(long long n) {\n    assert(0\
    \ <= n);\n    long long re = sqrt(n);\n    while ((re + 1) * (re + 1) <= n) re++;\n\
    \    while (n < re * re) re--;\n    return re;\n}\n#line 4 \"structure/sqrttree.hpp\"\
    \nusing namespace std;\n\ntemplate <class S, auto op, auto e, class F, auto mapping,\
    \ auto mapping2>\nstruct sqrttree {\n    int n, bsize, m;\n    vector<S> data,\
    \ block;\n    sqrttree() = default;\n    sqrttree(int n) : sqrttree(vector<S>(n,\
    \ e())) {}\n    sqrttree(vector<S> v) {\n        n = v.size();\n        bsize\
    \ = isqrt(n) + 1;\n        m = bsize * bsize;\n        data.reserve(m);\n    \
    \    block.reserve(bsize);\n        for (int i=0; i<bsize; i++) {\n          \
    \  block[i] = e();\n            for (int j=0; j<bsize; j++) {\n              \
    \  int k = i * bsize + j;\n                if (k < n) {\n                    data[k]\
    \ = v[k];\n                } else {\n                    data[k] = e();\n    \
    \            }\n                block[i] = op(block[i], data[k]);\n          \
    \  }\n        }\n    }\n    void apply(int i, F f) {\n        assert(0<=i && i<n);\n\
    \        data[i] = mapping(f, data[i]);\n        block[i/bsize] = mapping2(f,\
    \ block[i/bsize]);\n    }\n    S get(int i) {\n        assert(0 <= i && i < n);\n\
    \        return data[i];\n    }\n    S operator[](int i) {\n        return get(i);\n\
    \    }\n    S prod(int l, int r) {\n        assert(0<=l && l<=r && r<=n);\n  \
    \      S re = e();\n        for (int i=0; i<bsize; i++) {\n            if (r<=i*bsize\
    \ || (i+1)*bsize<=l) continue;\n            if (l<=i*bsize && (i+1)*bsize<=r)\
    \ re = op(re, block[i]);\n            else {\n                for (int j=0; j<bsize;\
    \ j++) {\n                    int k = i * bsize + j;\n                    if (l<=k\
    \ && k<r) {\n                        re = op(re, data[k]);\n                 \
    \   }\n                }\n            }\n        }\n        return re;\n    }\n\
    };\n#line 4 \"verify/yosupo-point_add_range_sum.test.cpp\"\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll a(n); cin >> a;\r\n   \
    \ sqrttree<ll,[](ll a,ll b){return a+b;},[](){return 0;},ll,[](ll a,ll b){return\
    \ a+b;},[](ll a,ll b){return a+b;}> seg(a);\r\n    while (q--) {\r\n        int\
    \ x, y, z; cin >> x >> y >> z;\r\n        if (x == 0) {\r\n            seg.apply(y,\
    \ z);\r\n        } else {\r\n            cout << seg.prod(y, z) << nl;\r\n   \
    \     }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n#include \"template\"\r\n#include \"sqrttree\"\r\n\r\nint main() { IO();\r\n\
    \    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll a(n); cin >> a;\r\n   \
    \ sqrttree<ll,[](ll a,ll b){return a+b;},[](){return 0;},ll,[](ll a,ll b){return\
    \ a+b;},[](ll a,ll b){return a+b;}> seg(a);\r\n    while (q--) {\r\n        int\
    \ x, y, z; cin >> x >> y >> z;\r\n        if (x == 0) {\r\n            seg.apply(y,\
    \ z);\r\n        } else {\r\n            cout << seg.prod(y, z) << nl;\r\n   \
    \     }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/sqrttree.hpp
  - math/isqrt.hpp
  isVerificationFile: true
  path: verify/yosupo-point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-08-07 22:45:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_add_range_sum.test.cpp
- /verify/verify/yosupo-point_add_range_sum.test.cpp.html
title: verify/yosupo-point_add_range_sum.test.cpp
---
