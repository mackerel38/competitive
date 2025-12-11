#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    Sort(a);
    vll b(n+1); rep1(i, n) b[i] = b[i-1] + a[i-1];
    while (q--) {
        ll x, y; cin >> x >> y;
        ll t = x / y;
        if (n <= t) {
            cout << b.back() << nl;
            continue;
        }
        ll backv = a[n-t-1];
        ll kb = (backv + y - 1) / y;
        auto f = [&](ll z) -> ll {
            ll m = y  * z;
            int it = upper_bound(all(a), m) - a.begin();
            int ti = n - it;
            return b.back()-b[it]-y*z*ti+x*z;
        };
        cout << min(f(max(0LL, kb-1)), f(kb)) << nl;
    }
}
