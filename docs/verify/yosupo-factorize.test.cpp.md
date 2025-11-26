---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.hpp
    title: math/prime.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"verify/yosupo-factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#line 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\"\
    : \"<<x<<endl\n#else\n#define debug(x)\n#endif\n#include<bits/stdc++.h>\nusing\
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
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(int i=0;i<(int)v.size();i++){s<<v[i];if(i!=v.size()-1)s<<'\
    \ ';}s<<'\\n';return s;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\n#define nl '\\n'\n#define sp ' '\nconst\
    \ int inf = (1<<30)-(1<<15);\nconst ll INF = 1LL<<61;\nconst ll mod = 998244353;\n\
    const ll MOD = 1000000007;\nconst ld EPS = 1e-9;\nconst ld PI = acos(-1);\n\n\
    void IO() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n// poe\n#line 3 \"math/prime.hpp\"\nusing namespace std;\n\
    // \u7D20\u6570\u5224\u5B9A O(log n)\nbool isprime(long long n) {\n    if (n <=\
    \ 1) return false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n\
    \    int flag = 1;\n    if (n < 4759123141LL) flag = 0;\n    vector<vector<long\
    \ long>> tests = {{2, 7, 61}, {2, 325, 9375, 28178, 450775, 9780504, 1795265022}};\n\
    \    long long s = 0, d = n - 1;\n    while (d % 2 == 0) {\n        ++s;\n   \
    \     d >>= 1;\n    }\n    for (auto a : tests[flag]) {\n        if (n <= a) return\
    \ true;\n        __int128_t x = 1, a2=a%n, d2 = d;\n        while (d2) {\n   \
    \         if (d2 & 1) x = x * a2 % n;\n            a2 = a2 * a2 % n;\n       \
    \     d2 >>= 1;\n        }\n        if (x != 1) {\n            long long t;\n\
    \            for (t = 0; t < s; ++t) {\n                if (x == n - 1) break;\n\
    \                x = x * x % n;\n            }\n            if (t == s) return\
    \ false;\n        }\n    }\n    return true;\n}\n// n \u4EE5\u4E0B\u306E\u7D20\
    \u6570\u3092\u5217\u6319\u3059\u308B O(n log log n)\nvector<int> enumprimes(long\
    \ long n) {\n    vector<char> primeflag(n+1);\n    vector<int> re;\n    for (long\
    \ long i=2; i<=n; i++) {\n        if (primeflag[i]) continue;\n        re.push_back(i);\n\
    \        for (long long j=i*i; j<=n; j+=i) {\n            primeflag[j] = true;\n\
    \        }\n    }\n    return re;\n}\nvoid inner_factorize(long long n, vector<long\
    \ long>& factors) {\n    if (n <= 1) return;\n    if (isprime(n)) {\n        factors.push_back(n);\n\
    \        return;\n    }\n    if (n % 2 == 0) {\n        while (n % 2 == 0) {\n\
    \            factors.push_back(2);\n            n /= 2;\n        }\n        inner_factorize(n,\
    \ factors);\n        return;\n    }\n    while (true) {\n        __int128_t x\
    \ = rand() % (n - 2) + 2;\n        __int128_t y = x;\n        __int128_t c = rand()\
    \ % (n - 1) + 1;\n        __int128_t m = 1;\n        while (m == 1) {\n      \
    \      x = (x * x + c) % n;\n            y = (y * y + c) % n;\n            y =\
    \ (y * y + c) % n;\n            m = gcd((long long)(x - y + n), n);\n        \
    \    if (m == n) break;\n        }\n        if (m != n) {\n            inner_factorize(m,\
    \ factors);\n            inner_factorize(n / m, factors);\n            return;\n\
    \        }\n    }\n}\n// \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3059\u308B O(n^0.25)\n\
    vector<long long> factorize(long long n) {\n    vector<long long> re;\n    inner_factorize(n,\
    \ re);\n    sort(re.begin(), re.end());\n    return re;\n}\n#line 5 \"verify/yosupo-factorize.test.cpp\"\
    \n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int q; cin >> q;\r\n    while (q--)\
    \ {\r\n        ll x; cin >> x;\r\n        auto y = factorize(x);\r\n        cout\
    \ << y.size() << sp << y;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ \"template\"\r\n#include \"prime\"\r\n\r\nint main() { IO();\r\n    int T=1;\r\
    \n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid solve() {\r\n\
    \    int q; cin >> q;\r\n    while (q--) {\r\n        ll x; cin >> x;\r\n    \
    \    auto y = factorize(x);\r\n        cout << y.size() << sp << y;\r\n    }\r\
    \n}"
  dependsOn:
  - util/template.hpp
  - math/prime.hpp
  isVerificationFile: true
  path: verify/yosupo-factorize.test.cpp
  requiredBy: []
  timestamp: '2025-11-27 00:46:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-factorize.test.cpp
- /verify/verify/yosupo-factorize.test.cpp.html
title: verify/yosupo-factorize.test.cpp
---
