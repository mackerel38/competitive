#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; str s; cin >> n >> q >> s;
    vll d(n, INF);
    rep(i, 2*n) {
        if (s[i%n] != s[(i+1)%n]) d[(i+1)%n] = 1;
        else chmin(d[(i+1)%n], d[i%n]+1);
    }
    per(i, 2*n) {
        if (s[i%n] != s[(i-1+n)%n]) d[(i-1+n)%n] = 1;
        else chmin(d[(i-1+n)%n], d[i%n]+1);
    }
    debug(d);
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        if (s[x] == s[y]) {
            cout << 1 << nl;
            continue;
        }
        int ans = 3;
        chmin(ans, min(abs(x-y), n-abs(x-y)));
        chmin(ans, 1+min(d[x], d[y]));
        cout << ans << nl;
    }
}