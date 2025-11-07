#include "template"
#include "autodp/stringdp"
using mint = modint998244353;
mint naive(const str& s) {
    int n = s.size();
    if (n == 0) return 0;
    str t, u;
    range(c, s) {
        int x = c - '0';
        t += '0' + x%3;
        u += '0' + x/3;
    }
    str re = "";
    vi m;
    rep(i, n) if (t[i] == '2') m.pb(i);
    rep(i, 1<<(m.size())) {
        str T = t;
        rep(j, m.size()) {
            T[m[j]] = '0' + bit(i, j);
        }
        if (T <= u) chmax(re, T);
    }
    if (re == "") return -1;
    return stoll(re, nullptr, 2);
}
int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    // embed_coefs<mint, naive>(6);
    str s; cin >> s;
    range(c, s) if (c == '?') c = '2';
    ll n; cin >> n;
    str t(60, '0');
    rep(i, s.size()) {
        t[60-s.size()+i] = s[i];
    }
    rep(i, 60) {
        t[60-i-1] += 3*(n&1);
        n >>= 1;
    }
    cout << solvedp<ll>(t) << nl;
}