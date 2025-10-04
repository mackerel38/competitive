#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    int k = 1;
    rep1(i, n) {
        k *= -1;
        ans += k * i * i * i;
    }
    cout << ans << nl;
}