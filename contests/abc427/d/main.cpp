#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    str s; cin >> s;
    graph<int, true, false> g(n); g.read(m);
    vvi dp(2*k+1, vi(n));
    rep(i, n) if (s[i] == 'A') dp[2*k][i] = 1;
    per(i, 2*k) range(e, g._edges) if (dp[i+1][e.to] == 0) dp[i][e.from] = 1;
    cout << (dp[0][0] ? "Alice" : "Bob") << nl;
}