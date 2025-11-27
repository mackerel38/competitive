#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            seg.add(y, z);
        } else {
            cout << seg.sum(y, z) << nl;
        }
    }
}