#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, k; cin >> n >> k;
    str s; cin >> s;
    int ans = 0;
    rep(i, n-k+1) {
        int cnt = 0;
        rep(I, n-k+1) {
            bool flag = true;
            rep(j, k) {
                if (s[i+j] != s[I+j]) flag = false;
            }
            if (flag) cnt++;
        }
        chmax(ans, cnt);
    }
    cout << ans << nl;
    vec<str> ans2;
    rep(i, n-k+1) {
        int cnt = 0;
        rep(I, n-k+1) {
            bool flag = true;
            rep(j, k) {
                if (s[i+j] != s[I+j]) flag = false;
            }
            if (flag) cnt++;
        }
        if (ans == cnt) {
            str t = "";
            rep(j, k) t += s[i+j];
            ans2.pb(t);
        }
    }
    uniq(ans2);
    cout << ans2;
}