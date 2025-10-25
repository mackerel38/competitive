#include "template"
#include "segtree"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
struct S {
    bool flag = false;
    vi l, r;
    vvi d;
};
S op(S a, S b) {
    if (!a.flag) return b;
    if (!b.flag) return a;
    vvi d(3, vi(3, inf));
    rep(i, 3) rep(j, 3) rep(k, 3) if (a.r[k] == 0 && b.l[k] == 0)chmin(d[i][j], 1+a.d[i][k] + b.d[k][j]);
    return S{true, a.l, b.r, d};
}
S e() { return {false, vi(), vi(), vvi()}; }
void solve() {
    int n; cin >> n;
    vec<str> s(3); cin >> s;
    int q; cin >> q;
    vec<S> a(n);
    rep(i, n) {
        vi l(3), r(3); vvi d(3, vi(3, inf));
        rep(j, 3) {
            if (s[j][i] == '#') {
                l[j] = r[j] = 1;
            } else {
                d[j][j] = 0;
            }
        }
        rep(j, 3) rep(k, 3) {
            bool ok = true;
            for (int x = min(j, k); x <= max(j, k); x++) {
                if (s[x][i] == '#') ok = false;
            }
            if (ok) {
                d[j][k] = d[k][j] = abs(j - k);
            }
        }
        a[i] = S{true, l, r, d};
    }
    segtree<S, op, e> seg(a);
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        s[x][y] = (s[x][y] == '#' ? '.' : '#');
        vi l(3), r(3); vvi d(3, vi(3, inf));
        rep(j, 3) {
            if (s[j][y] == '#') {
                l[j] = r[j] = 1;
            } else {
               d[j][j] = 0;
            }
        }
        rep(j, 3) rep(k, 3) {
            bool ok = true;
            for (int z = min(j, k); z <= max(j, k); z++) {
                if (s[z][y] == '#') ok = false;
            }
            if (ok) {
                d[j][k] = d[k][j] = abs(j - k);
            }
        }
        seg.set(y, S{true, l, r, d});
        S re = seg.all_prod();
        cout << (re.d[0][2] == inf ? -1 : re.d[0][2]) << nl;
    }
}