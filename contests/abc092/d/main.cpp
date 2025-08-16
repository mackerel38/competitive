#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int a, b; cin >> a >> b;
    vvi f(100, vi(100, 0));
    rep(i, 50) rep(j, 100) f[i][j] = 1;
    rep(i, a-1) f[i*2/100*2][i*2%100] = 0;
    rep(i, b-1) f[99-i*2/100*2][99-i*2%100] = 1;
    cout << 100 << sp << 100 << nl;
    rep(i, 100) {
        rep(j, 100) cout << (f[i][j] ? '#' : '.');
        cout << nl;
    }
}