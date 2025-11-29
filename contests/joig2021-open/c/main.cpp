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
    int c = Sum(a);
    int ans = c;
    rep(i, n) {
        if (a[i] == 1) c--;
        else c++;
        chmin(ans, c);
    }
    cout << ans << nl;
}