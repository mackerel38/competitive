#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll s, a, b, x; cin >> s >> a >> b >> x;
    ll ans = a * s * (x / (a + b));
    x %= a + b;
    ans += min(x, a) * s;
    cout << ans << nl;
}