#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

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
    vec<pair<int, pairs<mint>>> a(n); range2(_, i, a) cin >> i;
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int l, r; mint c, d; cin >> l >> r >> c >> d;
        } else {
            int l, r; mint x; cin >> l >> r >> x;
        }
    }
}