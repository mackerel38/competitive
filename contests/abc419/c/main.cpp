#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpll a(n); cin >> a;
    ll x=INF, X=-INF, y=INF, Y=-INF;
    range(i, a) {
        chmin(x, i.fi);
        chmax(X, i.fi);
        chmin(y, i.se);
        chmax(Y, i.se);
    }
    ll xm = (x + X) / 2, ym = (y + Y) / 2;
    ll ans = 0;
    range(i, a) {
        chmax(ans, max(abs(i.fi-xm), abs(i.se-ym)));
    }
    cout << ans << nl;
}