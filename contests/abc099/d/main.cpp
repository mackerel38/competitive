#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, c; cin >> n >> c;
    vvi d(c, vi(c)); cin >> d;
    vvi f(n, vi(n)); cin >> f;
    vvll a(3, vll(c));
    rep(i, n) rep(j, n) rep(k, c) a[(i+j)%3][k] += d[f[i][j]-1][k];
    ll ans = INF;
    rep(i, c) rep(j, c) rep(k, c) if (i!=j && j!=k && k!=i) chmin(ans, a[0][i]+a[1][j]+a[2][k]);
    cout << ans << nl;
}