#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s, t; cin >> s >> t;
    int S = s.size(), T = t.size();
    vvi dp(S+1, vi(T+1));
    rep(i, S) rep(j, T) {
        if (s[i] == t[j]) {
            dp[i+1][j+1] = dp[i][j] + 1;
        }
        chmax(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
    }
    str ans = "";
    while (0<S && 0<T) {
        if (dp[S][T] == dp[S][T-1]) { T--; }
        elif (dp[S][T] == dp[S-1][T]) { S--; }
        elif (dp[S][T] == dp[S-1][T-1]+1) { S--; T--; ans += s[S]; }
    }
    Reverse(ans);
    cout << ans << nl;
}