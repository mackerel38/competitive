#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    ld ans = 0;
    int n = s.size();
    rep(i, n) rep(j, n) if (2 <= j - i) if (s[i] == 't' && s[j] == 't') {
        int cnt = 0;
        for (int k=i+1; k<j; k++) {
            if (s[k] == 't') cnt++;
        }
        chmax(ans, 1.*cnt/(j-i-1));
    }
    cout << ans << nl;
}