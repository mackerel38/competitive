#include "template"
#include "modint"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vpi g;
    rep(i, n) g.pb({i, i});
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        g.pb({x, y});
        g.pb({y, x});
    }
    vec<vec<mint>> dp(k+1, vec<mint>(n)); dp[0][0] = mint(1);
    rep(i, k) {
        mint s = 0;
        range(j, dp[i]) s += j;
        rep(j, n) dp[i+1][j] = s;
        range(j, g) {
            dp[i+1][j.se] -= dp[i][j.fi];
        }
    }
    cout << dp[k][0] << nl;
}