#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    vi t(w);
    rep(i, w) {
        int m = 0;
        rep(j, h) {
            if (s[j][i] == '#') m |= (1 << j);
        }
        t[i] = m;
    }
    debug(t);
    vvi a(w), cost(w, vi(1<<h, inf));
    rep(i, w) {
        for (int j = 0; j < (1<<h); ++j) {
            if ((j & ~t[i]) == 0) {
                a[i].push_back(j);
                cost[i][j] = __builtin_popcount(t[i]) - __builtin_popcount(j);
            }
        }
    }
    debug(a);
    vvi p(1<<h, vi(1<<h, 0));
    rep(i, 1<<h) rep(j, 1<<h) {
        int x = i & j;
        if ((x & (x >> 1)) == 0) p[i][j] = 1;
    }
    vvi dp(w, vi(1<<h, inf));
    for (int m : a[0]) dp[0][m] = cost[0][m];
    rep1(i, w-1) {
        for (int j : a[i]) {
            for (int k : a[i-1]) {
                if (dp[i-1][k] == inf) continue;
                if (p[k][j]) chmin(dp[i][j], dp[i-1][k] + cost[i][j]);
            }
        }
    }
    debug(dp);
    cout << Min(dp.back()) << nl;
}
