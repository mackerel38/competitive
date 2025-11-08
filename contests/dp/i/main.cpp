#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<ld> a(n); cin >> a;
    vec<vec<ld>> dp(n+1, vec<ld>(n+1)); dp[0][0] = 1.;
    rep(i, n) rep(j, n) {
        dp[i+1][j+1] += dp[i][j]*a[i];
        dp[i+1][j] += dp[i][j]*(1-a[i]);
    }
    ld ans = 0.;
    loop(i, (n+1)/2, n+1) ans += dp.back()[i];
    cout << ans << nl;
}