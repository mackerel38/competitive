#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vvll s(h, vll(w)); cin >> s;
    vvll dp(h, vll(w, INF));
    ll k = h + w - 1;
    vll p(k); cin >> p;
    dp.back().back() = max(0LL, p.back()-s.back().back());
    per1(i, k-1) {
        for (int x=max(0LL, h-(k-i)); x < h; x++) {
            int y = i - x;
            if (ismid(0, y, w)) {
                if (0 < x) {
                    chmin(dp[x-1][y], max(0LL, dp[x][y] + p[i-1] - s[x-1][y]));
                }
                if (0 < y) {
                    chmin(dp[x][y-1], max(0LL, dp[x][y] + p[i-1] - s[x][y-1]));
                }
            } else break;
        }
    }
    debug(dp);
    cout << dp[0][0] << nl;
}