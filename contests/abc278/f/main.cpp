#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a;
    rep(i, n) {
        str s; cin >> s;
        a.pb({s[0]-'a', s.back()-'a'});
    }
    vvi dp(1<<n, vi(26));
    rep(i, 1<<n) {
        rep(j, n) if (0 == ((i >> j) & 1)) if (dp[i][a[j].se] == 0) {
            dp[i | (1 << j)][a[j].fi] = 1;
        }
    }
    range(i, dp.back()) if (i == 1) {
        cout << "First" << nl;
        return;
    }
    cout << "Second" << nl;
}