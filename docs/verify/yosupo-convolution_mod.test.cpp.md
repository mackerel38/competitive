---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/NTT.hpp
    title: math/NTT.hpp
  - icon: ':x:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  - icon: ':x:'
    path: math/modint.hpp
    title: math/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/yosupo-convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\r\n#line 2 \"util/template.hpp\"\
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
    // poe\n#line 3 \"math/modint.hpp\"\nusing namespace std;\n\ntemplate <long long\
    \ modint_MOD>\nstruct modint {\n    long long val;\n    constexpr modint(long\
    \ long x=0) noexcept {\n        x %= modint_MOD;\n        if (x < 0) x += modint_MOD;\n\
    \        val = x;\n    }\n    explicit constexpr operator long long() const noexcept\
    \ { return val; }\n    template<typename Int>\n    static constexpr long long\
    \ adjust(Int x) noexcept {\n        static_assert(std::is_integral<Int>::value,\
    \ \"Int must be integral\");\n        __int128 t = static_cast<__int128>(x);\n\
    \        __int128 m = static_cast<__int128>(modint_MOD);\n        t %= m;\n  \
    \      if (t < 0) t += m;\n        return static_cast<long long>(t);\n    }\n\
    \    constexpr modint operator+(const modint& x) const noexcept { return modint(*this)\
    \ += x; }\n    constexpr modint operator-(const modint& x) const noexcept { return\
    \ modint(*this) -= x; }\n    constexpr modint operator*(const modint& x) const\
    \ noexcept { return modint(*this) *= x; }\n    constexpr modint operator/(const\
    \ modint& x) const noexcept { return modint(*this) /= x; }\n    constexpr modint&\
    \ operator+=(const modint& x) noexcept {\n        if (modint_MOD <= (val += x.val))\
    \ val -= modint_MOD;\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint& x) noexcept {\n        if ((val -= x.val) < 0) val += modint_MOD;\n\
    \        return *this;\n    }\n    constexpr modint& operator*=(const modint&\
    \ x) noexcept {\n        __int128 t = (__int128)val * x.val;\n        val = (long\
    \ long)(t % modint_MOD);\n        if (val < 0) val += modint_MOD;\n        return\
    \ *this;\n    }\n    constexpr modint& operator/=(modint x) noexcept {\n     \
    \   *this *= x.inv();\n        return *this;\n    }\n    constexpr modint operator-()\
    \ const noexcept { return modint() - *this; }\n    constexpr modint& operator++()\
    \ noexcept { return *this += 1; }\n    constexpr modint& operator--() noexcept\
    \ { return *this -= 1; }\n    constexpr modint operator++(int) noexcept { modint\
    \ tmp = *this; ++*this; return tmp; }\n    constexpr modint operator--(int) noexcept\
    \ { modint tmp = *this; --*this; return tmp; }\n    constexpr bool operator==(const\
    \ modint& x) const noexcept { return val == x.val; }\n    constexpr bool operator!=(const\
    \ modint& x) const noexcept { return val != x.val; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr modint&\
    \ operator+=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n      \
    \  if (modint_MOD <= (val += y)) val -= modint_MOD;\n        return *this;\n \
    \   }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator-=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        if ((val -= y) < 0) val += modint_MOD;\n        return *this;\n    }\n\
    \    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    constexpr modint& operator*=(Int x) noexcept {\n        long long y = adjust<Int>(x);\n\
    \        __int128 t = (__int128)val * y;\n        val = (long long)(t % modint_MOD);\n\
    \        if (val < 0) val += modint_MOD;\n        return *this;\n    }\n    template<typename\
    \ Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n    constexpr\
    \ modint& operator/=(Int x) noexcept {\n        modint t = modint(adjust<Int>(x));\n\
    \        *this /= t;\n        return *this;\n    }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator+(const modint& a, Int b) noexcept { modint t = a; t += b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator+(Int a, const modint& b) noexcept { modint\
    \ t = b; t += a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(const modint& a, Int b) noexcept { modint\
    \ t = a; t -= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator-(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t -= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ modint operator*(const modint& a, Int b) noexcept { modint t = a; t *= b; return\
    \ t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator*(Int a, const modint& b) noexcept { modint\
    \ t = b; t *= a; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(const modint& a, Int b) noexcept { modint\
    \ t = a; t /= b; return t; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr modint operator/(Int a, const modint& b) noexcept { modint\
    \ t = modint(adjust<Int>(a)); t /= b; return t; }\n    template<typename Int,\
    \ typename = std::enable_if_t<std::is_integral<Int>::value>>\n    friend constexpr\
    \ bool operator==(const modint& a, Int b) noexcept { return a.val == adjust<Int>(b);\
    \ }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator==(Int a, const modint& b) noexcept { return\
    \ adjust<Int>(a) == b.val; }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(const modint& a, Int b) noexcept { return\
    \ !(a == b); }\n    template<typename Int, typename = std::enable_if_t<std::is_integral<Int>::value>>\n\
    \    friend constexpr bool operator!=(Int a, const modint& b) noexcept { return\
    \ !(a == b); }\n    friend constexpr istream& operator>> (istream& i, modint&\
    \ x) { long long y; i >> y; x = modint(y); return i; }\n    friend constexpr ostream&\
    \ operator<< (ostream& o, const modint& x) { o << x.val; return o; }\n    constexpr\
    \ modint pow(long long n) const noexcept {\n        if (n < 0) return inv().pow(-n);\n\
    \        modint x = *this, re = 1;\n        while (0 < n){\n            if (n\
    \ & 1) re *= x;\n            x *= x;\n            n >>= 1;\n        }\n      \
    \  return re;\n    }\n    constexpr modint inv() const noexcept { return pow(modint_MOD\
    \ - 2); }\n};\n\ntemplate <long long modint_MOD>\nstruct factor {\n    vector<modint<modint_MOD>>\
    \ fac, ifac;\n    factor(int n) : fac(n+1), ifac(n+1) {\n        fac[0] = 1;\n\
    \        for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n        ifac[n] = fac[n].inv();\n\
    \        for (int i=n; 1<=i; i--) ifac[i-1] = ifac[i] * i;\n    }\n    modint<modint_MOD>\
    \ P(int n, int r) const noexcept { return (r<0 || n<r) ? 0 : fac[n] * ifac[n-r];\
    \ }\n    modint<modint_MOD> C(int n, int r) const noexcept { return (r<0 || n<r)\
    \ ? 0 : P(n, r) * ifac[r]; }\n    modint<modint_MOD> H(int n, int r) const noexcept\
    \ { return (n==0 && r==0) ? 1 : C(n+r-1, r); }\n};\n#line 4 \"math/NTT.hpp\"\n\
    using namespace std;\n\ntemplate <long long NTT_MOD>\nvoid NTT(vector<modint<NTT_MOD>>&\
    \ a, bool inv=false, int g_=3) {\n    modint<NTT_MOD> g = g_;\n    int n = (int)a.size();\n\
    \    for (int i=1, j=0; i<n; i++) {\n        int bit = n >> 1;\n        for (;\
    \ j&bit; bit>>=1) j ^= bit;\n        j ^= bit;\n        if (i < j) swap(a[i],\
    \ a[j]);\n    }\n    for (int len=2; len<=n; len<<=1) {\n        modint<NTT_MOD>\
    \ wlen = g.pow((NTT_MOD - 1) / len);\n        if (inv) wlen = wlen.inv();\n  \
    \      for (int i=0; i<n; i+=len) {\n            modint<NTT_MOD> w = 1;\n    \
    \        for (int j=0; j<len/2; j++) {\n                modint<NTT_MOD> u = a[i+j];\n\
    \                modint<NTT_MOD> v = a[i+j+len/2]*w;\n                a[i+j] =\
    \ u + v;\n                a[i+j+len/2] = u - v;\n                w *= wlen;\n\
    \            }\n        }\n    }\n    if (inv) {\n        modint<NTT_MOD> inv_n\
    \ = modint<NTT_MOD>(n).inv();\n        for (auto& x : a) x *= inv_n;\n    }\n\
    }\n#line 4 \"math/convolution.hpp\"\nusing namespace std;\n\ntemplate<long long\
    \ convolution_MOD>\nvector<modint<convolution_MOD>> convolution(vector<modint<convolution_MOD>>\
    \ a,vector<modint<convolution_MOD>> b){\n    int n = 1;\n    int s = (int)(a.size()+b.size()-1);\n\
    \    while (n < s) n<<=1;\n    a.resize(n);\n    b.resize(n);\n    NTT(a);\n \
    \   NTT(b);\n    for (int i=0; i<n; i++) a[i] *= b[i];\n    NTT(a,true);\n   \
    \ a.resize(s);\n    return a;\n}\n#line 4 \"verify/yosupo-convolution_mod.test.cpp\"\
    \nusing mint = modint<998244353>;\r\n\r\nint main() { IO();\r\n    int T=1;\r\n\
    \    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid solve() {\r\n \
    \   int n, m; cin >> n >> m;\r\n    vec<mint> a(n), b(m); cin >> a; cin >> b;\r\
    \n    vec<mint> c = convolution(a, b);\r\n    cout << c;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\r\n#include\
    \ \"template\"\r\n#include \"convolution\"\r\nusing mint = modint<998244353>;\r\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    vec<mint>\
    \ a(n), b(m); cin >> a; cin >> b;\r\n    vec<mint> c = convolution(a, b);\r\n\
    \    cout << c;\r\n}"
  dependsOn:
  - util/template.hpp
  - math/convolution.hpp
  - math/NTT.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: verify/yosupo-convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:24:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-convolution_mod.test.cpp
- /verify/verify/yosupo-convolution_mod.test.cpp.html
title: verify/yosupo-convolution_mod.test.cpp
---
