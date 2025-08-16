#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    assert(n <= 16);
    vpi a(n), b(n); cin >> a >> b;
    vvll dp(n+1, vll(1<<n, INF)); dp[0][0] = 0;
    rep(i, n) {
        rep(j, 1<<n) {
            rep(k, n) if (0==(j&(1<<k)) && a[i].se<=b[k].se) {
                chmin(dp[i+1][j|(1<<k)], dp[i][j]+(a[i].fi!=b[k].fi));
            }
        }
    }
    debug(dp);
    cout << dp[n].back() << nl;
}