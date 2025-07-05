#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    deque<pll> qu;
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            ll y, z; cin >> y >> z;
            qu.pb({z, y});
        } else {
            ll y; cin >> y;
            ll ans = 0;
            while (0 < y) {
                auto [v, c] = qu.front();
                qu.pop_front();
                if (c <= y) {
                    ans += v * c;
                    y -= c;
                } else {
                    ans += v * y;
                    qu.push_front({v, c - y});
                    y = 0;
                }
            }
            cout << ans << nl;
        }
    }
}