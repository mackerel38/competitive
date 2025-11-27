---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/lazysegtree.hpp
    title: structure/lazysegtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/yosupo-static_range_sum-3.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\r\n\r\n#line 2 \"util/template.hpp\"\
    \n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n#else\n#define debug(x)\n\
    #endif\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\nusing\
    \ ull=unsigned long long;\nusing ld=long double;\nusing pi=pair<int,int>;\nusing\
    \ pll=pair<ll,ll>;\nusing str=string;\ntemplate<class T>using vec=vector<T>;\n\
    using vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using\
    \ vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using vvvll=vec<vvll>;using\
    \ vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using vvpi=vec<vpi>;using\
    \ vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\nusing vpll=vec<pll>;using\
    \ vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;\n\
    template<class T>using pairs=pair<T, T>;\ntemplate<class T>using pq=priority_queue<T,vector<T>>;\n\
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
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++){s<<v[i];if(i!=(int)v.size()-1)s<<'\
    \ ';}s<<'\\n';return s;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\nconst char nl='\\n';\nconst char sp=' ';\n\
    const int inf=(1<<30)-(1<<15);\nconst ll INF=1LL<<61;\nconst ll mod=998244353;\n\
    const ll MOD=1000000007;\nconst ld EPS=1e-9;\nconst ld PI=acos(-1);\n\nvoid IO()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n// poe\n#line 3 \"structure/lazysegtree.hpp\"\nusing namespace\
    \ std;\n\ntemplate<class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nstruct lazysegtree {\n    int _n, size, sz;\n    vector<S> data;\n\
    \    vector<F> lazy;\n    lazysegtree() = default;\n    // \u5927\u304D\u3055\
    n \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int n) : _n(n)\
    \ { build(vector<S>(n, e())); }\n    // \u5927\u304D\u3055v.size() \u306E\u30BB\
    \u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(vector<S>& v) : _n((int)v.size())\
    \ { build(v); }\n    void build(vector<S> v) {\n        size = __bit_ceil((unsigned\
    \ int)_n);\n        sz = __countr_zero(size);\n        data.assign(2 * size, e());\n\
    \        lazy.assign(2 * size, id());\n        for (int i=0; i<_n; i++) data[size+i]\
    \ = v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n    void update(int\
    \ k) { data[k] = op(data[2*k], data[2*k+1]); }\n    void all_apply(int k, F f)\
    \ {\n        data[k] = mapping(f, data[k]);\n        if (k < size) lazy[k] = composition(f,\
    \ lazy[k]);\n    }\n    void push(int k) {\n        all_apply(2*k, lazy[k]);\n\
    \        all_apply(2*k+1, lazy[k]);\n        lazy[k] = id();\n    }\n    // p\
    \ \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void\
    \ set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n \
    \       for (int i=sz; 0<i; i--) push(p >> i);\n        data[p] = x;\n       \
    \ for (int i=p>>1; 0<i; i>>=1) update(i);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i; i--) push(p\
    \ >> i);\n        return data[p];\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S operator[](int p) { return get(p);\
    \ }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\
    \ O(log n)\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
    \ _n);\n        if (l == r) return e();\n        l += size;\n        r += size;\n\
    \        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >> i);\n  \
    \      for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        S ll = e(), rr = e();\n        while (l < r) {\n            if (l & 1)\
    \ ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r], rr);\n  \
    \          l >>= 1;\n            r >>= 1;\n        }\n        return op(ll, rr);\n\
    \    }\n    // [0, n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n\
    \    S all_prod() const { return data[1]; }\n    // [0, n) \u306E\u533A\u9593\u306E\
    \u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S> values() {\n        vector<S>\
    \ re(_n);\n        for (int i=0; i<size; i++) if (lazy[i] != id()) push(i);\n\
    \        for (int i=0; i<_n; i++) re[i] = data[size+i];\n        return re;\n\
    \    }\n    // [l, r) \u306B\u5BFE\u3057\u3066 f \u3092\u9069\u7528\u3059\u308B\
    \ O(log n)\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        if (l == r) return;\n        l += size;\n        r +=\
    \ size;\n        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l) push(l >>\
    \ i);\n        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        int ll = l, rr = r;\n        while (ll < rr) {\n           \
    \ if (ll & 1) all_apply(ll++, f);\n            if (rr & 1) all_apply(--rr, f);\n\
    \            ll >>= 1;\n            rr >>= 1;\n        }\n        for (int i=1;\
    \ i<=sz; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n     \
    \       if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n  \
    \  // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059\
    \n    template<class G>\n    int max_right(int l, G g) {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(g(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        for (int i=sz; i >= 1; i--) push(l >> i);\n      \
    \  S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n      \
    \      if (!g(op(sm, data[l]))) {\n                while (l < size) {\n      \
    \              push(l);\n                    l = (2 * l);\n                  \
    \  if (g(op(sm, data[l]))) {\n                        sm = op(sm, data[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - size;\n            }\n            sm = op(sm, data[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\
    \    // f(op([l, r)))==true \u3068\u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\
    \u3059\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i=sz; i >= 1; i--) push((r - 1) >> i);\n  \
    \      S sm = e();\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r % 2)) r >>= 1;\n            if (!g(op(data[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(data[r], sm))) {\n                       \
    \ sm = op(data[r], sm);\n                        r--;\n                    }\n\
    \                }\n                return r + 1 - size;\n            }\n    \
    \        sm = op(data[r], sm);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n};\n#line 5 \"verify/yosupo-static_range_sum-3.test.cpp\"\n\r\nint\
    \ main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll a(n); cin\
    \ >> a;\r\n    lazysegtree<ll,[](ll x,ll y){return x+y;},[](){return 0LL;},ll,[](ll\
    \ x,ll y){return y;},[](ll x,ll y){return y;},[](){return 0LL;}> seg(a);\r\n \
    \   while (q--) {\r\n        int l, r; cin >> l >> r;\r\n        cout << seg.prod(l,\
    \ r) << nl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\r\n\r\
    \n#include \"template\"\r\n#include \"lazysegtree\"\r\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q; cin >> n >> q;\r\n    vll a(n); cin >> a;\r\n   \
    \ lazysegtree<ll,[](ll x,ll y){return x+y;},[](){return 0LL;},ll,[](ll x,ll y){return\
    \ y;},[](ll x,ll y){return y;},[](){return 0LL;}> seg(a);\r\n    while (q--) {\r\
    \n        int l, r; cin >> l >> r;\r\n        cout << seg.prod(l, r) << nl;\r\n\
    \    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/lazysegtree.hpp
  isVerificationFile: true
  path: verify/yosupo-static_range_sum-3.test.cpp
  requiredBy: []
  timestamp: '2025-11-27 18:39:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-static_range_sum-3.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-static_range_sum-3.test.cpp
- /verify/verify/yosupo-static_range_sum-3.test.cpp.html
title: verify/yosupo-static_range_sum-3.test.cpp
---
