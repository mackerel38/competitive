#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vi a(n); cin >> a;
    Sort(a);
    ll ans = 0;
    range(i, a) {
        ll Y = i - a[0];
        ll t = Y * y / (y - x);
        if (Y * y % (y - x)) {
            cout << -1 << nl;
            return;
        } elif (i - t < 0) {
            cout << -1 << nl;
            return;
        }
        ans += i - t;
    }
    cout << ans << nl;
}