#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "template"
#include "lazysegtree"
#include "modint"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vec<pair<mint, mint>> a(n);
    rep(i, n) {
        mint x; cin >> x;
        a[i] = {x, mint(1)};
    }
    auto op = [](pair<mint, mint> a, pair<mint, mint> b) {
        return make_pair(a.first + b.first, a.second + b.second);
    };
    auto mapping = [](pair<mint, mint> f, pair<mint, mint> x) {
        return make_pair(f.first * x.first + f.second * x.second, x.second);
    };
    auto composition = [](pair<mint, mint> f, pair<mint, mint> g) {
        return make_pair(f.first * g.first, f.first * g.second + f.second);
    };
    lazysegtree<pair<mint, mint>, op, pair<mint, mint>, mapping, composition> seg(a, make_pair(mint(0), mint(0)), make_pair(mint(1), mint(0)));
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            mint x, y;
            cin >> l >> r >> x >> y;
            seg.apply(l, r, make_pair(x, y));
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).first << nl;
        }
    }
}