#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, t; cin >> h >> w >> t;
    vec<str> s(h); cin >> s;
    int r, y, cnt=0;
    vpi a;
    rep(i, h) rep(j, w) {
        if (s[i][j] == 'S' || s[i][j] == 'G' || s[i][j] == 'o') {
            if (s[i][j] == 'S') r = cnt;
            if (s[i][j] == 'G') y = cnt;
            a.pb({i, j});
            cnt++;
        }
    }
    vvll g(cnt, vll(cnt, INF));
    rep(i, cnt) {
        vvll d(h, vll(w, INF));
        queue<pi> q; q.push(a[i]);
        d[a[i].fi][a[i].se] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            rep(j, 4) {
                int X = x + dxy[j], Y = y + dxy[j+1];
                if (ismid(0, X, h) && ismid(0, Y, w)) {
                    if (s[X][Y] != '#') {
                        if (chmin(d[X][Y], d[x][y] + 1)) {
                            q.push({X, Y});
                        }
                    }
                }
            }
        }
        g[i][i] = 0;
        rep(j, cnt) if (i != j) {
            g[i][j] = d[a[j].fi][a[j].se];
        }
    }
    vvll dp(1<<cnt, vll(cnt, INF));
    dp[1<<r][r] = 0;
    rep(i, 1<<cnt) {
        rep(j, cnt) if (bit(i, j)) if (dp[i][j] < INF) {
            rep(k, cnt) if (0 == bit(i, k)) {
                chmin(dp[i+(1<<k)][k], dp[i][j]+g[j][k]);
            }
        }
    }
    int ans = -1;
    rep(i, 1<<cnt) if (dp[i][y] <= t) {
        chmax(ans, __builtin_popcount(i)-2);
    }
    cout << ans << nl;
}