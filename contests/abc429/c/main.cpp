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
    vll b(n);
    rep(i, n) a[i]--;
    rep(i, n) b[a[i]]++;
    ll ans = 0;
    rep(i, n) {
        ans += b[i] * (b[i] - 1) / 2 * (n - b[i]);
    }
    cout << ans << nl;
}