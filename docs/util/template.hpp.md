---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_1_A.test.cpp
    title: verify/aizu-DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_A.test.cpp
    title: verify/aizu-DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_B.test.cpp
    title: verify/aizu-DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_E.test.cpp
    title: verify/aizu-DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_A.test.cpp
    title: verify/aizu-GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_B.test.cpp
    title: verify/aizu-GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_C.test.cpp
    title: verify/aizu-GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_2_A.test.cpp
    title: verify/aizu-GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-bitwise_xor_convolution.test.cpp
    title: verify/yosupo-bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-factorize.test.cpp
    title: verify/yosupo-factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-minimum_steiner_tree.test.cpp
    title: verify/yosupo-minimum_steiner_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum.test.cpp
    title: verify/yosupo-point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum_2.test.cpp
    title: verify/yosupo-point_add_range_sum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo-point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite_large_array.test.cpp
    title: verify/yosupo-point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-predecessor_problem.test.cpp
    title: verify/yosupo-predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-primality_test.test.cpp
    title: verify/yosupo-primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_point_get.test.cpp
    title: verify/yosupo-range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo-range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-scc.test.cpp
    title: verify/yosupo-scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-shortest_path.test.cpp
    title: verify/yosupo-shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_inversions_query.test.cpp
    title: verify/yosupo-static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_sum.test.cpp
    title: verify/yosupo-static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-staticrmq.test.cpp
    title: verify/yosupo-staticrmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-unionfind.test.cpp
    title: verify/yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\"\
    : \"<<x<<endl\n#else\n#define debug(x)\n// #pragma GCC target(\"arch=skylake-avx512\"\
    )\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#endif\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\ntemplate<class\
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
    }\n\nvoid solve();\n// poe\n"
  code: "#pragma once\n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n#else\n\
    #define debug(x)\n// #pragma GCC target(\"arch=skylake-avx512\")\n// #pragma GCC\
    \ target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
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
    }\n\nvoid solve();\n// poe"
  dependsOn: []
  isVerificationFile: false
  path: util/template.hpp
  requiredBy:
  - main.cpp
  timestamp: '2025-06-18 08:29:31+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-minimum_steiner_tree.test.cpp
  - verify/yosupo-predecessor_problem.test.cpp
  - verify/aizu-DSL_2_E.test.cpp
  - verify/yosupo-shortest_path.test.cpp
  - verify/aizu-GRL_2_A.test.cpp
  - verify/yosupo-point_set_range_composite_large_array.test.cpp
  - verify/yosupo-range_affine_range_sum.test.cpp
  - verify/yosupo-staticrmq.test.cpp
  - verify/yosupo-factorize.test.cpp
  - verify/yosupo-point_add_range_sum.test.cpp
  - verify/aizu-GRL_1_C.test.cpp
  - verify/aizu-GRL_1_B.test.cpp
  - verify/yosupo-unionfind.test.cpp
  - verify/aizu-DSL_1_A.test.cpp
  - verify/yosupo-point_set_range_composite.test.cpp
  - verify/yosupo-static_range_inversions_query.test.cpp
  - verify/aizu-DSL_2_B.test.cpp
  - verify/aizu-GRL_1_A.test.cpp
  - verify/yosupo-point_add_range_sum_2.test.cpp
  - verify/yosupo-range_affine_point_get.test.cpp
  - verify/yosupo-bitwise_xor_convolution.test.cpp
  - verify/yosupo-primality_test.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
  - verify/yosupo-static_range_sum.test.cpp
  - verify/yosupo-scc.test.cpp
  - verify/aizu-DSL_2_A.test.cpp
documentation_of: util/template.hpp
layout: document
redirect_from:
- /library/util/template.hpp
- /library/util/template.hpp.html
title: util/template.hpp
---
