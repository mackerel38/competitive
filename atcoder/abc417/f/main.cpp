#include "template"
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<mint> a(n); rep(i, n) { ll x; cin >> x; a[i] = mint(x); }
    auto op = [](mint x, mint y) { return x + y; };
    auto e = []() { return mint(0); };
    auto mapping = [&](mint f, mint x) { return f == mint(INF) ? x : f; };
    auto composition = [&](mint f, mint g) { return f == mint(INF) ? g : f; };
    auto id = []() { return mint(INF); };
    lazy_segtree<mint, op, e, mint, mapping, composition, id> seg(n);
    rep(i, n) seg.set(i, a[i]);
    while (m--) {
        int l, r; cin >> l >> r; --l;
        mint len = r - l;
        seg.apply(l, r, seg.prod(l, r) * len.inv());
    }
    rep(i, n) cout << seg.get(i).val() << sp;
    cout << nl;
}