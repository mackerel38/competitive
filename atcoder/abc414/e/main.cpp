#include "template"
#include "modint"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n; cin >> n;
    mint m = mint(n);
    mint ans = m * (m + 1) / 2;
    ll t = 1;
    for (ll i=1; i<=n; i=t+1) {
        ll x = n / i;
        t = n / x;
        ans -= mint(x) * (t - i + 1);
    }
    cout << ans << nl;  
}