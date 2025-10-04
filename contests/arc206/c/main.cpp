#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    rep(i, n) a[i]--;
    vll dp(n+1), dp2(n+1); dp[0] = 1;
    rep(i, n) {
        if (i != n-1) {
            if (a[i] == -1 || a[i] == i + 1) dp[i+1] = dp[i];
            if (a[i] != i+1) {
                dp2[i+1] = dp2[i];
            }
        } elif (a[i] == -1) {
            dp2[i+1] = dp2[i];
        } else {
            ;
        }
    }
}