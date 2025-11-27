#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "template"
#include "lazysegtree"
#include "modint"
using mint = modint<998244353>;

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vec<pair<mint, mint>> a(n); cin >> a;
    lazysegtree<pairs<mint>,[](pairs<mint>x,pairs<mint>y){return pairs<mint>{y.fi*x.fi,y.fi*x.se+y.se};},[](){return pairs<mint>{1,0};},pairs<mint>,[](pairs<mint>x,pairs<mint>y){return pairs<mint>{y.fi*x.fi,y.fi*x.se+y.se};},[](pairs<mint>x,pairs<mint>y){return pairs<mint>{y.fi*x.fi,y.fi*x.se+y.se};},[](){return pairs<mint>{1,0};}> seg(a);
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int y; mint c, d; cin >> y >> c >> d;
            seg.set(y, pairs<mint>{c, d});
        } else {
            int l, r; mint y; cin >> l >> r >> y;
            auto p = seg.prod(l, r);
            cout << p.fi*y+p.se << nl;
        }
    }
}