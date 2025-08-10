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
    int plus = 1;
    ll ans = INF;
    rep(i, 2) {
        if (i) plus = 0;
        ll ans2 = 0;
        ll c = 0;
        rep(j, n) {
            if (plus) {
                if (c+a[j] <= 0) {
                    ans2 += 1 - (c + a[j]);
                    c = 1;
                } else {
                    c += a[j];
                }
            } else {
                if (0 <= c+a[j]) {
                    ans2 += (c + a[j]) + 1;
                    c = -1;
                } else {
                    c += a[j];
                }
            }
            plus = 1 - plus;
        }
        chmin(ans, ans2);
    }
    cout << ans << nl;
}