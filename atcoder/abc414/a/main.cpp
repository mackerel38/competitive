#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int l, r; cin >> l >> r;
    int ans = 0;
    rep(i, n) {
        int x, y; cin >> x >> y;
        if (x <=l && r<=y) ans++;
    }
    cout << ans << nl;
}