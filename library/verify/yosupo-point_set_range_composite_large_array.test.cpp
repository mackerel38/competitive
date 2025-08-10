#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "template"
#include "modint"
#include "dynamicsegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    auto op = [](pair<mint, mint> f, pair<mint, mint> g) -> pair<mint, mint> {
        return {g.first * f.first, g.first * f.second + g.second};
    };
    auto e = []() -> pair<mint, mint> {
        return {mint(1), mint(0)};
    };
    dynamicsegtree<pair<mint, mint>, op, e> seg(n);
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