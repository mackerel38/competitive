#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

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
    lazysegtree<ll,[](ll x,ll y){return x+y;},[](){return 0LL;},ll,[](){return;},[](){return;},[](){return 0LL;}> seg(a);
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int y; ll z; cin >> y >> z;
            seg.set(y, z);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r) << nl;
        }
    }
}