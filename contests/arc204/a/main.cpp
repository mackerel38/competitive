#include "template"
#include "modint"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

mint solve2(int n, int k, vi a, vi b) {
    ll p = Sum(b) - Sum(a);
    ll t = k - p;
    if (t < 0) return mint(0);
    vi a2(n+1), b2(n+1);
    rep(i, n) a2[i+1] = a2[i] + a[i];
    rep(i, n) b2[i+1] = b2[i] + b[i];
    vec<mint> dp(n+1), ndp(n+1);
    dp[0] = mint(1);
    rep(i, n+1) {
        rep(j, i) dp[j+1] += dp[j];
        if (i == n) break;
        fill(all(ndp), mint(0));
        rep(j, i+1) {
            ll y = b2[j] - a2[i];
            if (a[i] - t <= y) ndp[j] += dp[j];
        }
        swap(dp, ndp);
        debug(dp);
    }
    return dp.back();
}

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vi a(n), b(n); cin >> a >> b;
    cout << solve2(n, r, a, b) - solve2(n, l-1, a, b) << nl;
}