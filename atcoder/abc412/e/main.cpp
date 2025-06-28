#include "template"
#include "prime"
#include "isqrt"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll l, r;  cin >> l >> r;
    ll rr = isqrt(r) + 1;
    vi p = enumprimes(rr);
    vi flags(r-l+1, 1);
    for (ll i : p) {
        ll x = max(i * i, ((l + i - 1) / i) * i);
        for (ll j=x; j<=r; j+=i) flags[j-l] = 0;
    }
    int cnt = 0;
    for (ll i=l+1; i<=r; i++) if (flags[i-l]) cnt++;
    unordered_set<ll> m; m.reserve(1729);
    for (ll i : p) {
        ll x = i * i;
        while (x <= r) {
            if (x > l) m.insert(x);
            if (x > r / i) break;
            x *= i;
        }
    }
    cout << 1 + cnt + m.size() << nl;
}
