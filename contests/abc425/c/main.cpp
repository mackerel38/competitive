#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    vll b(n+1);
    rep(i, n) b[i+1] = b[i] + a[i];
    ll c = 0;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y; cin >> y;
            c += y;
        } else {
            ll x, y; cin >> x >> y; x--;
            x += c; y += c;
            if (x/n != y/n) {
                y -= n;
                cout << (b[n]-b[x%n]) + (b[y%n]-b[0]) << nl;
            } else {
                cout << b[y%n] - b[x%n] << nl;
            }
        }
    }
}