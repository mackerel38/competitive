#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi p(n), c(n); cin >> p >> c;
    vvi a(n+1); rep(i, n) a[c[i]].pb(p[i]);
    ll ans = 0;
    rep1(i, n) {
        int m = a[i].size();
        vi dp(m, inf);
        rep(j, m) *lower_bound(all(dp), a[i][j]) = a[i][j];
        ans += (ll)i * (m-(lower_bound(all(dp), inf)-dp.begin()));
        debug(i);
        debug(ans);
    }
    cout << ans << nl;
}