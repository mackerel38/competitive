#include "template"
#include "rollinghash"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str s; cin >> n >> s;
    RollingHash rh(s), rh2(s);
    int ans = 0;
    rep(i, n) for (int j=i+1; j<n; j++) chmax(ans, Min(rh.lcp(rh, i, j), n-j, j-i));
    cout << ans << nl;
}