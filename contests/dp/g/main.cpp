#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, true, false> g(n); g.read(m);
    vi cnt(n); range(i, g._edges) cnt[i.to]++;
    queue<int> q;
    vi dp(n);
    rep(i, n) if (cnt[i] == 0) q.push(i);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        range(i, g[x]) {
            chmax(dp[i.to], dp[i.from]+1);
            if (--cnt[i.to] == 0) q.push(i.to);
        }
    }
    cout << Max(dp) << nl;
}