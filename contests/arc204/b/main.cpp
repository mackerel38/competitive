#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n*k); cin >> a;
    range(i, a) i--;
    vi b(n*k, -1);
    int cnt = 0;
    rep(i, n*k) {
        if (0 <= b[i]) continue;
        b[i] = cnt;
        for (int j=a[i]; j!=i; j=a[j]) b[j] = cnt;
        cnt++;
    }
    vvi c(cnt, vi(n));
    rep(i, n*k) c[b[i]][i%n]++;
    int ans = 0;
    range(i, c) {
        range(j, i) {
            ans += j / 2;
        }
    }
    cout << ans << nl;
}