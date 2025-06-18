---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/NTT.hpp
    title: math/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/yosupo-convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\r\n#line 2 \"util/template.hpp\"\
    \n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n#else\n#define debug(x)\n\
    // #pragma GCC target(\"arch=skylake-avx512\")\n// #pragma GCC target(\"avx2\"\
    )\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\
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
    }\n\nvoid solve();\n// poe\n#line 3 \"math/modint.hpp\"\nusing namespace std;\n\
    long long modint_MOD = 998244353;\n// mod \u306E\u5024\u3092\u5909\u66F4\u3059\
    \u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u306F998244353)\nvoid setmod(long long x)\
    \ { modint_MOD = x; }\nstruct mint {\n    long long val;\n    mint(long long x=0)\
    \ {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n    }\n    mint& operator+=(const\
    \ mint& a) { val = (val + a.val) % modint_MOD; return *this; }\n    mint& operator-=(const\
    \ mint& a) { val = (val - a.val + modint_MOD) % modint_MOD; return *this; }\n\
    \    mint& operator*=(const mint& a) { val = val * a.val % modint_MOD ; return\
    \ *this; }\n    mint& operator/=(const mint& a) { return *this *= a.inv(); }\n\
    \    mint operator+(const mint& a) const { return mint(*this) += a; }\n    mint\
    \ operator-(const mint& a) const { return mint(*this) -= a; }\n    mint operator*(const\
    \ mint& a) const { return mint(*this) *= a; }\n    mint operator/(const mint&\
    \ a) const { return mint(*this) /= a; }\n    bool operator==(const mint& a) const\
    \ { return val == a.val; }\n    bool operator!=(const mint& a) const { return\
    \ val != a.val; }\n    mint& operator+=(int a) { return *this += mint(a); }\n\
    \    mint& operator-=(int a) { return *this -= mint(a); }\n    mint& operator*=(int\
    \ a) { return *this *= mint(a); }\n    mint& operator/=(int a) { return *this\
    \ /= mint(a); }\n    mint operator+(int a) const { return mint(*this) += a; }\n\
    \    mint operator-(int a) const { return mint(*this) -= a; }\n    mint operator*(int\
    \ a) const { return mint(*this) *= a; }\n    mint operator/(int a) const { return\
    \ mint(*this) /= a; }\n    bool operator==(int a) const { return val == mint(a).val;\
    \ }\n    bool operator!=(int a) const { return val != mint(a).val; }\n    friend\
    \ mint operator+(int a,const mint& b) { return mint(a) + b; }\n    friend mint\
    \ operator-(int a,const mint& b) { return mint(a) - b; }\n    friend mint operator*(int\
    \ a,const mint& b) { return mint(a) * b; }\n    friend mint operator/(int a,const\
    \ mint& b) { return mint(a) / b; }\n    friend bool operator==(int a, const mint&\
    \ b) { return mint(a) == b; }\n    friend bool operator!=(int a, const mint& b)\
    \ { return mint(a) != b; }\n    mint& operator++() { return *this += 1; }\n  \
    \  mint operator++(int) { mint r = *this; *this += 1; return r; }\n    mint& operator--()\
    \ { return *this -= 1; }\n    mint operator--(int) { mint r = *this; *this -=\
    \ 1; return r; }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\u7B97\
    \u91CFO(log mod)\n    mint pow(long long n) const {\n        if (n != 0) n = ((n-2)\
    \ % (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;\n        mint r = 1, a\
    \ = *this;\n        while (n) {\n            if (n & 1) r *= a;\n            a\
    \ *= a;\n            n >>= 1;\n        }\n        return r;\n    }\n    mint inv()\
    \ const { return pow(-1); }\n    friend ostream& operator<<(ostream&s, const mint&\
    \ a) { return s << a.val; }\n    friend istream& operator>>(istream&s, mint& a)\
    \ { long long x; s >> x; a = mint(x); return s; }\n};\nvector<mint>fac, ifac;\n\
    // n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\u3002\
    O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n + 1);\n\
    \    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n    ifac[n]\
    \ = mint(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i;\n\
    }\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\u3057\
    \u304C\u5FC5\u9808\u3002O(1)\nmint comb(int n,int k) { return (0 <= k && k <=\
    \ n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\u308B\u3002\
    buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\nmint perm(int\
    \ n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }\n#line 4 \"\
    math/NTT.hpp\"\nusing namespace std;\nvoid NTT(vector<mint>& a, bool invert=false)\
    \ {\n    int n = a.size();\n    for (int i=1, j=0; i<n; i++) {\n        int b;\n\
    \        for (b=n>>1; j&b; b>>=1) j ^= b;\n        j ^= b;\n        if (i < j)\
    \ swap(a[i], a[j]);\n    }\n    for (int len=2; len<=n; len<<=1) {\n        mint\
    \ wlen = mint(3).pow((998244353 - 1) / len);\n        if (invert) wlen = wlen.inv();\n\
    \        for (int i=0; i<n; i+=len) {\n            mint w = 1;\n            for\
    \ (int j=0; j<len/2; j++) {\n                mint u = a[i+j], v = a[i+j+len/2]\
    \ * w;\n                a[i+j] = u + v;\n                a[i+j+len/2] = u - v;\n\
    \                w *= wlen;\n            }\n        }\n    }\n    if (invert)\
    \ {\n        mint inv_n = mint(n).inv();\n        for (auto& x : a) x *= inv_n;\n\
    \    }\n}\n#line 4 \"math/convolution.hpp\"\nusing namespace std;\nvector<int>\
    \ convolution(vector<int>& a, vector<int>& b) {\n    int n=1;\n    while (n <\
    \ a.size()+b.size()-1) n <<= 1;\n    vector<mint> A(n), B(n);\n    for (int i=0;\
    \ i<a.size(); i++) {\n        A[i] = mint(a[i]);\n    }\n    for (int i=0; i<b.size();\
    \ i++) {\n        B[i] = mint(b[i]);\n    }\n    NTT(A, false);\n    NTT(B, false);\n\
    \    for (int i=0; i<n; i++) {\n        A[i] *= B[i];\n    }\n    NTT(A, true);\n\
    \    vector<int> re(a.size()+b.size()-1);\n    for (int i=0; i<a.size()+b.size()-1;\
    \ i++) {\n        re[i] = A[i].val;\n    }\n    return re;\n}\n#line 4 \"verify/yosupo-convolution_mod.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    vi\
    \ a(n), b(m); cin >> a; cin >> b;\r\n    vi c = convolution(a, b);\r\n    cout\
    \ << c;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\r\n#include\
    \ \"template\"\r\n#include \"convolution\"\r\n\r\nint main() { IO();\r\n    int\
    \ T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid solve()\
    \ {\r\n    int n, m; cin >> n >> m;\r\n    vi a(n), b(m); cin >> a; cin >> b;\r\
    \n    vi c = convolution(a, b);\r\n    cout << c;\r\n}"
  dependsOn:
  - util/template.hpp
  - math/convolution.hpp
  - math/NTT.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: verify/yosupo-convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2025-06-18 08:29:31+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-convolution_mod.test.cpp
- /verify/verify/yosupo-convolution_mod.test.cpp.html
title: verify/yosupo-convolution_mod.test.cpp
---
