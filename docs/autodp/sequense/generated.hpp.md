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
  bundledCode: "#line 2 \"autodp/sequense/generated.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class VTYPE>\nVTYPE solvedp(const vector<VTYPE>&\
    \ wgt) {\n\tconstexpr int DIM = 11;\n\tconstexpr int COL = 2;\n\tVTYPE matAs[COL][DIM][DIM]\
    \ = {{{0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0},{0,-100,100,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,1},{0,-111100,111100,100,-100,-90,100,-10,91,-100,10},{0,0,0,0,0,0,0,0,0,0,0},{0,299473316,-299473316,0,0,-299473305,0,299473305,-1,0,1},{0,399196731,-399196731,299473406,-299473406,-469174937,299473406,169701531,90,-100,10}},{{0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0},{0,-100,100,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,-1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,-1,1,1},{0,-111100,111100,100,-100,-90,100,-10,90,-99,10},{0,1,-1,-1,1,1,-1,0,-1,1,0},{0,299473317,-299473317,-1,1,-299473304,-1,299473305,-2,1,1},{0,399196732,-399196732,299473405,-299473405,-469174936,299473405,169701531,89,-99,10}}};\n\
    \tVTYPE vecQ[DIM] = {0,0,100,0,1100,0,1010,110100,0,10,101100};\n\tarray<VTYPE,\
    \ DIM> dp;\n\tdp[0] = 1;\n\tfor (int i=1; i<DIM; i++) dp[i] = 0;\n\tarray<VTYPE,\
    \ COL> fact_inv;\n\tfact_inv[0] = 1;\n\tfor (int i=1; i<COL; i++) fact_inv[i]\
    \ = fact_inv[i-1] / i;\n\tarray<VTYPE, COL> fixed;\n\tfor (int i=0; i<COL; i++)\
    \ fixed[i] = ((COL-1-i) & 1 ? -1 : 1) * fact_inv[i] * fact_inv[COL-1-i];\n\tarray<VTYPE,\
    \ COL> acc_l, acc_r;\n\tauto lagrange_interpolation = [&](const array<VTYPE, COL>&\
    \ y, VTYPE c) {\n\t\tacc_l[0] = 1;\n\t\tfor (int i=1; i<COL; i++) acc_l[i] = acc_l[i\
    \ - 1] * (c - (i - 1));\n\t\tacc_r[COL - 1] = 1;\n\t\tfor (int i=COL-2; 0<=i;\
    \ i--) acc_r[i] = (c - (i + 1)) * acc_r[i + 1];\n\t\tVTYPE res = 0;\n\t\tfor (int\
    \ i=0; i<COL; i++) res += y[i] * acc_l[i] * acc_r[i] * fixed[i];\n\t\treturn res;\n\
    \t};\n\tauto apply = [&](const array<VTYPE, DIM>& x, VTYPE w) {\n\t\tarray<VTYPE,\
    \ DIM> z;\n\t\tfor (int j=0; j<DIM; j++) {\n\t\t\tz[j] = 0;\n\t\t\tfor (int i=0;\
    \ i<DIM; i++) {\n\t\t\t\tarray<VTYPE, COL> ys;\n\t\t\t\tfor (int c=0; c<COL; c++)\
    \ ys[c] = matAs[c][i][j];\n\t\t\t\tz[j] += x[i] * lagrange_interpolation(ys, w);\n\
    \t\t\t}\n\t\t}\n\t\treturn z;\n\t};\n\tfor (const auto& w : wgt) dp = apply(dp,\
    \ w);\n\tVTYPE res = 0;\n\tfor (int i=0; i<DIM; i++) res += vecQ[i] * dp[i];\n\
    \treturn res;\n}\n\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class VTYPE>\nVTYPE solvedp(const vector<VTYPE>& wgt) {\n\tconstexpr int DIM\
    \ = 11;\n\tconstexpr int COL = 2;\n\tVTYPE matAs[COL][DIM][DIM] = {{{0,1,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0},{0,-100,100,1,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,1},{0,-111100,111100,100,-100,-90,100,-10,91,-100,10},{0,0,0,0,0,0,0,0,0,0,0},{0,299473316,-299473316,0,0,-299473305,0,299473305,-1,0,1},{0,399196731,-399196731,299473406,-299473406,-469174937,299473406,169701531,90,-100,10}},{{0,0,1,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,0,0,0},{0,-100,100,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0},{0,0,0,0,0,-1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,-1,1,1},{0,-111100,111100,100,-100,-90,100,-10,90,-99,10},{0,1,-1,-1,1,1,-1,0,-1,1,0},{0,299473317,-299473317,-1,1,-299473304,-1,299473305,-2,1,1},{0,399196732,-399196732,299473405,-299473405,-469174936,299473405,169701531,89,-99,10}}};\n\
    \tVTYPE vecQ[DIM] = {0,0,100,0,1100,0,1010,110100,0,10,101100};\n\tarray<VTYPE,\
    \ DIM> dp;\n\tdp[0] = 1;\n\tfor (int i=1; i<DIM; i++) dp[i] = 0;\n\tarray<VTYPE,\
    \ COL> fact_inv;\n\tfact_inv[0] = 1;\n\tfor (int i=1; i<COL; i++) fact_inv[i]\
    \ = fact_inv[i-1] / i;\n\tarray<VTYPE, COL> fixed;\n\tfor (int i=0; i<COL; i++)\
    \ fixed[i] = ((COL-1-i) & 1 ? -1 : 1) * fact_inv[i] * fact_inv[COL-1-i];\n\tarray<VTYPE,\
    \ COL> acc_l, acc_r;\n\tauto lagrange_interpolation = [&](const array<VTYPE, COL>&\
    \ y, VTYPE c) {\n\t\tacc_l[0] = 1;\n\t\tfor (int i=1; i<COL; i++) acc_l[i] = acc_l[i\
    \ - 1] * (c - (i - 1));\n\t\tacc_r[COL - 1] = 1;\n\t\tfor (int i=COL-2; 0<=i;\
    \ i--) acc_r[i] = (c - (i + 1)) * acc_r[i + 1];\n\t\tVTYPE res = 0;\n\t\tfor (int\
    \ i=0; i<COL; i++) res += y[i] * acc_l[i] * acc_r[i] * fixed[i];\n\t\treturn res;\n\
    \t};\n\tauto apply = [&](const array<VTYPE, DIM>& x, VTYPE w) {\n\t\tarray<VTYPE,\
    \ DIM> z;\n\t\tfor (int j=0; j<DIM; j++) {\n\t\t\tz[j] = 0;\n\t\t\tfor (int i=0;\
    \ i<DIM; i++) {\n\t\t\t\tarray<VTYPE, COL> ys;\n\t\t\t\tfor (int c=0; c<COL; c++)\
    \ ys[c] = matAs[c][i][j];\n\t\t\t\tz[j] += x[i] * lagrange_interpolation(ys, w);\n\
    \t\t\t}\n\t\t}\n\t\treturn z;\n\t};\n\tfor (const auto& w : wgt) dp = apply(dp,\
    \ w);\n\tVTYPE res = 0;\n\tfor (int i=0; i<DIM; i++) res += vecQ[i] * dp[i];\n\
    \treturn res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: autodp/sequense/generated.hpp
  requiredBy: []
  timestamp: '2025-11-08 14:19:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: autodp/sequense/generated.hpp
layout: document
redirect_from:
- /library/autodp/sequense/generated.hpp
- /library/autodp/sequense/generated.hpp.html
title: autodp/sequense/generated.hpp
---
