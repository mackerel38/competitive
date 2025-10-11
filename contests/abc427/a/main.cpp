#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str s; cin >> s; n = (int)s.size();
    rep(i, n/2) cout << s[i];
    rep1(i, n/2) cout << s[i+n/2];
    cout << nl;
}