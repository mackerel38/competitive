#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vpi c(n-1); cin >> c;
    vll d(840);
    rep(i, 840) {
        ll t = i;
        t += a;
        rep(j, n-1) {
            t = ((t - 1) / c[j].fi + 1) * c[j].fi;
            t += c[j].se;
        }
        t += b;
        d[i] = t;
    }
    int q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        cout << x - x%840 + d[x%840] << nl;
    }
}