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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/mackerel38/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/mackerel38/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/mackerel38/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/mackerel38/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"\
    autodp/matrix.hpp\"\n#include \"atcoder/modint\"\nusing namespace atcoder;\n\n\
    template <class CTYPE, auto NAIVE>\nvoid embed_coefs() {\n\tvector<vector<int>>\
    \ trees{ {0} };\n\tint idx = 0;\n\tvector<pair<int, int>> piv_prv;\n\tfor(int\
    \ lv = int(2), lv_end = int(1001001001); lv <= lv_end; ++lv) {\n\t\tint L = ((int)(trees).size());\n\
    \t\tMatrix<CTYPE> mat(L, L);\n\t\tfor(int i = 0, i_len = int(L); i < i_len; ++i)\
    \ for(int j = 0, j_len = int(L); j < j_len; ++j) {\n\t\t\tvector<int> tree(trees[i]);\n\
    \t\t\tint p0 = tree.back();\n\t\t\ttree.pop_back();\n\t\t\tint offset = ((int)(tree).size());\n\
    \t\t\tfor(const auto& p : (trees[j])) {\n\t\t\t\tint np = (p == 0 ? p0 : p + offset);\n\
    \t\t\t\ttree.push_back(np);\n\t\t\t}\n\t\t\tmat[i][j] = NAIVE(tree);\n\t\t}\n\t\
    \tauto piv = row_reduced_form(mat);\n\t\tif (lv > 2 && ((int)(piv).size()) ==\
    \ ((int)(piv_prv).size())) {\n\t\t\tint R = ((int)(piv).size());\n\t\t\tvector<int>\
    \ is(R), js(R);\n\t\t\tfor(int r = 0, r_len = int(R); r < r_len; ++r) tie(is[r],\
    \ js[r]) = piv[r];\n\t\t\tsort((js).begin(), (js).end());\n\t\t\tMatrix<CTYPE>\
    \ P(R, R);\n\t\t\tfor(int i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0,\
    \ j_len = int(R); j < j_len; ++j) {\n\t\t\t\tvector<int> tree(trees[is[i]]);\n\
    \t\t\t\tint p0 = tree.back();\n\t\t\t\ttree.pop_back();\n\t\t\t\tint offset =\
    \ ((int)(tree).size());\n\t\t\t\tfor(const auto& p : (trees[js[j]])) {\n\t\t\t\
    \t\tint np = (p == 0 ? p0 : p + offset);\n\t\t\t\t\ttree.push_back(np);\n\t\t\t\
    \t}\n\t\t\t\tP[i][j] = NAIVE(tree);\n\t\t\t}\n\t\t\tauto P_inv = inverse_matrix(P);\n\
    \t\t\tMatrix<CTYPE> apply(R, R);\n\t\t\tfor(int i = 0, i_len = int(R); i < i_len;\
    \ ++i) for(int j = 0, j_len = int(R); j < j_len; ++j) {\n\t\t\t\tvector<int> tree(trees[is[i]]);\n\
    \t\t\t\tint offset = ((int)(tree).size());\n\t\t\t\tfor(const auto& p : (trees[js[j]]))\
    \ {\n\t\t\t\t\tint np = p + offset;\n\t\t\t\t\ttree.push_back(np);\n\t\t\t\t}\n\
    \t\t\t\tapply[i][j] = NAIVE(tree);\n\t\t\t}\n\t\t\tapply = P_inv * apply;\n\t\t\
    \tvector<vector<vector<CTYPE>>> merge(R, vector<vector<CTYPE>>(R, vector<CTYPE>(R)));\n\
    \t\t\tfor(int j1 = 0, j1_len = int(R); j1 < j1_len; ++j1) for(int j2 = 0, j2_len\
    \ = int(R); j2 < j2_len; ++j2) {\n\t\t\t\tfor(int i = 0, i_len = int(R); i < i_len;\
    \ ++i) {\n\t\t\t\t\tvector<int> tree(trees[is[i]]);\n\t\t\t\t\tint p0 = tree.back();\n\
    \t\t\t\t\ttree.pop_back();\n\t\t\t\t\tint offset = ((int)(tree).size());\n\t\t\
    \t\t\tfor(const auto& p : (trees[js[j1]])) {\n\t\t\t\t\t\tint np = (p == 0 ? p0\
    \ : p + offset);\n\t\t\t\t\t\ttree.push_back(np);\n\t\t\t\t\t}\n\t\t\t\t\toffset\
    \ = ((int)(tree).size());\n\t\t\t\t\tfor(const auto& p : (trees[js[j2]])) {\n\t\
    \t\t\t\t\tint np = (p == 0 ? p0 : p + offset);\n\t\t\t\t\t\ttree.push_back(np);\n\
    \t\t\t\t\t}\n\t\t\t\t\tmerge[j1][j2][i] = NAIVE(tree);\n\t\t\t\t}\n\t\t\t\tmerge[j1][j2]\
    \ = P_inv * merge[j1][j2];\n\t\t\t}\n\t\t\tauto to_signed_string = [](CTYPE x)\
    \ {\n\t\t\t\tint v = x.val();\n\t\t\t\tint mod = CTYPE::mod();\n\t\t\t\tif (2\
    \ * v > mod) v -= mod;\n\t\t\t\treturn to_string(v);\n\t\t\t};\n            ofstream\
    \ ofs(\"/home/mackerel38/competitive/library/autodp/tree/generated.hpp\");\n\t\
    \t\tstring eb = \"#pragma once\\n#include <bits/stdc++.h>\\nusing namespace std;\\\
    n\\ntemplate <class VTYPE>\\nvector<VTYPE> solvedp(const vector<vector<int>>&\
    \ g, int r) {\\n\\tvector<vector<VTYPE>>matA={\";\n\t\t\tfor(int i = 0, i_len\
    \ = int(R); i < i_len; ++i) {\n\t\t\t\teb += \"{\";\n\t\t\t\tfor(int j = 0, j_len\
    \ = int(R); j < j_len; ++j) eb += to_signed_string(apply[i][j]) + \",\";\n\t\t\
    \t\teb.pop_back();\n\t\t\t\teb += \"},\";\n\t\t\t}\n\t\t\teb.pop_back();\n\t\t\
    \teb += \"};\\n\\tvector<vector<vector<VTYPE>>>tsrM={\";\n\t\t\tfor(int i = 0,\
    \ i_len = int(R); i < i_len; ++i) {\n\t\t\t\teb += \"{\";\n\t\t\t\tfor(int j1\
    \ = 0, j1_len = int(R); j1 < j1_len; ++j1) {\n\t\t\t\t\teb += \"{\";\n\t\t\t\t\
    \tfor(int j2 = 0, j2_len = int(R); j2 < j2_len; ++j2) eb += to_signed_string(merge[j1][j2][i])\
    \ + \",\";\n\t\t\t\t\teb.pop_back();\n\t\t\t\t\teb += \"},\";\n\t\t\t\t}\n\t\t\
    \t\teb.pop_back();\n\t\t\t\teb += \"},\";\n\t\t\t}\n\t\t\teb.pop_back();\n\t\t\
    \teb += \"};\\n\\tvector<VTYPE>vecQ={\";\n\t\t\tfor(int j = 0, j_len = int(R);\
    \ j < j_len; ++j) eb += to_signed_string(P[0][j]) + \",\";\n\t\t\teb.pop_back();\n\
    \t\t\teb += \"};\\n\";\n            eb += \"\\tint R = ((int)(matA).size());\\\
    n\\tint n = ((int)(g).size());\\n\\tvector<vector<VTYPE>> dp(n, vector<VTYPE>(R));\\\
    n\\tfor(int s = 0, s_len = int(n); s < s_len; ++s) dp[s][0] = 1;\\n\\tauto apply\
    \ = [&](const vector<VTYPE>& x) {\\n\\t\\tvector<VTYPE> z(R);\\n\\t\\tfor(int\
    \ i = 0, i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len;\
    \ ++j) z[i] += matA[i][j] * x[j];\\n\\t\\treturn z;\\n\\t};\\n\\tauto merge =\
    \ [&](const vector<VTYPE>& x, const vector<VTYPE>& y) {\\n\\t\\tvector<VTYPE>\
    \ z(R);\\n\\t\\tfor(int k = 0, k_len = int(R); k < k_len; ++k) for(int i = 0,\
    \ i_len = int(R); i < i_len; ++i) for(int j = 0, j_len = int(R); j < j_len; ++j)\
    \ z[k] += x[i] * tsrM[k][i][j] * y[j];\\n\\t\\treturn z;\\n\\t};\\n\\tfunction<void(int,\
    \ int)> dfs = [&](int s, int p) {\\n\\t\\tbool is_leaf = true;\\n\\t\\tfor(const\
    \ auto& t : (g[s])) {\\n\\t\\t\\tif (t == p) continue;\\n\\t\\t\\tdfs(t, s);\\\
    n\\t\\t\\tif (is_leaf) {\\n\\t\\t\\t\\tdp[s] = dp[t];\\n\\t\\t\\t}\\n\\t\\t\\\
    telse {\\n\\t\\t\\t\\tdp[s] = merge(dp[s], dp[t]);\\n\\t\\t\\t}\\n\\t\\t\\tis_leaf\
    \ = false;\\n\\t\\t}\\n\\t\\tif (!is_leaf) dp[s] = apply(dp[s]);\\n\\t};\\n\\\
    tdfs(r, -1);\\n\\tvector<VTYPE> res(n);\\n\\tfor(int s = 0, s_len = int(n); s\
    \ < s_len; ++s) {\\n\\t\\tfor(int j = 0, j_len = int(R); j < j_len; ++j) res[s]\
    \ += vecQ[j] * dp[s][j];\\n\\t}\\n\\treturn res;\\n}\\n\";\n\t\t\tofs << eb <<\
    \ endl;\n\t\t\texit(0);\n\t\t}\n\t\tint nidx = ((int)(trees).size());\n\t\tfor(int\
    \ i = int(idx), i_end = int(nidx - 1); i <= i_end; ++i) for(int p = 0, p_len =\
    \ int(lv); p < p_len; ++p) {\n\t\t\ttrees.push_back(trees[i]);\n\t\t\ttrees.back().push_back(p);\n\
    \t\t}\n\t\tidx = nidx;\n\t\tpiv_prv = move(piv);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: autodp/tree/construct.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: autodp/tree/construct.hpp
layout: document
redirect_from:
- /library/autodp/tree/construct.hpp
- /library/autodp/tree/construct.hpp.html
title: autodp/tree/construct.hpp
---
