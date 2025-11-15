#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n);
    rep(i, n) { int x; cin >> a[i].fi >> a[i].se >> x; }
    int lx = 0, rx = 1e9;
    while (rx - lx > 1) {
        int mx = (lx + rx) / 2;
        int ly = 0, ry = 1e9;
        while (ry - ly > 1) {
            int my = (ly + ry) / 2;
            vpi over, under;
            rep(i, n) {
                if (my <= a[i].fi) over.pb(a[i]);
                else under.pb(a[i]);
            }
            int underdist = 0;
            range(i, under) {
                chmax()
            }
        }
    }
}