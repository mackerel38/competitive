#include "template"
#include "autodp/stringdp"
using mint = modint998244353;
mint naive(const string& s) {
    int n = s.size();
    vi a(n), b(n);
    rep(i, n) {
        int x = s[i] - '0';
        a[i] = x % 3;
        b[i] = x / 3;
    }
    mint ans = 0;
    rep(i, n) if (b[i] == 0) {
        loop(j, i+1, n) if (b[j] == 1) {
            loop(k, j+1, n) if (b[k] == 2) {
                rep(t, 4) {
                    if (a[i]!=t && a[j]!=t && a[k]!=t) {
                        ans += t;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    // embed_coefs<mint, naive>(9);
    int n; cin >> n;
    vi a(n); cin >> a;
    str s; cin >> s;
    str t;
    rep(i, n) {
        int x = a[i];
    }
}