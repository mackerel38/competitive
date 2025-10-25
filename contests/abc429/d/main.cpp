#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m, c; cin >> n >> m >> c;
    vll a(n); cin >> a;
    Sort(a);
    vll b(2*n);
    rep(i, n) b[i] = a[i];
    rep(i, n) b[i+n] = a[i] + m;
    ll ans = 0;
    rep(i, n+1) {
        ll l;
        if (i == 0) l = a[i];
        elif (i == n) l = m - a[i-1];
        else l = a[i] - a[i-1];
        ll r = i + c - 1;
        ll nex = upper_bound(all(b), b[r]) - b.begin();
        ans += l * (nex - i);
    }
    cout << ans << nl;
}