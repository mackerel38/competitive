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
    rep(i, n) a[i]--;
    vi b(n); rep(i, n) b[a[i]]++;
    ll ans = 1;
    rep(i, n-1) {
        b[a[i]]--;
        if (a[i] == a[i+1]) continue;
        ans += n-1-i-b[a[i]];
        debug(i);
        debug(ans);
    }
    cout << ans << nl;
}