#include "template"

int main() {
    IO();
    ll T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll q; cin >> q;
    set<ll> s;
    map<ll, ll> l, r;
    ll ans = 0;
    {
        q--;
        ll x; cin >> x;
        s.insert(0);
        s.insert(x);
        l[0] = INF; r[0] = x;
        l[x] = x; r[x] = INF;
        ans += min(l[0], r[0]) + min(l[x], r[x]);
        cout << ans << nl;
    }
    while (q--) {
        ll x; cin >> x;
        auto it = s.lower_bound(x);
        ll R = *it;
        if (it == s.end()) {
            it--;
            ll L = *it;
            ans -= min(l[L], r[L]);
            l[x] = x-L; r[x] = INF;
            r[L] = x-L;
            ans += min(l[x], r[x]) + min(l[L], r[L]);
            s.insert(x);
            cout << ans << nl;
            continue;
        }
        it--;
        ll L = *it;
        ans -= min(l[L], r[L]) + min(l[R], r[R]);
        l[x] = x-L; r[x] = R-x;
        l[R] = R-x; r[L] = x-L;
        ans += min(l[x], r[x]) + min(l[L], r[L]) + min(l[R], r[R]);
        s.insert(x);
        cout << ans << nl;
    }
}