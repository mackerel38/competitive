#include "template"
#include "UnionFind"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, n; cin >> h >> w >> n;
    vpi a(n); cin >> a;
    rep(i, n) a[i].fi--;
    rep(i, n) a[i].se--;
    map<pi, int> m;
    rep(i, n) m[a[i]] = i;
    vvi f(w);
    rep(i, n) f[a[i].se].pb(a[i].fi);
    range(i, f) Sort(i);
    vec<pair<int, pi>> e;
    rep(i, w) {
        rep1(j, f[i].size()-1) e.pb({f[i][j]-f[i][j-1]-1, {m[{f[i][j], i}], m[{f[i][j-1], i}]}});
        if (i == 0) continue;
        rep(j, f[i].size()) {
            int x = f[i][j];
            int p = upper_bound(all(f[i-1]), x) - f[i-1].begin();
            if (p < (int)f[i-1].size()) e.pb({f[i-1][p]-f[i][j], {m[{f[i][j], i}], m[{f[i-1][p], i-1}]}});
            if (0 < p) e.pb({f[i][j]-f[i-1][p-1], {m[{f[i][j], i}], m[{f[i-1][p-1], i-1}]}});
        }
    }
    Sort(e);
    debug(e);
    UnionFind uf(n);
    int size = n;
    range(i, e) {
        auto [d, p] = i;
        if (uf.merge(p.fi, p.se)) size--;
        if (size == 1) {
            cout << d << nl;
            return;
        }
    }
    cout << -1 << nl;
}