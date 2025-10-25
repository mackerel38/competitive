#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    ll s = Sum(a);
    rep(i, n) {
        if (s - a[i] == m) {
            Yes;
            return;
        }
    }
    No;
}