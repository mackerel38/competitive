#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "template"
#include "lazysegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    lazysegtree<ll,[](ll x,ll y){return x+y;},[](){return 0LL;},ll,[](ll x,ll y){return x+y;},[](ll x,ll y){return x+y;},[](){return 0LL;}> seg(a);
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            seg.set(y, seg[y]+z);
        } else {
            cout << seg.prod(y, z) << nl;
        }
    }
}