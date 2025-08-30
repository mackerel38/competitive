#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    ll ans = INF;
    {
        ll ans2 = 0;
        int a=0;
        rep(i, 2*n) {
            if (s[i] == 'A') {
                ans2 += abs(a - i);
                a += 2;
            }
        }
        chmin(ans, ans2);
    }
    {
        ll ans2 = 0;
        int a=1;
        rep(i, 2*n) {
            if (s[i] == 'A') {
                ans2 += abs(a - i);
                a += 2;
            }
        }
        chmin(ans, ans2);
    }
    cout << ans << nl;
}