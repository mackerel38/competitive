#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

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
    vec<pairs<mint>> a(n, pairs<mint>{0, 1});
    range2(i, _, a) cin >> i;
    lazysegtree<pairs<mint>, [](pairs<mint> x, pairs<mint> y){ return pairs<mint>{x.fi+y.fi, x.se+y.se}; }, [](){ return pairs<mint>{0, 0}; },
                pairs<mint>, [](pairs<mint> x, pairs<mint> y){ return pairs<mint>{x.fi*y.fi+x.se*y.se, y.se}; },
                [](pairs<mint> x, pairs<mint> y){ return pairs<mint>{x.fi*y.fi, x.fi*y.se+x.se}; }, [](){ return pairs<mint>{1, 0}; }> seg(a);
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int l, r; mint a, b; cin >> l >> r >> a >> b;
            seg.apply(l, r, pairs<mint>{a, b});
        } else {
            int y; cin >> y;
            cout << seg[y].fi << nl;
        }
    }
}