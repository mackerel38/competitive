#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    map<ll, int> cnt;
    ll ans = 0;
    rep(i, n) {
        if (cnt.count(i-a[i])) {
            ans += cnt[i-a[i]];
        }
        cnt[i+a[i]]++;
    }
    cout << ans << nl;
}