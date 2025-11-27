#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "template"
#include "BIT"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    BIT<ll> seg(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << seg.sum(l, r) << nl;
    }
}