#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n); cin >> a;
    troS(a);
    vpi b = a;
    sort(b.begin(), b.end(), [](pi x, pi y) {
        return x.se < y.se;
    });
    ll ans = 0;
    rep(i, n) {
        ll x = a[i].fi - b[i].se;
        if (0 < x) {
            ans += x * (n - (2 * i + 1));
        }
    }
    cout << ans << nl;
}