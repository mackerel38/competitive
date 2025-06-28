#include "template"
#include "prime"
#include "modint"

int main() { IO();
    int T=1;
    setmod(1000000007);
    buildfac(2000000);
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m; cin >> n >> m;
    if (m == 1) {
        cout << 1 << nl;
        return;
    }
    vll f; factorize(m, f); Sort(f);
    vll cnt;
    int c = 1, p = f[0];
    rep1(i, f.size()-1) {
        if (p != f[i]) {
            cnt.pb(c);
            c = 0;
        }
        c++;
        p = f[i];
    } cnt.pb(c);
    mint ans = 1;
    range(i, cnt) {
        ans *= comb(n+i-1, i);
    }
    cout << ans << nl;
}