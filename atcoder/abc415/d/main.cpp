#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m; cin >> n >> m;
    vpll a(m); cin >> a;
    sort(a.begin(), a.end(), [](pll x, pll y) {
        if (x.first-x.second != y.first-y.second) return x.first-x.second < y.first-y.second;
        else return x.first < y.first;
    });
    debug(a);
    int c = 0;
    ll ans = 0;
    while (c < m) {
        debug(c); debug(ans);
        auto [x, y] = a[c++];
        ll d = x - y;
        if (n < x) continue;
        ll z = (n - x + d) / d;
        ans += z;
        n -= z * d;
    }
    cout << ans << nl;
}