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
    int c=0; range2(i, j, a) c += j;
    vvll dp(n+1, vll(c+1, INF)); dp[0][0] = 0;
    rep(i, n) rep(j, c) {
        chmin(dp[i+1][j], dp[i][j]);
        if (j+a[i].se <= c) chmin(dp[i+1][j+a[i].se], dp[i][j]+a[i].fi);
    }
    per(i, c+1) {
        if (dp.back()[i] <= w) {
            cout << i << nl;
            return;
        }
    }
}