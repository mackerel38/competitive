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
    vi p(n);
    rep(i, m) {
        int zero=0, one=0;
        rep(j, n) {
            if (s[j][i] == '0') zero ++;
            else one++;
        }
        if (zero < one) {
            rep(j, n) {
                if (s[j][i] == '0') p[j]++;
            }
        } else {
            rep(j, n) {
                if (s[j][i] == '1') p[j]++;
            }
        }
    }
    int M = Max(p);
    rep(i, n) if (M == p[i]) cout << i+1 << sp;
    cout << nl;
}