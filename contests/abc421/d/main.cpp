#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll r, c, R, C; cin >> r >> c >> R >> C;
    ll n, m, l; cin >> n >> m >> l;
    vec<pair<char, ll>> s(m), t(l); cin >> s >> t;
    int st=0, tt=0;
    rep1(i, m-1) s[i].se += s[i-1].se;
    rep1(i, l-1) t[i].se += t[i-1].se;
    ll ans = 0;
    while (st<m || tt<l) {
        if (r==R && c==C) {
        }
    }
}