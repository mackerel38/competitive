#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "template"
#include "lazysegtree"
#include "modint"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    using P = pair<mint, mint>;
    vec<P> a(n);
    rep(i, n) {
        mint x; cin >> x;
        a[i] = {x, mint(1)};
    }
    auto op = [](P a, P b) -> P { return {a.first+b.first, a.second+b.second}; };
    auto mapping = [](P a, P b) -> P { return {a.first*b.first+a.second*b.second, b.second}; };
    auto composition = [](P a, P b) -> P { return {a.first*b.first, a.first*b.second+a.second}; };
    lazysegtree<P, op, P, mapping, composition> seg(a, {mint(0), mint(0)}, {mint(1), mint(0)});
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int l, r; mint a, b; cin >> l >> r >> a >> b;
            seg.apply(l, r, {a, b});
        } else {
            int y; cin >> y;
            cout << seg.get(y).first << nl;
        }
    }
}