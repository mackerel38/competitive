#include "template"
#include "modint"
#include "isqrt"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int m = isqrt(n);
    vll a(n); cin >> a;
    vec<mint> dp(n); dp[0] = mint(1);
    vec<vec<mint>> dp2(m, vec<mint>(m));
    rep(i, n) {
        rep1(j, m-1) {
            dp[i] += dp2[j][i%j];
        }
        if (m <= a[i]) for (int j=i+a[i]; j<n; j+=a[i]) {
            dp[j] += dp[i];
        } else {
            dp2[a[i]][i%a[i]] += dp[i];
        }
    }
    cout << Sum(dp) << nl;
}