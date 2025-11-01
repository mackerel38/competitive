#include "template"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vec<str> s(n); cin >> s;
    vvi a;
    rep(i, n-m+1) rep(j, n-m+1) {
        vi x(m);
        rep(I, m) {
            rep(J, m) {
                x[I] = x[I]*2 + (s[i+I][j+J]=='#');
            }
        }
        a.pb(x);
    }
    uniq(a);
    cout << a.size() << nl;
}