#include "template"
#include "modint"

int main() {
    IO();
    setmod(1000000007);
    buildfac(1000000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    vll a(n); cin >> a;
    mint ans = 0;
    Sort(a);
    rep(i, n-1) {
        ans -= a[i] * comb(n-i-1, k-1);
    }
    per1(i, n-1) {
        ans += a[i] * comb(i, k-1);
    }
    cout << ans << nl;
}