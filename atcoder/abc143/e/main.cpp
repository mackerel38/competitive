#include "template"
#include "warshallfloyd"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, l; cin >> n >> m >> l;
    graph<ll, false, true> g(n); g.read(m);
    vvll d = warshallfloyd(g);
    graph<ll, false, false> g2(n);
    rep(i, n) rep(j, n) {
        if (d[i][j] <= l) {
            g2.add_edge(i, j);
        }
    }
    vvll d2 = warshallfloyd(g2);
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        if (INF <= d2[x][y]) cout << -1 << nl;
        else cout << d2[x][y]-1 << nl;
    }
}