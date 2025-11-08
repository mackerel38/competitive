#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, w; cin >> n >> w;
    vpi a(n); cin >> a;
    vvll dp(n+1, vll(w+1, -INF)); dp[0][0] = 0;
    rep(i, n) rep(j, w) {
        if (j+a[i].fi <= w) chmax(dp[i+1][j+a[i].fi], dp[i][j]+a[i].se);
        chmax(dp[i+1][j], dp[i][j]);
    }
    cout << Max(dp.back()) << nl;
}