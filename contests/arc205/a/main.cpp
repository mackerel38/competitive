#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vec<str> f(n); cin >> f;
    vvi a(n, vi(n));
    rep(i, n-1) rep(j, n-1) {
        int cnt = 0;
        rep(di, 2) rep(dj, 2) {
            if (f[i+di][j+dj] == '.') cnt++;
        }
        if (cnt == 4) a[i+1][j+1] = 1;
    }
    vvi b = a;
    rep(i, n-1) rep(j, n) b[i+1][j] += b[i][j];
    rep(i, n) rep(j, n-1) b[i][j+1] += b[i][j];
    debug(b);
    while (q--) {
        int u, d, l, r; cin >> u >> d >> l >> r; u--; d--; l--; r--;
        cout << b[d][r] + b[u][l] - b[d][l] - b[u][r] << nl;
    }
}