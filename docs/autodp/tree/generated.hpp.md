---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"autodp/tree/generated.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class VTYPE>\nvector<VTYPE> solvedp(const vector<vector<int>>&\
    \ g, int r) {\n\tvector<vector<VTYPE>>matA={{-500000001,-499999998},{500000003,500000002}};\n\
    \tvector<vector<vector<VTYPE>>>tsrM={{{0,-2},{-2,-6}},{{1,3},{3,7}}};\n\tvector<VTYPE>vecQ={2,4};\n\
    \tint R = ((int)(matA).size());\n\tint n = ((int)(g).size());\n\tvector<vector<VTYPE>>\
    \ dp(n, vector<VTYPE>(R));\n\tfor(int s = 0, s_len = int(n); s < s_len; ++s) dp[s][0]\
    \ = 1;\n\tauto apply = [&](const vector<VTYPE>& x) {\n\t\tvector<VTYPE> z(R);\n\
    \t\tfor(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R);\
    \ j < j_len; ++j) z[i] += matA[i][j] * x[j];\n\t\treturn z;\n\t};\n\tauto merge\
    \ = [&](const vector<VTYPE>& x, const vector<VTYPE>& y) {\n\t\tvector<VTYPE> z(R);\n\
    \t\tfor(int k = 0, k_len = int(R); k < k_len; ++k) for(int i = 0, i_len = int(R);\
    \ i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[k] += x[i]\
    \ * tsrM[k][i][j] * y[j];\n\t\treturn z;\n\t};\n\tfunction<void(int, int)> dfs\
    \ = [&](int s, int p) {\n\t\tbool is_leaf = true;\n\t\tfor(const auto& t : (g[s]))\
    \ {\n\t\t\tif (t == p) continue;\n\t\t\tdfs(t, s);\n\t\t\tif (is_leaf) {\n\t\t\
    \t\tdp[s] = dp[t];\n\t\t\t}\n\t\t\telse {\n\t\t\t\tdp[s] = merge(dp[s], dp[t]);\n\
    \t\t\t}\n\t\t\tis_leaf = false;\n\t\t}\n\t\tif (!is_leaf) dp[s] = apply(dp[s]);\n\
    \t};\n\tdfs(r, -1);\n\tvector<VTYPE> res(n);\n\tfor(int s = 0, s_len = int(n);\
    \ s < s_len; ++s) {\n\t\tfor(int j = 0, j_len = int(R); j < j_len; ++j) res[s]\
    \ += vecQ[j] * dp[s][j];\n\t}\n\treturn res;\n}\n\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class VTYPE>\nvector<VTYPE> solvedp(const vector<vector<int>>& g, int r) {\n\
    \tvector<vector<VTYPE>>matA={{-500000001,-499999998},{500000003,500000002}};\n\
    \tvector<vector<vector<VTYPE>>>tsrM={{{0,-2},{-2,-6}},{{1,3},{3,7}}};\n\tvector<VTYPE>vecQ={2,4};\n\
    \tint R = ((int)(matA).size());\n\tint n = ((int)(g).size());\n\tvector<vector<VTYPE>>\
    \ dp(n, vector<VTYPE>(R));\n\tfor(int s = 0, s_len = int(n); s < s_len; ++s) dp[s][0]\
    \ = 1;\n\tauto apply = [&](const vector<VTYPE>& x) {\n\t\tvector<VTYPE> z(R);\n\
    \t\tfor(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R);\
    \ j < j_len; ++j) z[i] += matA[i][j] * x[j];\n\t\treturn z;\n\t};\n\tauto merge\
    \ = [&](const vector<VTYPE>& x, const vector<VTYPE>& y) {\n\t\tvector<VTYPE> z(R);\n\
    \t\tfor(int k = 0, k_len = int(R); k < k_len; ++k) for(int i = 0, i_len = int(R);\
    \ i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) z[k] += x[i]\
    \ * tsrM[k][i][j] * y[j];\n\t\treturn z;\n\t};\n\tfunction<void(int, int)> dfs\
    \ = [&](int s, int p) {\n\t\tbool is_leaf = true;\n\t\tfor(const auto& t : (g[s]))\
    \ {\n\t\t\tif (t == p) continue;\n\t\t\tdfs(t, s);\n\t\t\tif (is_leaf) {\n\t\t\
    \t\tdp[s] = dp[t];\n\t\t\t}\n\t\t\telse {\n\t\t\t\tdp[s] = merge(dp[s], dp[t]);\n\
    \t\t\t}\n\t\t\tis_leaf = false;\n\t\t}\n\t\tif (!is_leaf) dp[s] = apply(dp[s]);\n\
    \t};\n\tdfs(r, -1);\n\tvector<VTYPE> res(n);\n\tfor(int s = 0, s_len = int(n);\
    \ s < s_len; ++s) {\n\t\tfor(int j = 0, j_len = int(R); j < j_len; ++j) res[s]\
    \ += vecQ[j] * dp[s][j];\n\t}\n\treturn res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: autodp/tree/generated.hpp
  requiredBy: []
  timestamp: '2025-11-07 21:48:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: autodp/tree/generated.hpp
layout: document
redirect_from:
- /library/autodp/tree/generated.hpp
- /library/autodp/tree/generated.hpp.html
title: autodp/tree/generated.hpp
---
