#include "template"
#include "segtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int N = 2 * n;
    vi a(N); vll v(N); cin >> a >> v; range(i, a) i--;
    segtree<ll, [](ll x, ll y){ return max(x, y); }, [](){ return 0LL; }> dp(N+1);
    segtree<ll, [](ll x, ll y){ return max(x, y); }, [](){ return -INF; }> dp2(N+1);
    vi b(n); rep(i, N) b[a[i]] = i+1;
    rep(i, N) {
        if (b[a[i]] != i+1) {
            dp.set(b[a[i]]-1, max(dp[b[a[i]]]-1, max(dp.prod(0, i), dp2.prod(i+1, b[a[i]]))+v[a[i]]));
            dp2.set(b[a[i]]-1, dp.prod(0, i)+v[a[i]]);
        } else dp2.set(i, 0LL);
    }
    cout << dp.all_prod() << nl;
}