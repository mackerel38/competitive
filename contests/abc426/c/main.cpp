#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    pqg<pi> qu;
    rep(i, n) qu.push({i+1, 1});
    while (q--) {
        int x, y; cin >> x >> y;
        int ans = 0;
        while (!qu.empty() && qu.top().fi <= x) {
            auto [z, w] = qu.top(); qu.pop();
            ans += w;
        }
        qu.push({y, ans});
        cout << ans << nl;
    }
}