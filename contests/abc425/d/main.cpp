#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    int ans = 0;
    vvi cnt(h, vi(w));
    queue<pi> q;
    rep(i, h) rep(j, w) {
        rep(d, 4) {
            int I = i + dxy[d], J = j + dxy[d+1];
            if (ismid(0, I, h) && ismid(0, J, w) && s[I][J] == '#') {
                cnt[i][j]++;
            }
        }
    }
    queue<pi> r;
    rep(i, h) rep(j, w) if (s[i][j] == '.' && cnt[i][j] == 1) q.push({i, j});
    while(!q.empty() || !r.empty()) {
        if (q.empty()) {
            while (!r.empty()) {
                auto [i, j] = r.front(); r.pop();
                if (cnt[i][j] == 1) {
                    q.push({i, j});
                }
            }
            continue;
        }
        auto [x, y] = q.front(); q.pop();
        if (s[x][y] == '#') continue;
        s[x][y] = '#';
        rep(d, 4) {
            int X = x + dxy[d], Y = y + dxy[d+1];
            if (ismid(0, X, h) && ismid(0, Y, w)) {
                cnt[X][Y]++;
                if (cnt[X][Y] == 1) r.push({X, Y});
            }
        }
    }
    range(i, s) debug(i);
    range(i, s) range(j, i) if (j == '#') ans++;
    cout << ans << nl;
}