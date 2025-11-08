#include "template"
#include "atcoder/modint"
using namespace atcoder;
using mint = modint1000000007;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    vec<vec<mint>> dp(h, vec<mint>(w)); dp[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (i+1 < h) if (s[i+1][j] == '.') dp[i+1][j] += dp[i][j];
        if (j+1 < w) if (s[i][j+1] == '.') dp[i][j+1] += dp[i][j];
    }
    cout << dp.back().back().val() << nl;
}