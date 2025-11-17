---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  - icon: ':x:'
    path: graph/warshallfloyd.hpp
    title: graph/warshallfloyd.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
  bundledCode: "#line 1 \"verify/aizu-GRL_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja\"\
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
    // poe\n#line 3 \"graph/graphtemplate.hpp\"\nusing namespace std;\n// \u8FBA\u306E\
    \u69CB\u9020\u4F53 edge(from, to, cost, id)\ntemplate<class T = int>\nstruct edge\
    \ {\n    int from, to;\n    T cost;\n    int id;\n};\n// \u9802\u70B9\u306E\u69CB\
    \u9020\u4F53 vector<edge<T>>\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\n\
    // \u30B0\u30E9\u30D5\u306E\u69CB\u9020\u4F53 graph<T, directed, weighted> \n\
    template <class T = int, bool directed = false, bool weighted = false>\nstruct\
    \ graph {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>>\
    \ data;\n    T sumcost;\n    graph() = default;\n    // \u9802\u70B9\u6570 n \u306E\
    \u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\n    graph(int n) : isdirected(directed),\
    \ isweighted(weighted), data(n), sumcost(T{}) {}\n    // from \u304B\u3089 to\
    \ \u3078\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void add_edge(int from, int\
    \ to, T cost = 1, int id = -1) {\n        if (id == -1) id = _edges.size();\n\
    \        data[from].push_back(edge<T>{from, to, cost, id});\n        _edges.push_back(edge<T>{from,\
    \ to, cost, id});\n        if (!isdirected) {\n            data[to].push_back(edge<T>{to,\
    \ from, cost, id});\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\
    \u3092\u8FFD\u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n    // \u30D1\u30B9\u3092\u9802\u70B9\u306B\
    \u5909\u63DB\u3059\u308B\n    vector<int> path_to_vertex(edges<T>& _e) {\n   \
    \     vector<int> re;\n        if (_e.size() == 0) {\n            return re;\n\
    \        }\n        if (_e.size() == 1) {\n            re.push_back(_e[0].from);\n\
    \            re.push_back(_e[0].to);\n            return re;\n        }\n    \
    \    int x=_e[0].from,y=_e[0].to;\n        if (x==_e[1].to || x == _e[1].from)\
    \ swap(x, y);\n        re.push_back(x);\n        for (int i=1; i<_e.size(); i++)\
    \ {\n            re.push_back(y);\n            x = _e[i].to;\n            if (x\
    \ == y) x = _e[i].from;\n            swap(x, y);\n        }\n        return re;\n\
    \    }\n    // \u9802\u70B9\u3092\u30D1\u30B9\u306B\u5909\u63DB\u3059\u308B\n\
    \    edges<T> vetex_to_path (vector<int>& v){\n        edges<T> re;\n        for\
    \ (int i=0; i+1<v.size(); i++) {\n            for (auto& _e : this[v[i]]) {\n\
    \                if (_e.to == v[i+1]) {\n                    re.push_back(_e);\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return re;\n    }\n};\n#line 4 \"graph/warshallfloyd.hpp\"\nusing namespace\
    \ std;\n// \u30B0\u30E9\u30D5\u306E\u5168\u70B9\u9593\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u6C42\u3081\u308B O(n^3)\ntemplate <class T>\nvector<vector<T>> warshallfloyd(vector<vector<T>>&\
    \ g) {\n    vector<vector<T>> d = g;\n    for (int k=0; k<(int)g.size(); k++)\
    \ {\n        for (int i=0; i<(int)g.size(); i++) {\n            for (int j=0;\
    \ j<(int)g.size(); j++) {\n                if (d[i][k] != numeric_limits<T>::max()\
    \ && d[k][j] != numeric_limits<T>::max()) {\n                    d[i][j] = min(d[i][j],\
    \ d[i][k] + d[k][j]);\n                }\n            }\n        }\n    }\n  \
    \  return d;\n}\n// \u30B0\u30E9\u30D5\u306E\u5168\u70B9\u9593\u6700\u77ED\u7D4C\
    \u8DEF\u3092\u6C42\u3081\u308B O(n^3)\ntemplate<class T = int, bool directed =\
    \ false, bool weighted = true>\nvector<vector<T>> warshallfloyd(graph<T, directed,\
    \ weighted>& g) {\n    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    for (int i=0; i<(int)g.size(); i++) {\n        d[i][i] = T{};\n        for\
    \ (auto& _e : g[i]) {\n            d[i][_e.to] = _e.cost;\n        }\n    }\n\
    \    return warshallfloyd(d);\n}\n#line 5 \"verify/aizu-GRL_1_C.test.cpp\"\n\r\
    \nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<ll, true,\
    \ true> g(n);\r\n    g.read(m, 0);\r\n    vvll d = warshallfloyd(g);\r\n    rep(i,\
    \ n) if (d[i][i] < 0) {\r\n        cout << \"NEGATIVE CYCLE\" << nl;\r\n     \
    \   return;\r\n    }\r\n    rep(i, n) {\r\n        rep(j, n) {\r\n           \
    \ if (d[i][j] == numeric_limits<ll>::max()) {\r\n                cout << \"INF\"\
    ;\r\n            } else {\r\n                cout << d[i][j];\r\n            }\r\
    \n            if (j != n - 1) cout << sp;\r\n        }\r\n        cout << nl;\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja\"\
    \r\n#include \"template\"\r\n#include \"graphtemplate\"\r\n#include \"warshallfloyd\"\
    \r\n\r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<ll,\
    \ true, true> g(n);\r\n    g.read(m, 0);\r\n    vvll d = warshallfloyd(g);\r\n\
    \    rep(i, n) if (d[i][i] < 0) {\r\n        cout << \"NEGATIVE CYCLE\" << nl;\r\
    \n        return;\r\n    }\r\n    rep(i, n) {\r\n        rep(j, n) {\r\n     \
    \       if (d[i][j] == numeric_limits<ll>::max()) {\r\n                cout <<\
    \ \"INF\";\r\n            } else {\r\n                cout << d[i][j];\r\n   \
    \         }\r\n            if (j != n - 1) cout << sp;\r\n        }\r\n      \
    \  cout << nl;\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - graph/graphtemplate.hpp
  - graph/warshallfloyd.hpp
  isVerificationFile: true
  path: verify/aizu-GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:24:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu-GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu-GRL_1_C.test.cpp
- /verify/verify/aizu-GRL_1_C.test.cpp.html
title: verify/aizu-GRL_1_C.test.cpp
---
