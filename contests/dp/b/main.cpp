#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    vll dp(n, INF); dp[0] = 0;
    rep1(i, n-1) {
        rep1(j, min(i, k)) {
            chmin(dp[i], dp[i-j] + abs(a[i]-a[i-j]));
        }
    }
    cout << dp.back() << nl;
}