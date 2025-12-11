#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    ll ans = 0;
    rep(i, n) {
        ans += a[i] / 3;
        a[i] %= 3;
        if (a[i]) if (i < n-1) {
            if (3 <= a[i+1]+a[i]) {
                a[i+1] -= 3 - a[i];
                a[i] = 0;
                ans++;
            }
        }
    }
    cout << ans << nl;
}