#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vi ans;
    int k = 1;
    rep(i, 3) {
        rep1(j, 100) {
            ans.pb({j*k});
        }
        k *= 100;
    }
    cout << ans.size() << nl << ans;
}