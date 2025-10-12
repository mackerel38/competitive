#include "template"

int main() {
    IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int c, x; cin >> c >> x;
    ll ans = c ^ x;
    if (ismid(x+1, ans, 1LL<<60)) {
        cout << ans << nl;
        return;
    }
    if (c < x) {
        cout << -1 << nl;
        return;
    }
    if ((c-x)%2 == 0) {
        ll t = (c - x) / 2;
        if ((t&~c) == 0) {
            ll n = t | (1LL<<58);
            cout << n << nl;
            return;
        }
    }
    cout << -1 << nl;
}