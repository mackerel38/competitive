#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    rep(i, n) {
        cout << (i < m ? "OK" : "Too Many Requests") << nl;
    }
}