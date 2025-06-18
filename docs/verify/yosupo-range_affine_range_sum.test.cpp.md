---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo-range_affine_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n#line\
    \ 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n\
    #else\n#define debug(x)\n// #pragma GCC target(\"arch=skylake-avx512\")\n// #pragma\
    \ GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n#endif\n#include<bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\nusing pi=pair<int,int>;\n\
    using pll=pair<ll,ll>;\nusing str=string;\ntemplate<class T>using vec=vector<T>;\n\
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
    }\n\nvoid solve();\n// poe\n#line 3 \"structure/lazysegtree.hpp\"\nusing namespace\
    \ std;\ntemplate<class S, auto op, class F, auto mapping, auto composition>\n\
    struct lazysegtree {\n    int _n, size, sz;\n    S _e;\n    F _id;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n    // \u5927\u304D\u3055n, \u5358\u4F4D\u5143e,\
    \ id(\u7701\u7565\u3059\u308B\u3068S{}, F{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\
    \u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(int n, S e = S{}, F id = F{}) :\
    \ _n(n), _e(e), _id(id) { build(vector<S>(n, _e)); }\n    // \u5927\u304D\u3055\
    v.size(), \u5358\u4F4D\u5143e, id(\u7701\u7565\u3059\u308B\u3068S{}, F{} \u306B\
    \u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    lazysegtree(vector<S>&\
    \ v, S e = S{}, F id = F{}) : _n(v.size()), _e(e), _id(id) { build(v); }\n   \
    \ void build(vector<S> v) {\n        size = __bit_ceil((unsigned int)_n);\n  \
    \      sz = __countr_zero(size);\n        data.assign(2 * size, _e);\n       \
    \ lazy.assign(2 * size, _id);\n        for (int i=0; i<_n; i++) data[size+i] =\
    \ v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n    void update(int\
    \ k) {\n        data[k] = op(data[2*k], data[2*k+1]);\n    }\n    void all_apply(int\
    \ k, F f) {\n        data[k] = mapping(f, data[k]);\n        if (k < size) lazy[k]\
    \ = composition(f, lazy[k]);\n    }\n    void push(int k) {\n        all_apply(2*k,\
    \ lazy[k]);\n        all_apply(2*k+1, lazy[k]);\n        lazy[k] = _id;\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i=sz; 0<i; i--) push(p >> i);\n        data[p] = x;\n      \
    \  for (int i=p>>1; 0<i; i>>=1) update(i);\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S get(int p) {\n    \
    \    assert(0 <= p && p < _n);\n        p += size;\n        for (int i=sz; 0<i;\
    \ i--) push(p >> i);\n        return data[p];\n    }\n    // p \u756A\u76EE\u306E\
    \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    S operator[](int p) {\n\
    \        return get(p);\n    }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return _e;\n        l += size;\n\
    \        r += size;\n        for (int i=sz; 0<i; i--) if (((l >> i) << i) != l)\
    \ push(l >> i);\n        for (int i=sz; 0<i; i--) if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        S ll = _e, rr = _e;\n        while (l < r) {\n        \
    \    if (l & 1) ll = op(ll, data[l++]);\n            if (r & 1) rr = op(data[--r],\
    \ rr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(ll, rr);\n    }\n    // [0, n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\
    \u308B O(1)\n    S all_prod() {\n        return data[1];\n    }\n    // [0, n)\
    \ \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S>\
    \ values() {\n        vector<S> re(_n);\n        for (int i=0; i<size; i++) {\n\
    \            if (lazy[i] != _id) push(i);\n        }\n        for (int i=0; i<_n;\
    \ i++) re[i] = data[size+i];\n        return re;\n    }\n    // [l, r) \u306B\u5BFE\
    \u3057\u3066 f \u3092\u9069\u7528\u3059\u308B O(log n)\n    void apply(int l,\
    \ int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return;\n        l += size;\n        r += size;\n        for (int i=sz; 0<i;\
    \ i--) if (((l >> i) << i) != l) push(l >> i);\n        for (int i=sz; 0<i; i--)\
    \ if (((r >> i) << i) != r) push((r - 1) >> i);\n        int ll = l, rr = r;\n\
    \        while (ll < rr) {\n            if (ll & 1) all_apply(ll++, f);\n    \
    \        if (rr & 1) all_apply(--rr, f);\n            ll >>= 1;\n            rr\
    \ >>= 1;\n        }\n        for (int i=1; i<=sz; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n};\n#line 3 \"math/modint.hpp\"\nusing namespace\
    \ std;\nlong long modint_MOD = 998244353;\n// mod \u306E\u5024\u3092\u5909\u66F4\
    \u3059\u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u306F998244353)\nvoid setmod(long\
    \ long x) { modint_MOD = x; }\nstruct mint {\n    long long val;\n    mint(long\
    \ long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n    }\n    mint&\
    \ operator+=(const mint& a) { val = (val + a.val) % modint_MOD; return *this;\
    \ }\n    mint& operator-=(const mint& a) { val = (val - a.val + modint_MOD) %\
    \ modint_MOD; return *this; }\n    mint& operator*=(const mint& a) { val = val\
    \ * a.val % modint_MOD ; return *this; }\n    mint& operator/=(const mint& a)\
    \ { return *this *= a.inv(); }\n    mint operator+(const mint& a) const { return\
    \ mint(*this) += a; }\n    mint operator-(const mint& a) const { return mint(*this)\
    \ -= a; }\n    mint operator*(const mint& a) const { return mint(*this) *= a;\
    \ }\n    mint operator/(const mint& a) const { return mint(*this) /= a; }\n  \
    \  bool operator==(const mint& a) const { return val == a.val; }\n    bool operator!=(const\
    \ mint& a) const { return val != a.val; }\n    mint& operator+=(int a) { return\
    \ *this += mint(a); }\n    mint& operator-=(int a) { return *this -= mint(a);\
    \ }\n    mint& operator*=(int a) { return *this *= mint(a); }\n    mint& operator/=(int\
    \ a) { return *this /= mint(a); }\n    mint operator+(int a) const { return mint(*this)\
    \ += a; }\n    mint operator-(int a) const { return mint(*this) -= a; }\n    mint\
    \ operator*(int a) const { return mint(*this) *= a; }\n    mint operator/(int\
    \ a) const { return mint(*this) /= a; }\n    bool operator==(int a) const { return\
    \ val == mint(a).val; }\n    bool operator!=(int a) const { return val != mint(a).val;\
    \ }\n    friend mint operator+(int a,const mint& b) { return mint(a) + b; }\n\
    \    friend mint operator-(int a,const mint& b) { return mint(a) - b; }\n    friend\
    \ mint operator*(int a,const mint& b) { return mint(a) * b; }\n    friend mint\
    \ operator/(int a,const mint& b) { return mint(a) / b; }\n    friend bool operator==(int\
    \ a, const mint& b) { return mint(a) == b; }\n    friend bool operator!=(int a,\
    \ const mint& b) { return mint(a) != b; }\n    mint& operator++() { return *this\
    \ += 1; }\n    mint operator++(int) { mint r = *this; *this += 1; return r; }\n\
    \    mint& operator--() { return *this -= 1; }\n    mint operator--(int) { mint\
    \ r = *this; *this -= 1; return r; }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\
    \u3002\u8A08\u7B97\u91CFO(log mod)\n    mint pow(long long n) const {\n      \
    \  if (n != 0) n = ((n-2) % (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;\n\
    \        mint r = 1, a = *this;\n        while (n) {\n            if (n & 1) r\
    \ *= a;\n            a *= a;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    mint inv() const { return pow(-1); }\n    friend ostream& operator<<(ostream&s,\
    \ const mint& a) { return s << a.val; }\n    friend istream& operator>>(istream&s,\
    \ mint& a) { long long x; s >> x; a = mint(x); return s; }\n};\nvector<mint>fac,\
    \ ifac;\n// n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u3002O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n\
    \ + 1);\n    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n\
    \    ifac[n] = mint(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i]\
    \ * i;\n}\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint comb(int n,int k) { return (0 <= k &&\
    \ k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\u308B\
    \u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\nmint\
    \ perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }\n\
    #line 5 \"verify/yosupo-range_affine_range_sum.test.cpp\"\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, q;\r\n    cin >> n >> q;\r\n    vec<pair<mint, mint>>\
    \ a(n);\r\n    rep(i, n) {\r\n        mint x; cin >> x;\r\n        a[i] = {x,\
    \ mint(1)};\r\n    }\r\n    auto op = [](pair<mint, mint> a, pair<mint, mint>\
    \ b) {\r\n        return make_pair(a.first + b.first, a.second + b.second);\r\n\
    \    };\r\n    auto mapping = [](pair<mint, mint> f, pair<mint, mint> x) {\r\n\
    \        return make_pair(f.first * x.first + f.second * x.second, x.second);\r\
    \n    };\r\n    auto composition = [](pair<mint, mint> f, pair<mint, mint> g)\
    \ {\r\n        return make_pair(f.first * g.first, f.first * g.second + f.second);\r\
    \n    };\r\n    lazysegtree<pair<mint, mint>, op, pair<mint, mint>, mapping, composition>\
    \ seg(a, make_pair(mint(0), mint(0)), make_pair(mint(1), mint(0)));\r\n    while\
    \ (q--) {\r\n        int t;\r\n        cin >> t;\r\n        if (t == 0) {\r\n\
    \            int l, r;\r\n            mint x, y;\r\n            cin >> l >> r\
    \ >> x >> y;\r\n            seg.apply(l, r, make_pair(x, y));\r\n        } else\
    \ {\r\n            int l, r;\r\n            cin >> l >> r;\r\n            cout\
    \ << seg.prod(l, r).first << nl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n#include \"template\"\r\n#include \"lazysegtree\"\r\n#include \"modint\"\r\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, q;\r\n    cin >> n >> q;\r\
    \n    vec<pair<mint, mint>> a(n);\r\n    rep(i, n) {\r\n        mint x; cin >>\
    \ x;\r\n        a[i] = {x, mint(1)};\r\n    }\r\n    auto op = [](pair<mint, mint>\
    \ a, pair<mint, mint> b) {\r\n        return make_pair(a.first + b.first, a.second\
    \ + b.second);\r\n    };\r\n    auto mapping = [](pair<mint, mint> f, pair<mint,\
    \ mint> x) {\r\n        return make_pair(f.first * x.first + f.second * x.second,\
    \ x.second);\r\n    };\r\n    auto composition = [](pair<mint, mint> f, pair<mint,\
    \ mint> g) {\r\n        return make_pair(f.first * g.first, f.first * g.second\
    \ + f.second);\r\n    };\r\n    lazysegtree<pair<mint, mint>, op, pair<mint, mint>,\
    \ mapping, composition> seg(a, make_pair(mint(0), mint(0)), make_pair(mint(1),\
    \ mint(0)));\r\n    while (q--) {\r\n        int t;\r\n        cin >> t;\r\n \
    \       if (t == 0) {\r\n            int l, r;\r\n            mint x, y;\r\n \
    \           cin >> l >> r >> x >> y;\r\n            seg.apply(l, r, make_pair(x,\
    \ y));\r\n        } else {\r\n            int l, r;\r\n            cin >> l >>\
    \ r;\r\n            cout << seg.prod(l, r).first << nl;\r\n        }\r\n    }\r\
    \n}"
  dependsOn:
  - util/template.hpp
  - structure/lazysegtree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: verify/yosupo-range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-18 08:29:31+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-range_affine_range_sum.test.cpp
- /verify/verify/yosupo-range_affine_range_sum.test.cpp.html
title: verify/yosupo-range_affine_range_sum.test.cpp
---
