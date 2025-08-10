#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template"
#include "dynamicsegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    auto op=[](ll x,ll y)->ll{return x+y;};
    auto e=[]()->ll{return 0;};
    dynamicsegtree<ll, op, e> s(n);
    rep(i, n) {
        int x; cin >> x;
        s.set(i, x);
    }
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            s.set(y, z+s.get(y));
        } else {
            cout << s.prod(y, z) << nl;
        }
    }
}