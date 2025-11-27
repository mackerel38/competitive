---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/BIT.hpp
    title: structure/BIT.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo-point_add_range_sum-2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n\r\n#line\
    \ 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n\
    #else\n#define debug(x)\n#endif\n#include<bits/stdc++.h>\nusing namespace std;\n\
    using ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\nusing\
    \ pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\ntemplate<class\
    \ T>using vec=vector<T>;\nusing vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using\
    \ vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using\
    \ vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using\
    \ vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\n\
    using vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using\
    \ vvvvvpll=vec<vvvvpll>;\ntemplate<class T>using pairs=pair<T, T>;\ntemplate<class\
    \ T>using pq=priority_queue<T,vector<T>>;\ntemplate<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;\n\
    #define rep(i,n) for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
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
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++){s<<v[i];if(i!=(int)v.size()-1)s<<'\
    \ ';}s<<'\\n';return s;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\nconst char nl='\\n';\nconst char sp=' ';\n\
    const int inf=(1<<30)-(1<<15);\nconst ll INF=1LL<<61;\nconst ll mod=998244353;\n\
    const ll MOD=1000000007;\nconst ld EPS=1e-9;\nconst ld PI=acos(-1);\n\nvoid IO()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n// poe\n#line 3 \"structure/BIT.hpp\"\nusing namespace std;\n\
    \ntemplate<class T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n    BIT()\
    \ = default;\n    // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(int n) : _n(n), data(_n,\
    \ T{}) {}\n    // BIT \u3092\u69CB\u7BC9 O(n)\n    BIT(vector<T>& v) : _n((int)v.size()),\
    \ data(v) {\n        for (int i=1; i<=_n; i++) {\n            int j = i+(i&-i);\n\
    \            if (j <= _n) data[j-1] += data[i-1];\n        }\n    }\n    // p\
    \ \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\u308B O(log n)\n  \
    \  void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        int i =\
    \ p + 1;\n        while (i <= _n) {\n            data[i-1] += x;\n           \
    \ i += i & -i;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092x \u306B\
    \u3059\u308B O(log n)\n    void set(int p, T x) { add(p, x - get(p)); }\n    //\
    \ [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int r)\
    \ const {\n        assert(0 <= r && r <= _n);\n        T re = T{};\n        int\
    \ i = r;\n        while (i > 0) {\n            re += data[i-1];\n            i\
    \ -= i & -i;\n        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r) const {\n   \
    \     assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log\
    \ n)\n    T get(int p) const { return sum(p+1) - sum(p); }\n    // p \u756A\u76EE\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T operator[](int p) const\
    \ { return get(p); }\n};\n#line 5 \"verify/yosupo-point_add_range_sum-2.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll\
    \ a(n); cin >> a;\r\n    BIT<ll> seg(a);\r\n    while (q--) {\r\n        int x,\
    \ y, z; cin >> x >> y >> z;\r\n        if (x == 0) {\r\n            seg.add(y,\
    \ z);\r\n        } else {\r\n            cout << seg.sum(y, z) << nl;\r\n    \
    \    }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"template\"\r\n#include \"BIT\"\r\n\r\nint main() { IO();\r\n\
    \    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll a(n); cin >> a;\r\n   \
    \ BIT<ll> seg(a);\r\n    while (q--) {\r\n        int x, y, z; cin >> x >> y >>\
    \ z;\r\n        if (x == 0) {\r\n            seg.add(y, z);\r\n        } else\
    \ {\r\n            cout << seg.sum(y, z) << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/BIT.hpp
  isVerificationFile: true
  path: verify/yosupo-point_add_range_sum-2.test.cpp
  requiredBy: []
  timestamp: '2025-11-27 16:51:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_add_range_sum-2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_add_range_sum-2.test.cpp
- /verify/verify/yosupo-point_add_range_sum-2.test.cpp.html
title: verify/yosupo-point_add_range_sum-2.test.cpp
---
