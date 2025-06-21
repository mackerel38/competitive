#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); rep1(i, n-1) cin >> a[i];
    rep1(i, n-1) a[i] += a[i-1];
    rep(i, n) {
        rep(j, n-i-1) {
            int k = i + j;
            cout << a[k+1] - a[i] << sp;
        }
        cout << nl;
    }
}