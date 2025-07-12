#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vll a(n); cin >> a;
    if (n == m) {
        cout << 0 << nl;
        return;
    }
    Sort(a);
    vll b(n-1); rep(i, n-1) b[i] = a[i+1] - a[i];
    Sort(b);
    ll t = b[n-m-1];
    ll ans = 0;
    int cnt = 0;
    rep(i, n-1) {
        if (b[i] <= t && cnt < n-m) {
            cnt++;
            ans += b[i];
        }
    }
    cout << ans << nl;
}