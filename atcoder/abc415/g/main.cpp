#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
#define k 300
void solve() {
    ll n, m; cin >> n >> m;
    vpll a(m); cin >> a;
    vll dp(k);
    rep(i, k) {
        rep(j, m) {
            if (a[j].first <= i) {
                chmax(dp[i], dp[i-(a[j].first-a[j].second)] + a[j].second);
            }
        }
    }
    int t=0;
    rep1(i, m-1) if (a[t].second < a[i].second) t = i;
    ll d = a[t].first - a[t].second;
    ll u = n;
    if (k <= n) u -= (n - k + d - 1) / d * d;
    ll ans = n + dp[u] + u / d * a[t].second;
    cout << ans << nl;
}