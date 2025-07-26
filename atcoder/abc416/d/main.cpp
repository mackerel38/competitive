#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m; cin >> n >> m;
    vll a(n), b(n); cin >> a >> b;
    troS(a); Sort(b);
    ll ans = Sum(a) + Sum(b);
    ll c = 0;
    rep(i, n) {
        while (c<n && a[i]+b[c]<m) c++;
        if (c == n) break;
        ans -= m;
        c++;
    }
    cout << ans << nl;
}