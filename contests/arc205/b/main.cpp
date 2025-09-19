#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m; cin >> n >> m;
    vi a(n);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        a[x]++;
        a[y]++;
    }
    int cnt = 0;
    rep(i, n) cnt += a[i] % 2;
    cout << n*(n-1)/2-(n%2==0 ? (n-cnt)/2 : cnt/2) << nl;
}