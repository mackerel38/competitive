#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n), b(n); cin >> a >> b;
    ll ans = 0;
    rep(i, n) ans += min(a[i], b[i]);
    while (q--) {
        char c; ll x, y; cin >> c >> x >> y; x--;
        ans -= min(a[x], b[x]);
        if (c == 'A') a[x] = y;
        else b[x] = y;
        ans += min(a[x], b[x]);
        cout << ans << nl;
    }
}