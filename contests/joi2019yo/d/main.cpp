#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vi b = a; uniq(b);
    vvi c(n);
    rep(i, n) c[lower_bound(all(b), a[i]) - b.begin()].pb(i+1);
    vi flag(n+2, 1); flag[0] = flag.back() = 0;
    int cur = 1;
    int ans = (Min(a)==0 ? 0 : 1);
    range(i, c) {
        range(j, i) {
            cur += flag[j-1] + flag[j+1] - 1;
            flag[j] = 0;
        }
        chmax(ans, cur);
        debug(cur);
    }
    cout << ans << nl;
}