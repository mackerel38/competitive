#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str t; cin >> t;
    vll dp(1<<n);
    dp[0] = 1;
    rep1(k, (1<<n)-1) {
        rep(i, n) if (bit(k, i)){
            int K = k&((1<<i)-1);
            if (K) {
                int j = 31 - __builtin_clz(K);
                if (t[i] == t[j]) continue;
            }
            dp[k] = (dp[k] + dp[k^(1<<i)]) % mod;
        }
    }
    cout << dp.back() << nl;
}