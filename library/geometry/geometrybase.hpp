#pragma once
#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
const double geo_PI = acos(-1);

// 実数の等値判定
inline bool eq(double a, double b) { return abs(a - b) < 1e-9; }

istream &operator>>(istream &i, point &p) {
    double x, y;
    i >> x >> y;
    p = point(x, y);
    return i;
}

ostream &operator<<(ostream &o, const point &p) {
    o << p.real() << " " << p.imag();
    return o;
}

// 反時計回りにtheta回転
point rotate(point &p, double theta) {
    return p * point(cos(theta), sin(theta));
}
// 度数法に変換
double to_deg(double rad) { return rad * 180.0 / geo_PI; }
// 弧度法に変換
double to_rad(double deg) { return deg * geo_PI / 180.0; }

// 外積
double cross(const point &a, const point &b) { return a.real() * b.imag() - a.imag() * b.real(); }

// 内積
double dot(const point &a, const point &b) { return a.real() * b.real() + a.imag() * b.imag(); }

// 3点abcのなす角
double angle(point &a, point &b, point &c) {
    point ab = b - a, ac = c - a;
    return acos(dot(ab, ac)) / (abs(ab) * abs(ac));
}

struct line {
    point a, b;
    bool segment = false;
    line() = default;
    line(point a, point b) : a(a), b(b) {}
    // Ax + By + C = 0
    line(double a, double b, double c) {
        if (eq(a, 0)) {
            this->a = point(0, -c / b);
            this->b = point(1, -c / b);
        } else if (eq(b, 0)) {
            this->a = point(-c / a, 0);
            this->b = point(-c / a, 1);
        } else {
            this->a = point(0, -c / b);
            this->b = point(-c / a, 0);
        }
    }
    istream &operator>>(istream &i) {
        i >> a >> b;
        return i;
    }
    ostream &operator<<(ostream &o) {
        o << a << " " << b;
        return o;
    }
    // 傾き
    double slope() {
        return (b.imag() - a.imag()) / (b.real() - a.real());
    }
};

struct circle {
    point c;
    double r;
    circle() = default;
    circle(point c, double r) : c(c), r(r) {}
};

using points = vector<point>;
using lines = vector<line>;
using circles = vector<circle>;

// 点p を通る直線l に垂線を下ろした足
point projection(const line &l, const point &p) {
  double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

// 直線l に対して点p と線対称な点
point reflection(const line &l, const point &p) {
  return p + (projection(l, p) - p) * 2.;
}

// 3点a, b, c が一直線上にあるか
bool is_collinear(const point &a, const point &b, const point &c) {
    return eq(cross(b - a, c - a), 0);
}
// 3点a, b, c が反時計回りの順に並んでいるか
bool is_counter_clockwise(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) > 0;
}
// 3点a, b, c が時計回りの順に並んでいるか
bool is_clockwise(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a) < 0;
}
// 点p が線分l 上にあるか
bool is_point_on_segment(const line &l, const point &p) {
    if (!eq(cross(l.b - l.a, p - l.a), 0)) return false;
    if (dot(l.a - p, l.b - p) > 0) return false;
    return true;
}
// 直線l, m が平行か
bool is_parallel(const line &l, const line &m) {
    return eq(cross(l.b - l.a, m.b - m.a), 0);
}
// 直線l, m が垂直か
bool is_orthogonal(const line &l, const line &m) {
    return eq(dot(l.b - l.a, m.b - m.a), 0);
}
// 直線l, m の交点
point intersection(const line &l, const line &m) {
    if (is_parallel(l, m)) return point(numeric_limits<double>::max(), numeric_limits<double>::max());
    double A = cross(m.b - m.a, l.b - l.a);
    double B = cross(m.b - m.a, m.b - l.a);
    if (eq(A, 0)) return point(numeric_limits<double>::max(), numeric_limits<double>::max());
    return l.a + (l.b - l.a) * (B / A);
}
// 線分l, m が交差しているか
bool is_intersected(const line &l, const line &m) {
    point p = intersection(l, m);
    if (p == point(numeric_limits<double>::max(), numeric_limits<double>::max())) return false;
    if (l.segment && !is_point_on_segment(l, p)) return false;
    if (m.segment && !is_point_on_segment(m, p)) return false;
    return true;
}

// 線分l, m の距離
double distance(const line &l, const line &m) {
    if (is_intersected(l, m)) return 0.0;
    return min({abs(projection(l, m.a) - m.a), abs(projection(l, m.b) - m.b), abs(projection(m, l.a) - l.a), abs(projection(m, l.b) - l.b)});
}

// 3点a, b, c のなす三角形の面積
double area(const point &a, const point &b, const point &c) {
    return abs(cross(b - a, c - a)) / 2.0;
}
// 多角形の面積
double area(const points &ps) {
    double res = 0.0;
    for (int i=0; i<(int)ps.size(); i++) {
        res += cross(ps[i], ps[(i+1) % (int)ps.size()]);
    }
    return abs(res) / 2.0;
}
// 凸性判定
bool is_convex(const points &ps) {
    int n = (int)ps.size();
    if (n < 3) return false;
    bool pos = false, neg = false;
    for (int i=0; i<n; i++) {
        double c = cross(ps[(i+1)%n] - ps[i], ps[(i+2)%n] - ps[i]);
        if (c > 0) pos = true;
        if (c < 0) neg = true;
    }
    return !(pos && neg);
}
// 多角形の包含判定
bool contains(const points &ps, const point &p) {
    int n = (int)ps.size();
    bool in = false;
    for (int i=0; i<n; i++) {
        point a = ps[i] - p, b = ps[(i+1)%n] - p;
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
        if (eq(cross(a, b), 0) && dot(a, b) <= 0) return true;
    }
    return in;
}