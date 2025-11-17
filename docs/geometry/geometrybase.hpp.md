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
  bundledCode: "#line 2 \"geometry/geometrybase.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing point = complex<double>;\nconst double geo_PI =\
    \ acos(-1);\n\n// \u5B9F\u6570\u306E\u7B49\u5024\u5224\u5B9A\ninline bool eq(double\
    \ a, double b) { return abs(a - b) < 1e-9; }\n\nistream &operator>>(istream &i,\
    \ point &p) {\n    double x, y;\n    i >> x >> y;\n    p = point(x, y);\n    return\
    \ i;\n}\n\nostream &operator<<(ostream &o, const point &p) {\n    o << p.real()\
    \ << \" \" << p.imag();\n    return o;\n}\n\n// \u53CD\u6642\u8A08\u56DE\u308A\
    \u306Btheta\u56DE\u8EE2\npoint rotate(point &p, double theta) {\n    return p\
    \ * point(cos(theta), sin(theta));\n}\n// \u5EA6\u6570\u6CD5\u306B\u5909\u63DB\
    \ndouble to_deg(double rad) { return rad * 180.0 / geo_PI; }\n// \u5F27\u5EA6\u6CD5\
    \u306B\u5909\u63DB\ndouble to_rad(double deg) { return deg * geo_PI / 180.0; }\n\
    \n// \u5916\u7A4D\ndouble cross(const point &a, const point &b) { return a.real()\
    \ * b.imag() - a.imag() * b.real(); }\n\n// \u5185\u7A4D\ndouble dot(const point\
    \ &a, const point &b) { return a.real() * b.real() + a.imag() * b.imag(); }\n\n\
    // 3\u70B9abc\u306E\u306A\u3059\u89D2\ndouble angle(point &a, point &b, point\
    \ &c) {\n    point ab = b - a, ac = c - a;\n    return acos(dot(ab, ac)) / (abs(ab)\
    \ * abs(ac));\n}\n\nstruct line {\n    point a, b;\n    bool segment = false;\n\
    \    line() = default;\n    line(point a, point b) : a(a), b(b) {}\n    // Ax\
    \ + By + C = 0\n    line(double a, double b, double c) {\n        if (eq(a, 0))\
    \ {\n            this->a = point(0, -c / b);\n            this->b = point(1, -c\
    \ / b);\n        } else if (eq(b, 0)) {\n            this->a = point(-c / a, 0);\n\
    \            this->b = point(-c / a, 1);\n        } else {\n            this->a\
    \ = point(0, -c / b);\n            this->b = point(-c / a, 0);\n        }\n  \
    \  }\n    istream &operator>>(istream &i) {\n        i >> a >> b;\n        return\
    \ i;\n    }\n    ostream &operator<<(ostream &o) {\n        o << a << \" \" <<\
    \ b;\n        return o;\n    }\n    // \u50BE\u304D\n    double slope() {\n  \
    \      return (b.imag() - a.imag()) / (b.real() - a.real());\n    }\n};\n\nstruct\
    \ circle {\n    point c;\n    double r;\n    circle() = default;\n    circle(point\
    \ c, double r) : c(c), r(r) {}\n};\n\nusing points = vector<point>;\nusing lines\
    \ = vector<line>;\nusing circles = vector<circle>;\n\n// \u70B9p \u3092\u901A\u308B\
    \u76F4\u7DDAl \u306B\u5782\u7DDA\u3092\u4E0B\u308D\u3057\u305F\u8DB3\npoint projection(const\
    \ line &l, const point &p) {\n  double t = dot(p - l.a, l.a - l.b) / norm(l.a\
    \ - l.b);\n  return l.a + (l.a - l.b) * t;\n}\n\n// \u76F4\u7DDAl \u306B\u5BFE\
    \u3057\u3066\u70B9p \u3068\u7DDA\u5BFE\u79F0\u306A\u70B9\npoint reflection(const\
    \ line &l, const point &p) {\n  return p + (projection(l, p) - p) * 2.;\n}\n\n\
    // 3\u70B9a, b, c \u304C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u304B\nbool\
    \ is_collinear(const point &a, const point &b, const point &c) {\n    return eq(cross(b\
    \ - a, c - a), 0);\n}\n// 3\u70B9a, b, c \u304C\u53CD\u6642\u8A08\u56DE\u308A\u306E\
    \u9806\u306B\u4E26\u3093\u3067\u3044\u308B\u304B\nbool is_counter_clockwise(const\
    \ point &a, const point &b, const point &c) {\n    return cross(b - a, c - a)\
    \ > 0;\n}\n// 3\u70B9a, b, c \u304C\u6642\u8A08\u56DE\u308A\u306E\u9806\u306B\u4E26\
    \u3093\u3067\u3044\u308B\u304B\nbool is_clockwise(const point &a, const point\
    \ &b, const point &c) {\n    return cross(b - a, c - a) < 0;\n}\n// \u70B9p \u304C\
    \u7DDA\u5206l \u4E0A\u306B\u3042\u308B\u304B\nbool is_point_on_segment(const line\
    \ &l, const point &p) {\n    if (!eq(cross(l.b - l.a, p - l.a), 0)) return false;\n\
    \    if (dot(l.a - p, l.b - p) > 0) return false;\n    return true;\n}\n// \u76F4\
    \u7DDAl, m \u304C\u5E73\u884C\u304B\nbool is_parallel(const line &l, const line\
    \ &m) {\n    return eq(cross(l.b - l.a, m.b - m.a), 0);\n}\n// \u76F4\u7DDAl,\
    \ m \u304C\u5782\u76F4\u304B\nbool is_orthogonal(const line &l, const line &m)\
    \ {\n    return eq(dot(l.b - l.a, m.b - m.a), 0);\n}\n// \u76F4\u7DDAl, m \u306E\
    \u4EA4\u70B9\npoint intersection(const line &l, const line &m) {\n    if (is_parallel(l,\
    \ m)) return point(numeric_limits<double>::max(), numeric_limits<double>::max());\n\
    \    double A = cross(m.b - m.a, l.b - l.a);\n    double B = cross(m.b - m.a,\
    \ m.b - l.a);\n    if (eq(A, 0)) return point(numeric_limits<double>::max(), numeric_limits<double>::max());\n\
    \    return l.a + (l.b - l.a) * (B / A);\n}\n// \u7DDA\u5206l, m \u304C\u4EA4\u5DEE\
    \u3057\u3066\u3044\u308B\u304B\nbool is_intersected(const line &l, const line\
    \ &m) {\n    point p = intersection(l, m);\n    if (p == point(numeric_limits<double>::max(),\
    \ numeric_limits<double>::max())) return false;\n    if (l.segment && !is_point_on_segment(l,\
    \ p)) return false;\n    if (m.segment && !is_point_on_segment(m, p)) return false;\n\
    \    return true;\n}\n\n// \u7DDA\u5206l, m \u306E\u8DDD\u96E2\ndouble distance(const\
    \ line &l, const line &m) {\n    if (is_intersected(l, m)) return 0.0;\n    return\
    \ min({abs(projection(l, m.a) - m.a), abs(projection(l, m.b) - m.b), abs(projection(m,\
    \ l.a) - l.a), abs(projection(m, l.b) - l.b)});\n}\n\n// 3\u70B9a, b, c \u306E\
    \u306A\u3059\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const point &a,\
    \ const point &b, const point &c) {\n    return abs(cross(b - a, c - a)) / 2.0;\n\
    }\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const points &ps) {\n\
    \    double res = 0.0;\n    for (int i=0; i<(int)ps.size(); i++) {\n        res\
    \ += cross(ps[i], ps[(i+1) % (int)ps.size()]);\n    }\n    return abs(res) / 2.0;\n\
    }\n// \u51F8\u6027\u5224\u5B9A\nbool is_convex(const points &ps) {\n    int n\
    \ = (int)ps.size();\n    if (n < 3) return false;\n    bool pos = false, neg =\
    \ false;\n    for (int i=0; i<n; i++) {\n        double c = cross(ps[(i+1)%n]\
    \ - ps[i], ps[(i+2)%n] - ps[i]);\n        if (c > 0) pos = true;\n        if (c\
    \ < 0) neg = true;\n    }\n    return !(pos && neg);\n}\n// \u591A\u89D2\u5F62\
    \u306E\u5305\u542B\u5224\u5B9A\nbool contains(const points &ps, const point &p)\
    \ {\n    int n = (int)ps.size();\n    bool in = false;\n    for (int i=0; i<n;\
    \ i++) {\n        point a = ps[i] - p, b = ps[(i+1)%n] - p;\n        if (a.imag()\
    \ > b.imag()) swap(a, b);\n        if (a.imag() <= 0 && 0 < b.imag() && cross(a,\
    \ b) < 0) in = !in;\n        if (eq(cross(a, b), 0) && dot(a, b) <= 0) return\
    \ true;\n    }\n    return in;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing point\
    \ = complex<double>;\nconst double geo_PI = acos(-1);\n\n// \u5B9F\u6570\u306E\
    \u7B49\u5024\u5224\u5B9A\ninline bool eq(double a, double b) { return abs(a -\
    \ b) < 1e-9; }\n\nistream &operator>>(istream &i, point &p) {\n    double x, y;\n\
    \    i >> x >> y;\n    p = point(x, y);\n    return i;\n}\n\nostream &operator<<(ostream\
    \ &o, const point &p) {\n    o << p.real() << \" \" << p.imag();\n    return o;\n\
    }\n\n// \u53CD\u6642\u8A08\u56DE\u308A\u306Btheta\u56DE\u8EE2\npoint rotate(point\
    \ &p, double theta) {\n    return p * point(cos(theta), sin(theta));\n}\n// \u5EA6\
    \u6570\u6CD5\u306B\u5909\u63DB\ndouble to_deg(double rad) { return rad * 180.0\
    \ / geo_PI; }\n// \u5F27\u5EA6\u6CD5\u306B\u5909\u63DB\ndouble to_rad(double deg)\
    \ { return deg * geo_PI / 180.0; }\n\n// \u5916\u7A4D\ndouble cross(const point\
    \ &a, const point &b) { return a.real() * b.imag() - a.imag() * b.real(); }\n\n\
    // \u5185\u7A4D\ndouble dot(const point &a, const point &b) { return a.real()\
    \ * b.real() + a.imag() * b.imag(); }\n\n// 3\u70B9abc\u306E\u306A\u3059\u89D2\
    \ndouble angle(point &a, point &b, point &c) {\n    point ab = b - a, ac = c -\
    \ a;\n    return acos(dot(ab, ac)) / (abs(ab) * abs(ac));\n}\n\nstruct line {\n\
    \    point a, b;\n    bool segment = false;\n    line() = default;\n    line(point\
    \ a, point b) : a(a), b(b) {}\n    // Ax + By + C = 0\n    line(double a, double\
    \ b, double c) {\n        if (eq(a, 0)) {\n            this->a = point(0, -c /\
    \ b);\n            this->b = point(1, -c / b);\n        } else if (eq(b, 0)) {\n\
    \            this->a = point(-c / a, 0);\n            this->b = point(-c / a,\
    \ 1);\n        } else {\n            this->a = point(0, -c / b);\n           \
    \ this->b = point(-c / a, 0);\n        }\n    }\n    istream &operator>>(istream\
    \ &i) {\n        i >> a >> b;\n        return i;\n    }\n    ostream &operator<<(ostream\
    \ &o) {\n        o << a << \" \" << b;\n        return o;\n    }\n    // \u50BE\
    \u304D\n    double slope() {\n        return (b.imag() - a.imag()) / (b.real()\
    \ - a.real());\n    }\n};\n\nstruct circle {\n    point c;\n    double r;\n  \
    \  circle() = default;\n    circle(point c, double r) : c(c), r(r) {}\n};\n\n\
    using points = vector<point>;\nusing lines = vector<line>;\nusing circles = vector<circle>;\n\
    \n// \u70B9p \u3092\u901A\u308B\u76F4\u7DDAl \u306B\u5782\u7DDA\u3092\u4E0B\u308D\
    \u3057\u305F\u8DB3\npoint projection(const line &l, const point &p) {\n  double\
    \ t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);\n  return l.a + (l.a - l.b) *\
    \ t;\n}\n\n// \u76F4\u7DDAl \u306B\u5BFE\u3057\u3066\u70B9p \u3068\u7DDA\u5BFE\
    \u79F0\u306A\u70B9\npoint reflection(const line &l, const point &p) {\n  return\
    \ p + (projection(l, p) - p) * 2.;\n}\n\n// 3\u70B9a, b, c \u304C\u4E00\u76F4\u7DDA\
    \u4E0A\u306B\u3042\u308B\u304B\nbool is_collinear(const point &a, const point\
    \ &b, const point &c) {\n    return eq(cross(b - a, c - a), 0);\n}\n// 3\u70B9\
    a, b, c \u304C\u53CD\u6642\u8A08\u56DE\u308A\u306E\u9806\u306B\u4E26\u3093\u3067\
    \u3044\u308B\u304B\nbool is_counter_clockwise(const point &a, const point &b,\
    \ const point &c) {\n    return cross(b - a, c - a) > 0;\n}\n// 3\u70B9a, b, c\
    \ \u304C\u6642\u8A08\u56DE\u308A\u306E\u9806\u306B\u4E26\u3093\u3067\u3044\u308B\
    \u304B\nbool is_clockwise(const point &a, const point &b, const point &c) {\n\
    \    return cross(b - a, c - a) < 0;\n}\n// \u70B9p \u304C\u7DDA\u5206l \u4E0A\
    \u306B\u3042\u308B\u304B\nbool is_point_on_segment(const line &l, const point\
    \ &p) {\n    if (!eq(cross(l.b - l.a, p - l.a), 0)) return false;\n    if (dot(l.a\
    \ - p, l.b - p) > 0) return false;\n    return true;\n}\n// \u76F4\u7DDAl, m \u304C\
    \u5E73\u884C\u304B\nbool is_parallel(const line &l, const line &m) {\n    return\
    \ eq(cross(l.b - l.a, m.b - m.a), 0);\n}\n// \u76F4\u7DDAl, m \u304C\u5782\u76F4\
    \u304B\nbool is_orthogonal(const line &l, const line &m) {\n    return eq(dot(l.b\
    \ - l.a, m.b - m.a), 0);\n}\n// \u76F4\u7DDAl, m \u306E\u4EA4\u70B9\npoint intersection(const\
    \ line &l, const line &m) {\n    if (is_parallel(l, m)) return point(numeric_limits<double>::max(),\
    \ numeric_limits<double>::max());\n    double A = cross(m.b - m.a, l.b - l.a);\n\
    \    double B = cross(m.b - m.a, m.b - l.a);\n    if (eq(A, 0)) return point(numeric_limits<double>::max(),\
    \ numeric_limits<double>::max());\n    return l.a + (l.b - l.a) * (B / A);\n}\n\
    // \u7DDA\u5206l, m \u304C\u4EA4\u5DEE\u3057\u3066\u3044\u308B\u304B\nbool is_intersected(const\
    \ line &l, const line &m) {\n    point p = intersection(l, m);\n    if (p == point(numeric_limits<double>::max(),\
    \ numeric_limits<double>::max())) return false;\n    if (l.segment && !is_point_on_segment(l,\
    \ p)) return false;\n    if (m.segment && !is_point_on_segment(m, p)) return false;\n\
    \    return true;\n}\n\n// \u7DDA\u5206l, m \u306E\u8DDD\u96E2\ndouble distance(const\
    \ line &l, const line &m) {\n    if (is_intersected(l, m)) return 0.0;\n    return\
    \ min({abs(projection(l, m.a) - m.a), abs(projection(l, m.b) - m.b), abs(projection(m,\
    \ l.a) - l.a), abs(projection(m, l.b) - l.b)});\n}\n\n// 3\u70B9a, b, c \u306E\
    \u306A\u3059\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const point &a,\
    \ const point &b, const point &c) {\n    return abs(cross(b - a, c - a)) / 2.0;\n\
    }\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const points &ps) {\n\
    \    double res = 0.0;\n    for (int i=0; i<(int)ps.size(); i++) {\n        res\
    \ += cross(ps[i], ps[(i+1) % (int)ps.size()]);\n    }\n    return abs(res) / 2.0;\n\
    }\n// \u51F8\u6027\u5224\u5B9A\nbool is_convex(const points &ps) {\n    int n\
    \ = (int)ps.size();\n    if (n < 3) return false;\n    bool pos = false, neg =\
    \ false;\n    for (int i=0; i<n; i++) {\n        double c = cross(ps[(i+1)%n]\
    \ - ps[i], ps[(i+2)%n] - ps[i]);\n        if (c > 0) pos = true;\n        if (c\
    \ < 0) neg = true;\n    }\n    return !(pos && neg);\n}\n// \u591A\u89D2\u5F62\
    \u306E\u5305\u542B\u5224\u5B9A\nbool contains(const points &ps, const point &p)\
    \ {\n    int n = (int)ps.size();\n    bool in = false;\n    for (int i=0; i<n;\
    \ i++) {\n        point a = ps[i] - p, b = ps[(i+1)%n] - p;\n        if (a.imag()\
    \ > b.imag()) swap(a, b);\n        if (a.imag() <= 0 && 0 < b.imag() && cross(a,\
    \ b) < 0) in = !in;\n        if (eq(cross(a, b), 0) && dot(a, b) <= 0) return\
    \ true;\n    }\n    return in;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometrybase.hpp
  requiredBy: []
  timestamp: '2025-10-05 01:09:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometrybase.hpp
layout: document
redirect_from:
- /library/geometry/geometrybase.hpp
- /library/geometry/geometrybase.hpp.html
title: geometry/geometrybase.hpp
---
