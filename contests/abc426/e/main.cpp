#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}
#define eps 1e-18L
ld dist(pair<ld, ld>&x, pair<ld, ld>& y) { return (x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se); }
pair<ld, ld> sim(pair<ld, ld>& x, pair<ld, ld>& y, ld d, ld t) {
    if (d <= t+eps) {
        return y;
    } elif (t <= eps) {
        return x;
    } else {
        return {
            ((d-t)*x.fi + t*y.fi) / d, 
            ((d-t)*x.se + t*y.se) / d
        };
    }
}


void solve() {
    pair<ld, ld> ps, pg, qs, qg; cin >> ps >> pg >> qs >> qg;
    ld d1 = sqrtl(dist(ps, pg));
    ld d2 = sqrtl(dist(qs, qg));
    if (d1 > d2) {
        swap(d1, d2);
        swap(ps, qs);
        swap(pg, qg);
    }
    ld ans = 1e100;
    auto solvemin = [&](ld x, ld y, ld z, ld l, ld r) -> ld {
        ld vL = x*l*l + y*l + z;
        ld vR = x*r*r + y*r + z;
        ld re = min(vL, vR);
        if (fabsl(x) > eps) {
            ld t = -y / (2*x);
            if (t > l+eps && t+eps < r) {
                ld v = x*t*t + y*t + z;
                chmin(re, v);
            }
        }
        return re;
    };
    ld sx = ps.fi - qs.fi;
    ld sy = ps.se - qs.se;
    ld vpx = (pg.fi - ps.fi) / d1;
    ld vpy = (pg.se - ps.se) / d1;
    ld vqx = (qg.fi - qs.fi) / d2;
    ld vqy = (qg.se - qs.se) / d2;
    {
        ld dx = vpx - vqx;
        ld dy = vpy - vqy;
        ans = min(ans, solvemin(dx*dx + dy*dy, 2.L * (sx*dx + sy*dy), sx*sx + sy*sy, .0L, d1));
    }
    if (d1+eps < d2) {
        sx = pg.fi - qs.fi;
        sy = pg.se - qs.se;
        ld dx = -vqx;
        ld dy = -vqy;
        ans = min(ans, solvemin(dx*dx + dy*dy, 2.L * (sx*dx + sy*dy), sx*sx + sy*sy, d1, d2));
    }
    {
        ld d = dist(pg, qg);
        chmin(ans, d);
    }
    cout << sqrtl(ans) << nl;
}