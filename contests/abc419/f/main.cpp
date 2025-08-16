#include "template"
#include "modint"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, l; cin >> n>> l;
    vec<str> s(n); cin >> s;
    vec<str> st;
    st.pb("");
    range(i, s) rep1(j, i.size()) st.pb(i.substr(0, j));
    uniq(st);
    int m = st.size();
    vi a(m);
    rep(i, m) rep(j, n) {
        if (s[j].size() <= st[i].size() && st[i].substr(st[i].size()-s[j].size()) == s[j]) {
            a[i] |= (1 << j);
        }
    }
    // 背に
    vvi nex(m, vi(26));
    rep(i, m) {
        rep(j, 26) {
            str t = st[i] + (char)('a' + j);
            while (!t.empty() && st.end() <= find(all(st), t)) t.erase(t.begin());
            nex[i][j] = find(all(st), t) - st.begin();
        }
    }
    vec<vec<mint>> dp(m, vec<mint>(1<<n));
    vec<vec<mint>> ndp(m, vec<mint>(1<<n));
    dp[0][0] = 1;
    rep(i, l) {
        ndp.assign(m, vec<mint>(1<<n));
        rep(j, m) rep(k, 1<<n) {
            rep(c, 26) {
                int J = nex[j][c];
                int K = k | a[J];
                ndp[J][K] += dp[j][k];
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    rep(i, m) ans += dp[i].back();
    cout << ans << nl;
}