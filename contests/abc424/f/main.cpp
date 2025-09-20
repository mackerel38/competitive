#include "template"
#include "segtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

pi op(pi x, pi y) {
    return {min(x.fi, y.fi), max(x.se, y.se)};
}
pi e(){ return {inf, -inf}; }

void solve() {
    int n, q; cin >> n >> q;
    segtree<pi, op, e> seg(n);
    vi p(n);
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        if (y < x) swap(x, y);
        bool flag = true;
        if (x+1 != y) {
            pi z = seg.prod(x+1, y);
            if (z.fi < x+1 || y+1 < z.se) flag = false;
        }
        if (flag) {
            Yes;
            p[x] = y; p[y] = x;
            seg.set(x, {y+1, y+1});
            seg.set(y, {x+1, x+1});
        } else {
            No;
        }
    }
}