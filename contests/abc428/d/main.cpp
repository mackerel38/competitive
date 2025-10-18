#include "template"
#include "isqrt"
ll dig(ll x) {
    str s = to_string(x);
    return (ll)s.size();
}
int main() {
    IO();
    ll T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ll c, d; cin >> c >> d;
    ll ans = 0;
    ll m = dig(c);
    ll M = dig(c+d);
    vll po(M+1); po[0] = 1;
    rep1(i, M) po[i] = po[i-1] * 10;
    for (ll i=m; i<=M; i++) {
        ll x = max(1LL, po[i-1]-c);
        ll y = min(d, po[i]-1-c);
        if (y < x) continue;
        ll a = c * (po[i] + 1);
        ll mans = isqrt(a + x);
        if (mans*mans < a+x) mans++;
        ll Mans = isqrt(a + y);
        ans += max(0LL, Mans-mans+1);
    }
    cout << ans << nl;
}