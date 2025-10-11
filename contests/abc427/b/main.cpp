#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n+1); a[0] = 1;
    rep1(i, n) {
        rep(j, i) {
            ll k = a[j];
            while (0 < k) {
                a[i] += k % 10;
                k /= 10;
            }
        }
    }
    cout << a[n] << nl;
}