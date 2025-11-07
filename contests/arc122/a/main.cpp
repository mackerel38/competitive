#include "template"
#include "autodp/sequensedp"
using mint = modint1000000007;
mint naive(const string& s) {
    int n = s.size();
    mint re = 0;
    rep(i, 1<<(n-1)) if (0 == (i & (i<<1))) {
        int v = s[0] - '0';
        rep(j, n-1) {
            if (bit(i, j)) v -= s[j+1] - '0';
            else v += s[j+1] - '0';
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
    // embed_coefs<mint, naive>(2);
    int n; cin >> n;
    vec<mint> a(n);
    range(i, a) { int x; cin >> x; i = x; }
    cout << solvedp<mint>(a).val() << nl;
}