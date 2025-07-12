#include "template"
#include "graphtemplate"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    graph<ll, false, false> g(n); g.read(n-1);
    vvi cnt(n, vi(k)); cnt[0][0] = 1;
    vvi dp(n, vi(k, inf));
    dp[0][0] = 0;
    queue<pair<pi, pi>> q; q.push({{0, 0}, {-1, 0}});
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        int v = x.fi.fi, d = x.fi.se, from = x.se.fi;
        int tok = (d + 1) % k;
        int tod = x.se.se; if (d == 0) tod++;
        range(e, g[v]) {
            if (e.to == from && d != 0) continue;
            if (chmin(dp[e.to][tok], tod) || cnt[e.to][tok] < 5) {
                cnt[e.to][tok]++;
                q.push({{e.to, tok}, {v, tod}});
            }
        }
    }
    debug(dp);
    rep1(i, n-1) {
        auto x = dp[i][0];
        if (inf == x) cout << -1 << sp;
        else {
            cout << x << sp;
        }
    }
    cout << nl;
}