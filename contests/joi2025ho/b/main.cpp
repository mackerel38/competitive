#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n), b(n); cin >> a >> b;
    vll dp(2*n); dp.back() = a.back();
    per(i, 2*n-1) dp[i] = max(a[i%n], dp[i+1]-b[i%n]);
    ll ans = INF; rep(i, n) chmin(ans, dp[i]);
    cout << ans << nl;
}