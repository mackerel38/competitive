#include "template"
#include "prime"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll x; cin >> x;
    x = 4 * x - 1;
    vll ans;
    for (ll i=1; i*i<=abs(x); i+=2) {
        if (x % i) continue;
        ll y = x / i;
        debug(i);debug(y);
        if (abs((y-i)%4) == 2) ans.pb((y-i-2)/4);
    }
    for (ll i=-1; i*i<=abs(x); i-=2) {
        if (x % i) continue;
        ll y = x / i;
        debug(i);debug(y);
        if (abs((y-i)%4) == 2) ans.pb((y-i-2)/4);
    }
    uniq(ans);
    cout << ans.size() << nl << ans;
}