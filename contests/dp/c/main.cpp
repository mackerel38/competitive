#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    ll a=0, b=0, c=0;
    rep(i, n) {
        int A, B, C; cin >> A >> B >> C;
        ll na = A+max(b, c), nb = B+max(a, c), nc=C+max(a, b);
        a = na; b = nb; c = nc;
    }
    cout << Max(a, b, c) << nl;
}