#include "template"
#include "autodp/treedp"
using mint = modint1000000007;
template <class T> inline T getb(T set, int i) { return (set >> i) & T(1); }
mint naive(const vi& par) {
	int n = par.size() + 1;
	ll res = 0;
	rep(set, 1<<n) {
		if (bit(set, 0)) continue;
		bool ok = true;
		rep1(i, n-1) {
			if (bit(set, i) && bit(set, par[i - 1])) {
				ok = false;
				break;
			}
		}
		if (ok) res++;
	}
	return res;
}

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    // embed_coefs<mint, naive>();
    int n; cin >> n;
    vvi g(n);
    rep(i, n-1) {
        int x, y; cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    auto dp = solvedp<mint>(g, 0);
    cout << dp[0].val() << nl;
}