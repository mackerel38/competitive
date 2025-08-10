#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "template"
#include "modint"
#include "segtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vec<pair<mint, mint>> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    auto op = [](pair<mint, mint> f, pair<mint, mint> g) -> pair<mint, mint> {
        return {g.first * f.first, g.first * f.second + g.second};
    };
    auto e = []() -> pair<mint, mint> {
        return {mint(1), mint(0)};
    };
    segtree<pair<mint, mint>, op, e> seg(a);
    while (q--) {
        int w, x, y, z; cin >> w >> x >> y >> z;
        if (w == 0) {
            seg.set(x, {mint(y), mint(z)});
        } else {
            auto [s, t] = seg.prod(x, y);
            cout << s * z + t << nl;
        }
    }
}