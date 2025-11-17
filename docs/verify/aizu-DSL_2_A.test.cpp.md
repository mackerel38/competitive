---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: structure/segtree.hpp
    title: structure/segtree.hpp
  - icon: ':x:'
    path: util/generalsegtree.hpp
    title: util/generalsegtree.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/aizu-DSL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
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
    // poe\n#line 3 \"structure/segtree.hpp\"\nusing namespace std;\n// op(op(a, b),\
    \ c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\u308B\
    (\u7D50\u5408\u5F8B)\ntemplate<class S, auto op, auto e>\nstruct segtree {\n \
    \   int _n, size;\n    vector<S> data;\n    segtree() = default;\n    // \u5927\
    \u304D\u3055n \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(int\
    \ n) : _n(n) { build(vector<S>(n, e())); }\n    // \u5927\u304D\u3055v.size()\
    \ \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(vector<S>& v) :\
    \ _n(v.size()) { build(v); }\n    void build(vector<S> v) {\n        size = __bit_ceil((unsigned\
    \ int)_n);\n        data.assign(2 * size, e());\n        for (int i=0; i<_n; i++)\
    \ data[size+i] = v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        data[p] = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n    }\n   \
    \ // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n   \
    \ S get(int p) {\n        assert(0 <= p && p < _n);\n        return data[size+p];\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S operator[](int p) {\n        return get(p);\n    }\n    // [l, r)\
    \ \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S\
    \ prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n       \
    \ S ll = e(), rr = e();\n        l += size;\n        r += size;\n        while\
    \ (l < r) {\n            if (l & 1) ll = op(ll, data[l++]);\n            if (r\
    \ & 1) rr = op(data[--r], rr);\n            l >>= 1;\n            r >>= 1;\n \
    \       }\n        return op(ll, rr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\
    \u30EA\u306B\u7B54\u3048\u308B O(1)\n    S all_prod() {\n        return data[1];\n\
    \    }\n    // [0, _n) \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(n)\n    vector<S> values() {\n        vector<S> re(_n);\n        for (int\
    \ i=0; i<_n; i++) re[i] = data[size+i];\n        return re;\n    }\n    void update(int\
    \ p) {\n        data[p] = op(data[2*p], data[2*p+1]);\n    }\n    // f(op([l,\
    \ r)))=true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059 O(log n)\n\
    \    template <class F>\n    int max_right(int l, F f) {\n        assert(f(e()));\n\
    \        assert(0 <= l && l <= _n);\n        if (l == _n) return l;\n        l\
    \ += size;\n        S s = e();\n        do {\n            while (l % 2 == 0) l\
    \ >>= 1;\n            if (!f(op(s, data[l]))) {\n                while (l < size)\
    \ {\n                    l = 2 * l;\n                    if (f(op(s, data[l])))\
    \ s = op(s, data[l++]);\n                }\n                return l - size;\n\
    \            }\n            s = op(s, data[l]);\n            l++;\n        } while\
    \ (l != (l & -l));\n        return _n;\n    }\n    // f(op([l, r)))=true \u3068\
    \u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\u3059 O(log n)\n    template <class\
    \ F>\n    int min_left(int r, F f) {\n        assert(f(e()));\n        assert(0\
    \ <= r && r <= _n);\n        if (r == 0) return r;\n        r += size;\n     \
    \   S s = e();\n        do {\n            r--;\n            while (r % 2 == 1)\
    \ r >>= 1;\n            if (!f(op(data[r], s))) {\n                while (r <\
    \ size) {\n                    r = 2 * r + 1;\n                    if (f(op(data[r],\
    \ s))) s = op(data[r--], s);\n                }\n                return (r + 1)\
    \ - size;\n            }\n            s = op(data[r], s);\n        } while(r !=\
    \ (r & -r));\n        return 0;\n    }\n};\n#line 4 \"util/generalsegtree.hpp\"\
    \nusing namespace std;\nusing rangesum_int=segtree<int,[](int a,int b)->int{return\
    \ a+b;},[]()->int{return 0;}>;\nusing rangesum_ll=segtree<long long,[](long long\
    \ a,long long b)->long long{return a+b;},[]()->long long{return 0LL;}>;\nusing\
    \ rangemin_int=segtree<int,[](int a,int b)->int{return min(a,b);},[]()->int{return\
    \ numeric_limits<int>::max();}>;\nusing rangemin_ll=segtree<long long,[](long\
    \ long a,long long b)->long long{return min(a,b);},[]()->long long{return numeric_limits<long\
    \ long>::max();}>;\nusing rangemax_int=segtree<int,[](int a,int b)->int{return\
    \ max(a,b);},[]()->int{return numeric_limits<int>::min();}>;\nusing rangemax_ll=segtree<long\
    \ long,[](long long a,long long b)->long long{return max(a,b);},[]()->long long{return\
    \ numeric_limits<long long>::min();}>;\n#line 4 \"verify/aizu-DSL_2_A.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    rangemin_int\
    \ seg(n);\r\n    while (q--) {\r\n        ll x, y, z; cin >> x >> y >> z;\r\n\
    \        if (x == 0) {\r\n            seg.set(y, z);\r\n        } else {\r\n \
    \           cout << seg.prod(y, z+1) << nl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \r\n#include \"template\"\r\n#include \"generalsegtree\"\r\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    rangemin_int seg(n);\r\n  \
    \  while (q--) {\r\n        ll x, y, z; cin >> x >> y >> z;\r\n        if (x ==\
    \ 0) {\r\n            seg.set(y, z);\r\n        } else {\r\n            cout <<\
    \ seg.prod(y, z+1) << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - util/generalsegtree.hpp
  - structure/segtree.hpp
  isVerificationFile: true
  path: verify/aizu-DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:24:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu-DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu-DSL_2_A.test.cpp
- /verify/verify/aizu-DSL_2_A.test.cpp.html
title: verify/aizu-DSL_2_A.test.cpp
---
