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
  bundledCode: "#line 2 \"autodp/matrix.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T>\nstruct Matrix\n{\n\tint n, m;\n\tvector<vector<T>>\
    \ v;\n\tMatrix(int n, int m) : n(n), m(m), v(n, vector<T>(m)) {}\n\tMatrix(int\
    \ n) : n(n), m(n), v(n, vector<T>(n))\n\t{\n\t\tfor (int i = 0, i_len = int(n);\
    \ i < i_len; ++i)\n\t\t\tv[i][i] = T(1);\n\t}\n\tMatrix(const vector<vector<T>>\
    \ &a) : n(((int)(a).size())), m(((int)(a[0]).size())), v(a) {}\n\tMatrix() : n(0),\
    \ m(0) {}\n\tMatrix(const Matrix &) = default;\n\tMatrix &operator=(const Matrix\
    \ &) = default;\n\tinline vector<T> const &operator[](int i) const { return v[i];\
    \ }\n\tinline vector<T> &operator[](int i)\n\t{\n\t\treturn v[i];\n\t}\n\tfriend\
    \ istream &operator>>(istream &is, Matrix &a)\n\t{\n\t\tfor (int i = 0, i_len\
    \ = int(a.n); i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(a.m); j < j_len;\
    \ ++j)\n\t\t\t\tis >> a.v[i][j];\n\t\treturn is;\n\t}\n\tvoid push_back(const\
    \ vector<T> &a)\n\t{\n\t\t{\n\t\t\tif (!(((int)(a).size()) == m))\n\t\t\t{\n\t\
    \t\t\tvector<char> MLE(1 << 30);\n\t\t\t\t{\n\t\t\t\t\tcout << (MLE.back()) <<\
    \ endl;\n\t\t\t\t\texit(0);\n\t\t\t\t};\n\t\t\t}\n\t\t};\n\t\tv.push_back(a);\n\
    \t\tn++;\n\t}\n\tvoid pop_back()\n\t{\n\t\t{\n\t\t\tif (!(n > 0))\n\t\t\t{\n\t\
    \t\t\tvector<char> MLE(1 << 30);\n\t\t\t\t{\n\t\t\t\t\tcout << (MLE.back()) <<\
    \ endl;\n\t\t\t\t\texit(0);\n\t\t\t\t};\n\t\t\t}\n\t\t};\n\t\tv.pop_back();\n\t\
    \tn--;\n\t}\n\tvoid resize(int n_)\n\t{\n\t\tv.resize(n_);\n\t\tn = n_;\n\t}\n\
    \tvoid resize(int n_, int m_)\n\t{\n\t\tn = n_;\n\t\tm = m_;\n\t\tv.resize(n);\n\
    \t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tv[i].resize(m);\n\t\
    }\n\tbool empty() const { return min(n, m) == 0; }\n\tbool operator==(const Matrix\
    \ &b) const { return n == b.n && m == b.m && v == b.v; }\n\tbool operator!=(const\
    \ Matrix &b) const { return !(*this == b); }\n\tMatrix &operator+=(const Matrix\
    \ &b)\n\t{\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tfor (int\
    \ j = 0, j_len = int(m); j < j_len; ++j)\n\t\t\t\tv[i][j] += b[i][j];\n\t\treturn\
    \ *this;\n\t}\n\tMatrix &operator-=(const Matrix &b)\n\t{\n\t\tfor (int i = 0,\
    \ i_len = int(n); i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(m); j < j_len;\
    \ ++j)\n\t\t\t\tv[i][j] -= b[i][j];\n\t\treturn *this;\n\t}\n\tMatrix &operator*=(const\
    \ T &c)\n\t{\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tfor (int\
    \ j = 0, j_len = int(m); j < j_len; ++j)\n\t\t\t\tv[i][j] *= c;\n\t\treturn *this;\n\
    \t}\n\tMatrix operator+(const Matrix &b) const { return Matrix(*this) += b; }\n\
    \tMatrix operator-(const Matrix &b) const { return Matrix(*this) -= b; }\n\tMatrix\
    \ operator*(const T &c) const { return Matrix(*this) *= c; }\n\tfriend Matrix\
    \ operator*(const T &c, const Matrix<T> &a) { return a * c; }\n\tMatrix operator-()\
    \ const { return Matrix(*this) *= T(-1); }\n\tvector<T> operator*(const vector<T>\
    \ &x) const\n\t{\n\t\tvector<T> y(n);\n\t\tfor (int i = 0, i_len = int(n); i <\
    \ i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(m); j < j_len; ++j)\n\t\t\t\t\
    y[i] += v[i][j] * x[j];\n\t\treturn y;\n\t}\n\tfriend vector<T> operator*(const\
    \ vector<T> &x, const Matrix &a)\n\t{\n\t\tvector<T> y(a.m);\n\t\tfor (int i =\
    \ 0, i_len = int(a.n); i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(a.m);\
    \ j < j_len; ++j)\n\t\t\t\ty[j] += x[i] * a[i][j];\n\t\treturn y;\n\t}\n\tMatrix\
    \ operator*(const Matrix &b) const\n\t{\n\t\tMatrix res(n, b.m);\n\t\tfor (int\
    \ i = 0, i_len = int(res.n); i < i_len; ++i)\n\t\t\tfor (int k = 0, k_len = int(m);\
    \ k < k_len; ++k)\n\t\t\t\tfor (int j = 0, j_len = int(res.m); j < j_len; ++j)\n\
    \t\t\t\t\tres[i][j] += v[i][k] * b[k][j];\n\t\treturn res;\n\t}\n\tMatrix &operator*=(const\
    \ Matrix &b)\n\t{\n\t\t*this = *this * b;\n\t\treturn *this;\n\t}\n\tMatrix pow(long\
    \ long d) const\n\t{\n\t\tMatrix res(n), pow2 = *this;\n\t\twhile (d > 0)\n\t\t\
    {\n\t\t\tif (d & 1)\n\t\t\t\tres *= pow2;\n\t\t\tpow2 *= pow2;\n\t\t\td >>= 1;\n\
    \t\t}\n\t\treturn res;\n\t}\n};\ntemplate <class T>\nvector<pair<int, int>> row_reduced_form(Matrix<T>\
    \ &A)\n{\n\tint n = A.n, m = A.m;\n\tvector<pair<int, int>> piv;\n\tpiv.reserve(min(n,\
    \ m));\n\tlist<int> rjs;\n\tfor (int j = 0, j_len = int(m); j < j_len; ++j)\n\t\
    \trjs.push_back(j);\n\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t{\n\t\
    \tauto it = rjs.begin();\n\t\tfor (; it != rjs.end(); it++)\n\t\t\tif (A[i][*it]\
    \ != 0)\n\t\t\t\tbreak;\n\t\tif (it == rjs.end())\n\t\t\tcontinue;\n\t\tint j\
    \ = *it;\n\t\trjs.erase(it);\n\t\tpiv.emplace_back(i, j);\n\t\tT Aij_inv = T(1)\
    \ / A[i][j];\n\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)\n\
    \t\t\tA[i][j2] *= Aij_inv;\n\t\tfor (int i2 = 0, i2_len = int(n); i2 < i2_len;\
    \ ++i2)\n\t\t\tif (A[i2][j] != 0 && i2 != i)\n\t\t\t{\n\t\t\t\tT mul = A[i2][j];\n\
    \t\t\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)\n\t\t\t\
    \t\tA[i2][j2] -= A[i][j2] * mul;\n\t\t\t}\n\t}\n\treturn piv;\n}\ntemplate <class\
    \ T>\nMatrix<T> inverse_matrix(const Matrix<T> &mat)\n{\n\tint n = mat.n;\n\t\
    vector<vector<T>> v(n, vector<T>(2 * n));\n\tfor (int i = 0, i_len = int(n); i\
    \ < i_len; ++i)\n\t\tfor (int j = 0, j_len = int(n); j < j_len; ++j)\n\t\t{\n\t\
    \t\tv[i][j] = mat[i][j];\n\t\t\tif (i == j)\n\t\t\t\tv[i][n + j] = 1;\n\t\t}\n\
    \tint m = 2 * n;\n\tint i = 0, j = 0;\n\twhile (i < n && j < m)\n\t{\n\t\tint\
    \ i2 = i;\n\t\twhile (i2 < n && v[i2][j] == T(0))\n\t\t\ti2++;\n\t\tif (i2 ==\
    \ n)\n\t\t\treturn Matrix<T>();\n\t\tif (i != i2)\n\t\t\tswap(v[i], v[i2]);\n\t\
    \tT vij_inv = T(1) / v[i][j];\n\t\tfor (int j2 = int(j), j2_end = int(m - 1);\
    \ j2 <= j2_end; ++j2)\n\t\t\tv[i][j2] *= vij_inv;\n\t\tfor (int i2 = 0, i2_len\
    \ = int(n); i2 < i2_len; ++i2)\n\t\t{\n\t\t\tif (i2 == i)\n\t\t\t\tcontinue;\n\
    \t\t\tT mul = v[i2][j];\n\t\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <=\
    \ j2_end; ++j2)\n\t\t\t\tv[i2][j2] -= v[i][j2] * mul;\n\t\t}\n\t\ti++;\n\t\tj++;\n\
    \t}\n\tMatrix<T> mat_inv(n, n);\n\tfor (int i = 0, i_len = int(n); i < i_len;\
    \ ++i)\n\t\tfor (int j = 0, j_len = int(n); j < j_len; ++j)\n\t\t\tmat_inv[i][j]\
    \ = v[i][n + j];\n\treturn mat_inv;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ T>\nstruct Matrix\n{\n\tint n, m;\n\tvector<vector<T>> v;\n\tMatrix(int n, int\
    \ m) : n(n), m(m), v(n, vector<T>(m)) {}\n\tMatrix(int n) : n(n), m(n), v(n, vector<T>(n))\n\
    \t{\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tv[i][i] = T(1);\n\
    \t}\n\tMatrix(const vector<vector<T>> &a) : n(((int)(a).size())), m(((int)(a[0]).size())),\
    \ v(a) {}\n\tMatrix() : n(0), m(0) {}\n\tMatrix(const Matrix &) = default;\n\t\
    Matrix &operator=(const Matrix &) = default;\n\tinline vector<T> const &operator[](int\
    \ i) const { return v[i]; }\n\tinline vector<T> &operator[](int i)\n\t{\n\t\t\
    return v[i];\n\t}\n\tfriend istream &operator>>(istream &is, Matrix &a)\n\t{\n\
    \t\tfor (int i = 0, i_len = int(a.n); i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len\
    \ = int(a.m); j < j_len; ++j)\n\t\t\t\tis >> a.v[i][j];\n\t\treturn is;\n\t}\n\
    \tvoid push_back(const vector<T> &a)\n\t{\n\t\t{\n\t\t\tif (!(((int)(a).size())\
    \ == m))\n\t\t\t{\n\t\t\t\tvector<char> MLE(1 << 30);\n\t\t\t\t{\n\t\t\t\t\tcout\
    \ << (MLE.back()) << endl;\n\t\t\t\t\texit(0);\n\t\t\t\t};\n\t\t\t}\n\t\t};\n\t\
    \tv.push_back(a);\n\t\tn++;\n\t}\n\tvoid pop_back()\n\t{\n\t\t{\n\t\t\tif (!(n\
    \ > 0))\n\t\t\t{\n\t\t\t\tvector<char> MLE(1 << 30);\n\t\t\t\t{\n\t\t\t\t\tcout\
    \ << (MLE.back()) << endl;\n\t\t\t\t\texit(0);\n\t\t\t\t};\n\t\t\t}\n\t\t};\n\t\
    \tv.pop_back();\n\t\tn--;\n\t}\n\tvoid resize(int n_)\n\t{\n\t\tv.resize(n_);\n\
    \t\tn = n_;\n\t}\n\tvoid resize(int n_, int m_)\n\t{\n\t\tn = n_;\n\t\tm = m_;\n\
    \t\tv.resize(n);\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\t\
    v[i].resize(m);\n\t}\n\tbool empty() const { return min(n, m) == 0; }\n\tbool\
    \ operator==(const Matrix &b) const { return n == b.n && m == b.m && v == b.v;\
    \ }\n\tbool operator!=(const Matrix &b) const { return !(*this == b); }\n\tMatrix\
    \ &operator+=(const Matrix &b)\n\t{\n\t\tfor (int i = 0, i_len = int(n); i < i_len;\
    \ ++i)\n\t\t\tfor (int j = 0, j_len = int(m); j < j_len; ++j)\n\t\t\t\tv[i][j]\
    \ += b[i][j];\n\t\treturn *this;\n\t}\n\tMatrix &operator-=(const Matrix &b)\n\
    \t{\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tfor (int j = 0,\
    \ j_len = int(m); j < j_len; ++j)\n\t\t\t\tv[i][j] -= b[i][j];\n\t\treturn *this;\n\
    \t}\n\tMatrix &operator*=(const T &c)\n\t{\n\t\tfor (int i = 0, i_len = int(n);\
    \ i < i_len; ++i)\n\t\t\tfor (int j = 0, j_len = int(m); j < j_len; ++j)\n\t\t\
    \t\tv[i][j] *= c;\n\t\treturn *this;\n\t}\n\tMatrix operator+(const Matrix &b)\
    \ const { return Matrix(*this) += b; }\n\tMatrix operator-(const Matrix &b) const\
    \ { return Matrix(*this) -= b; }\n\tMatrix operator*(const T &c) const { return\
    \ Matrix(*this) *= c; }\n\tfriend Matrix operator*(const T &c, const Matrix<T>\
    \ &a) { return a * c; }\n\tMatrix operator-() const { return Matrix(*this) *=\
    \ T(-1); }\n\tvector<T> operator*(const vector<T> &x) const\n\t{\n\t\tvector<T>\
    \ y(n);\n\t\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t\t\tfor (int j\
    \ = 0, j_len = int(m); j < j_len; ++j)\n\t\t\t\ty[i] += v[i][j] * x[j];\n\t\t\
    return y;\n\t}\n\tfriend vector<T> operator*(const vector<T> &x, const Matrix\
    \ &a)\n\t{\n\t\tvector<T> y(a.m);\n\t\tfor (int i = 0, i_len = int(a.n); i < i_len;\
    \ ++i)\n\t\t\tfor (int j = 0, j_len = int(a.m); j < j_len; ++j)\n\t\t\t\ty[j]\
    \ += x[i] * a[i][j];\n\t\treturn y;\n\t}\n\tMatrix operator*(const Matrix &b)\
    \ const\n\t{\n\t\tMatrix res(n, b.m);\n\t\tfor (int i = 0, i_len = int(res.n);\
    \ i < i_len; ++i)\n\t\t\tfor (int k = 0, k_len = int(m); k < k_len; ++k)\n\t\t\
    \t\tfor (int j = 0, j_len = int(res.m); j < j_len; ++j)\n\t\t\t\t\tres[i][j] +=\
    \ v[i][k] * b[k][j];\n\t\treturn res;\n\t}\n\tMatrix &operator*=(const Matrix\
    \ &b)\n\t{\n\t\t*this = *this * b;\n\t\treturn *this;\n\t}\n\tMatrix pow(long\
    \ long d) const\n\t{\n\t\tMatrix res(n), pow2 = *this;\n\t\twhile (d > 0)\n\t\t\
    {\n\t\t\tif (d & 1)\n\t\t\t\tres *= pow2;\n\t\t\tpow2 *= pow2;\n\t\t\td >>= 1;\n\
    \t\t}\n\t\treturn res;\n\t}\n};\ntemplate <class T>\nvector<pair<int, int>> row_reduced_form(Matrix<T>\
    \ &A)\n{\n\tint n = A.n, m = A.m;\n\tvector<pair<int, int>> piv;\n\tpiv.reserve(min(n,\
    \ m));\n\tlist<int> rjs;\n\tfor (int j = 0, j_len = int(m); j < j_len; ++j)\n\t\
    \trjs.push_back(j);\n\tfor (int i = 0, i_len = int(n); i < i_len; ++i)\n\t{\n\t\
    \tauto it = rjs.begin();\n\t\tfor (; it != rjs.end(); it++)\n\t\t\tif (A[i][*it]\
    \ != 0)\n\t\t\t\tbreak;\n\t\tif (it == rjs.end())\n\t\t\tcontinue;\n\t\tint j\
    \ = *it;\n\t\trjs.erase(it);\n\t\tpiv.emplace_back(i, j);\n\t\tT Aij_inv = T(1)\
    \ / A[i][j];\n\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)\n\
    \t\t\tA[i][j2] *= Aij_inv;\n\t\tfor (int i2 = 0, i2_len = int(n); i2 < i2_len;\
    \ ++i2)\n\t\t\tif (A[i2][j] != 0 && i2 != i)\n\t\t\t{\n\t\t\t\tT mul = A[i2][j];\n\
    \t\t\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <= j2_end; ++j2)\n\t\t\t\
    \t\tA[i2][j2] -= A[i][j2] * mul;\n\t\t\t}\n\t}\n\treturn piv;\n}\ntemplate <class\
    \ T>\nMatrix<T> inverse_matrix(const Matrix<T> &mat)\n{\n\tint n = mat.n;\n\t\
    vector<vector<T>> v(n, vector<T>(2 * n));\n\tfor (int i = 0, i_len = int(n); i\
    \ < i_len; ++i)\n\t\tfor (int j = 0, j_len = int(n); j < j_len; ++j)\n\t\t{\n\t\
    \t\tv[i][j] = mat[i][j];\n\t\t\tif (i == j)\n\t\t\t\tv[i][n + j] = 1;\n\t\t}\n\
    \tint m = 2 * n;\n\tint i = 0, j = 0;\n\twhile (i < n && j < m)\n\t{\n\t\tint\
    \ i2 = i;\n\t\twhile (i2 < n && v[i2][j] == T(0))\n\t\t\ti2++;\n\t\tif (i2 ==\
    \ n)\n\t\t\treturn Matrix<T>();\n\t\tif (i != i2)\n\t\t\tswap(v[i], v[i2]);\n\t\
    \tT vij_inv = T(1) / v[i][j];\n\t\tfor (int j2 = int(j), j2_end = int(m - 1);\
    \ j2 <= j2_end; ++j2)\n\t\t\tv[i][j2] *= vij_inv;\n\t\tfor (int i2 = 0, i2_len\
    \ = int(n); i2 < i2_len; ++i2)\n\t\t{\n\t\t\tif (i2 == i)\n\t\t\t\tcontinue;\n\
    \t\t\tT mul = v[i2][j];\n\t\t\tfor (int j2 = int(j), j2_end = int(m - 1); j2 <=\
    \ j2_end; ++j2)\n\t\t\t\tv[i2][j2] -= v[i][j2] * mul;\n\t\t}\n\t\ti++;\n\t\tj++;\n\
    \t}\n\tMatrix<T> mat_inv(n, n);\n\tfor (int i = 0, i_len = int(n); i < i_len;\
    \ ++i)\n\t\tfor (int j = 0, j_len = int(n); j < j_len; ++j)\n\t\t\tmat_inv[i][j]\
    \ = v[i][n + j];\n\treturn mat_inv;\n}"
  dependsOn: []
  isVerificationFile: false
  path: autodp/matrix.hpp
  requiredBy: []
  timestamp: '2025-11-05 10:48:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: autodp/matrix.hpp
layout: document
redirect_from:
- /library/autodp/matrix.hpp
- /library/autodp/matrix.hpp.html
title: autodp/matrix.hpp
---
