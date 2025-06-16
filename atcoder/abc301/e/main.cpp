#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, t; cin >> h >> w >> t;
    vec<str> s(h); cin >> s;
    vvvi dp(h, vvi(w, vi(19, inf)));
    int sx = 0, sy = 0, gx = 0, gy = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') {
                sx = i, sy = j;
            } else if (s[i][j] == 'G') {
                gx = i, gy = j;
            }
        }
    }
    dp[sx][sy][0] = 0;
    queue<pair<pi, int>> q;
    q.push({{sx, sy}, 0});
    while (!q.empty()) {
        auto [p, d] = q.front(); q.pop();
        int x = p.first, y = p.second;
        if (d == t) continue; // max distance
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) + abs(j) != 1) continue; // only orthogonal moves
                int nx = x + i, ny = y + j;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#') continue;
                if (dp[nx][ny][d + 1] > dp[x][y][d] + 1) {
                    dp[nx][ny][d + 1] = dp[x][y][d] + 1;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
    }
    
}