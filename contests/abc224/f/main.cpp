#include "template"
#include "autodp/sequensedp"
using mint = modint998244353;
mint naive(const string& s) {
    int n = s.size();
    mint re = 0;
    rep(i, 1<<(n-1)) {
        mint c = 0, v = 0;
        rep(j, n) {
            c *= 10; c += s[j] - '0';
            if (j==n-1 || bit(i, j)) {
                v += c;
                c = 0;
            }
        }
        re += v;
    }
    return re;
}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    // embed_coefs<mint, naive>(10);
    str s; cin >> s;
    vec<mint> a(s.size());
    rep(i, s.size()) a[i] = s[i] - '0';
    cout << solvedp<mint>(a).val() << nl;
}