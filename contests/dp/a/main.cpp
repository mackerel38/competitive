#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vll dp(n, INF); dp[0] = 0;
    rep(i, n) {
        if (1 <= i) chmin(dp[i], dp[i-1] + abs(a[i]-a[i-1]));
        if (2 <= i) chmin(dp[i], dp[i-2] + abs(a[i]-a[i-2]));
    }
    cout << dp.back() << nl;
}