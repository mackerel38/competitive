#include "template"
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a(n, m);
    vi ans;
    while (k--) {
        int x, y; cin >> x >> y; x--;
        a[x]--;
        if (a[x] == 0) ans.pb(x+1);
    }
    cout << ans << nl;
}