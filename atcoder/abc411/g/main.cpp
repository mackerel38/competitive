#include "template"
#include "modint"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vvll g(n, vll(n));
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        g[x][y]++;
        g[y][x]++;
    }
    mint ans = 0;
    rep(i, n) rep(j, n) ans += g[i][j] * (g[i][j] - 1) / 2;
    rep(i, n-2) {
        int I = n - i - 1;
        vec<vec<mint>> dp(1<<I, vec<mint>(I, 0));
        rep(p, I) if (g[i][i+p+1]) dp[1<<p][p] = g[i][i+p+1];
        rep1(j, (1<<I)-1) {
            if (__builtin_popcount(j) == 1) continue;
            rep(p, I) {
                if (j >> p & 1) {
                    int cur = i + p + 1;
                    rep(pre, I) {
                        if (bit(j^(1<<p), pre)) {
                            int pre2 = i + pre + 1;
                            if (g[pre2][cur]) dp[j][p] += dp[j^(1<<p)][pre] * g[pre2][cur];
                        }
                    }
                }
            }
        }
        rep(j, 1<<I) {
            if (__builtin_popcount(j) == 1) continue;
            rep(p, I) {
                if (j >> p & 1) if (g[i+p+1][i]) ans += dp[j][p] * g[i+p+1][i];
            }
        }
    }
    // なぜか2倍
    ans /= 2;
    cout << ans.val << nl;
}

/*
考察
サイクルの始点を固定してTSPみたいな
サイクルの長さ持たないと計算できない
始点をサイクル内の最小にするとできる？
定義的に事故ループが含まれないようになる
事故ループは別で計算する
n-1 と n-2 は最小になり得ない
*/