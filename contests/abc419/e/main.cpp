#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, l; cin >> n >> m >> l;
    vi a(n); cin >> a;
    vvi b(l);
    rep(i, n) b[i%l].pb(a[i]);
    vvll dp(l+1, vll(m, INF)); dp[0][0] = 0; // dp[i][j]: = iコメまでをmodmでjにするときのコスト
    rep(i, l) {
        vll x(m);
        rep(j, m) {
            range(k, b[i]) {
                x[j] += ((j - k) % m + m) % m;
            }
        }
        rep(j, m) rep(k, m) chmin(dp[i+1][(j+k)%m], dp[i][j]+x[k]);
    }
    cout << dp[l][0] << nl;
}