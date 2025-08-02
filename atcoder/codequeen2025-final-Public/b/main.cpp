#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, s; cin >> n >> s;
    ll ans = 0;
    map<int, int> cnt;
    rep(i, n) {
        int x; cin >> x;
        if (cnt.count(s-x)) {
            ans += cnt[s-x];
        }
        cnt[x]++;
    }
    cout << ans << nl;
}