#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, false, false> g(n);
    g.read(m);
    ll ans = INF;
    rep(i, 1<<n) {
        ll ans2 = 0;
        range(e, g._edges) {
            if (bit(i, e.from) == bit(i, e.to)) {
                ans2++;
            }
        }
        chmin(ans, ans2);
    }
    cout << ans << nl;
}