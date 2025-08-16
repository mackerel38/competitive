#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    str s, t; cin >> s >> t;
    vi a(n+1);
    while (q--) {
        int l, r; cin >> l >> r; l--;
        a[l]++; a[r]--;
    }
    int x = 0;
    rep(i, n) {
        x = (x + a[i]) % 2;
        if (x) {
            cout << t[i];
        } else {
            cout << s[i];
        }
    }
    cout << nl;
}