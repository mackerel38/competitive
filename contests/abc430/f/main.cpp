#include "template"
#include "graphtemplate"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    graph<int, true, false> g(n);
    vi cnt(n);
    rep(i, n-1) {
        if (s[i] == 'L') {
            g.add_edge(i+1, i);
            cnt[i]++;
        } else {
            g.add_edge(i, i+1);
            cnt[i+1]++;
        }
    }
    queue<int> q;
    rep(i, n) if (cnt[i] == 0) q.push(i);
    vi dp(n);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        range(e, g[x]) {
            dp[e.to] += dp[x] + 1;
            q.push(e.to);
        }
    }
    graph<int, true, false> G(n);
    vi cnt2(n);
    rep(i, n-1) {
        if (s[i] == 'L') {
            G.add_edge(i, i+1);
            cnt2[i+1]++;
        } else {
            G.add_edge(i+1, i);
            cnt2[i]++;
        }
    }
    queue<int> Q;
    rep(i, n) if (cnt2[i] == 0) Q.push(i);
    vi dp2(n);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        range(e, G[x]) {
            dp2[e.to] += dp2[x] + 1;
            Q.push(e.to);
        }
    }
    vi ans(n+1);
    rep(i, n) {
        ans[dp[i]]++;
        ans[n-dp2[i]]--;
    }
    rep(i, n-1) ans[i+1] += ans[i];
    rep(i, n) cout << ans[i] << sp;
    cout << nl;
}