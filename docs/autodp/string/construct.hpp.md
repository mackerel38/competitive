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
    template <class CTYPE, auto NAIVE>\nvoid embed_coefs(int K, int len_max=1001001001,\
    \ int lb_max=1001001001)\n{\n\tif (len_max == -1) len_max = 1001001001;\n\tif\
    \ (lb_max == -1) lb_max = 1001001001;\n\tvector<string> ss{\"\"};\n\tint idx =\
    \ 0;\n\tvector<pair<int, int>> piv_prv;\n\tfor (int len = int(0), len_end = int(1001001001);\
    \ len <= len_end; ++len)\n\t{\n\t\tint L = ((int)(ss).size());\n\t\tint LB = min(L,\
    \ lb_max);\n\t\tMatrix<CTYPE> mat(L, LB);\n\t\tfor (int i = 0, i_len = int(L);\
    \ i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(LB); j < j_len; ++j)\n\t\t\
    \t\tmat[i][j] = NAIVE(ss[i] + ss[j]);\n\t\tauto piv = row_reduced_form(mat);\n\
    \t\tif (len == len_max || (((int)(piv).size()) > 0 && ((int)(piv).size()) == ((int)(piv_prv).size())))\n\
    \t\t{\n\t\t\tint R = ((int)(piv).size());\n\t\t\tvector<int> is(R), js(R);\n\t\
    \t\tfor (int r = 0, r_len = int(R); r < r_len; ++r)\n\t\t\t\ttie(is[r], js[r])\
    \ = piv[r];\n\t\t\tsort((js).begin(), (js).end());\n\t\t\tMatrix<CTYPE> P(R, R);\n\
    \t\t\tfor (int i = 0, i_len = int(R); i < i_len; ++i)\n\t\t\t\tfor (int j = 0,\
    \ j_len = int(R); j < j_len; ++j)\n\t\t\t\t\tP[i][j] = NAIVE(ss[is[i]] + ss[js[j]]);\n\
    \t\t\tauto P_inv = inverse_matrix(P);\n\t\t\tvector<Matrix<CTYPE>> mats(K, Matrix<CTYPE>(R,\
    \ R));\n\t\t\tfor (int k = 0, k_len = int(K); k < k_len; ++k)\n\t\t\t{\n\t\t\t\
    \tchar c = '0' + k;\n\t\t\t\tfor (int i = 0, i_len = int(R); i < i_len; ++i)\n\
    \t\t\t\t\tfor (int j = 0, j_len = int(R); j < j_len; ++j)\n\t\t\t\t\t\tmats[k][i][j]\
    \ = NAIVE(ss[is[i]] + c + ss[js[j]]);\n\t\t\t\tmats[k] = mats[k] * P_inv;\n\t\t\
    \t}\n\t\t\tauto to_signed_string = [](CTYPE x)\n\t\t\t{\n\t\t\t\tint v = x.val();\n\
    \t\t\t\tint mod = CTYPE::mod();\n\t\t\t\tif (2 * v > mod)\n\t\t\t\t\tv -= mod;\n\
    \t\t\t\treturn to_string(v);\n\t\t\t};\n\t\t\tofstream ofs(\"/home/mackerel38/competitive/library/autodp/string/generated.hpp\"\
    );\n\t\t\tstring eb = \"\";\n\t\t\teb += \"#pragma once\\n\";\n\t\t\teb += \"\
    #include <bits/stdc++.h>\\n\";\n\t\t\teb += \"using namespace std;\\n\";\n\t\t\
    \teb += \"\\n\";\n\t\t\teb += \"template <class VTYPE>\\n\";\n\t\t\teb += \"VTYPE\
    \ solvedp(const string &s) {\\n\";\n\t\t\teb += \"\\tconstexpr int DIM = \";\n\
    \t\t\teb += to_string(R);\n\t\t\teb += \";\\n\";\n\t\t\teb += \"\\tconstexpr int\
    \ COL = \";\n\t\t\teb += to_string(K);\n\t\t\teb += \";\\n\";\n\t\t\teb += \"\\\
    tVTYPE matAs[COL][DIM][DIM] = {\";\n\t\t\tfor (int k = 0, k_len = int(K); k <\
    \ k_len; ++k)\n\t\t\t{\n\t\t\t\teb += \"{\";\n\t\t\t\tfor (int i = 0, i_len =\
    \ int(R); i < i_len; ++i)\n\t\t\t\t{\n\t\t\t\t\teb += \"{\";\n\t\t\t\t\tfor (int\
    \ j = 0, j_len = int(R); j < j_len; ++j)\n\t\t\t\t\t\teb += to_signed_string(mats[k][i][j])\
    \ + \",\";\n\t\t\t\t\teb.pop_back();\n\t\t\t\t\teb += \"},\";\n\t\t\t\t}\n\t\t\
    \t\teb.pop_back();\n\t\t\t\teb += \"},\";\n\t\t\t}\n\t\t\teb.pop_back();\n\t\t\
    \teb += \"};\\n\";\n\t\t\teb += \"\\tVTYPE vecQ[DIM] = {\";\n\t\t\tfor (int i\
    \ = 0, i_len = int(R); i < i_len; ++i)\n\t\t\t\teb += to_signed_string(P[i][0])\
    \ + \",\";\n\t\t\teb.pop_back();\n\t\t\teb += \"};\\n\";\n\t\t\teb += \"\\tarray<VTYPE,\
    \ DIM> dp;\\n\";\n\t\t\teb += \"\\tdp[0] = 1;\\n\";\n\t\t\teb += \"\\tfor (int\
    \ i=1; i<DIM; i++) dp[i] = 0;\\n\";\n\t\t\teb += \"\\tauto apply = [&](const array<VTYPE,\
    \ DIM> &x, int col) {\\n\";\n\t\t\teb += \"\\t\\tarray<VTYPE, DIM> z;\\n\";\n\t\
    \t\teb += \"\\t\\tfor (int j=0; j<DIM; j++) {\\n\";\n\t\t\teb += \"\\t\\t\\tz[j]\
    \ = 0;\\n\";\n\t\t\teb += \"\\t\\t\\tfor (int i=0; i<DIM; i++) z[j] += x[i]*matAs[col][i][j];\\\
    n\";\n\t\t\teb += \"\\t\\t}\\n\";\n\t\t\teb += \"\\t\\treturn z;\\n\";\n\t\t\t\
    eb += \"\\t};\\n\";\n\t\t\teb += \"\\tfor (const auto &c : s) dp = apply(dp, c-'0');\\\
    n\";\n\t\t\teb += \"\\tVTYPE res = 0;\\n\";\n\t\t\teb += \"\\tfor (int i=0; i<DIM;\
    \ i++) res += vecQ[i]*dp[i];\\n\";\n\t\t\teb += \"\\treturn res;\\n\";\n\t\t\t\
    eb += \"}\\n\";\n\t\t\tofs << eb << endl;\n\t\t\texit(0);\n\t\t}\n\t\tint nidx\
    \ = ((int)(ss).size());\n\t\tfor (int i = int(idx), i_end = int(nidx - 1); i <=\
    \ i_end; ++i)\n\t\t\tfor (int k = 0, k_len = int(K); k < k_len; ++k)\n\t\t\t{\n\
    \t\t\t\tss.push_back(ss[i]);\n\t\t\t\tss.back().push_back('0' + k);\n\t\t\t}\n\
    \t\tidx = nidx;\n\t\tpiv_prv = move(piv);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: autodp/string/construct.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: autodp/string/construct.hpp
layout: document
redirect_from:
- /library/autodp/string/construct.hpp
- /library/autodp/string/construct.hpp.html
title: autodp/string/construct.hpp
---
