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
    vvvll d(h, vvll(w, vll(2, INF))); // d[i][j][k] := (i, j) にk の状態で到達
    int sx, sy;
    rep(i, h) rep(j, w) if (s[i][j] == 'S') {
        sx = i;
        sy = j;
    }
    int gx, gy;
    rep(i, h) rep(j, w) if (s[i][j] == 'G') {
        gx = i;
        gy = j;
    }
    queue<pair<pll, int>> q; q.push({{sx, sy}, 0});
    d[sx][sy][0] = 0;
    while (!q.empty()) {
        auto [X, z] = q.front(); auto [x, y] = X; q.pop();
        rep(i, 4) {
            int nx = x + dxy[i], ny = y + dxy[i+1];
            if (ismid(0, nx, h) && ismid(0, ny, w)) {
                if (s[nx][ny] == '#' || (s[nx][ny]=='o' && z==1) || (s[nx][ny]=='x' && z==0)) continue;
                if (s[nx][ny] == '?') {
                    if (chmin(d[nx][ny][1-z], d[x][y][z]+1)) {
                        q.push({{nx, ny}, 1-z});
                    }
                } else {
                    if (chmin(d[nx][ny][z], d[x][y][z]+1)) {
                        q.push({{nx, ny}, z});
                    }
                }
            }
        }
    }
    cout << (Min(d[gx][gy])<INF ? Min(d[gx][gy]) : -1) << nl;
}