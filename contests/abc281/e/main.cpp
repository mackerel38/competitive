#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vll a(n); cin >> a;
    if (m == k) {
        ll ans = 0;
        rep(i, m) ans += a[i];
        cout << ans << sp;
        rep(i, n-m) {
            ans += a[i+m]-a[i];
            cout << ans << sp;
        }
        cout << nl;
        return;
    }
    ll sum = 0;
    set<pll> s, S;
    rep(i, m) S.insert({a[i], i});
    rep(i, k) {
        s.insert(*S.begin());
        sum += (*S.begin()).fi;
        S.erase(S.begin());
    }
    cout << sum << sp;
    rep(i, n-m) {
        s.erase({a[i], i});
        S.erase({a[i], i});
        S.insert({a[i+m], i+m});
        if (s.size() != k) {
            sum -= a[i];
            sum += (*S.begin()).fi;
            s.insert(*S.begin());
            S.erase(*S.begin());
        }
        while ((*s.rbegin()).fi > (*S.begin()).fi) {
            sum -= (*s.rbegin()).fi;
            S.insert(*s.rbegin());
            s.erase(*s.rbegin());
            sum += (*S.begin()).fi;
            s.insert(*S.begin());
            S.erase(*S.begin());
        }
        cout << sum << sp;
    }
    cout << nl;
}
