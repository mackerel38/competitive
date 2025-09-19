#include "template"
#include "graphtemplate"
#include "scc"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpll a(n); cin >> a;
    vll b;
    rep(i, n) {
        b.pb(a[i].fi);
        b.pb(a[i].se);
    }
    Sort(b);
    rep(i, n) {
        a[i].fi = lower_bound(all(b), a[i].fi)-b.begin();
        a[i].se = lower_bound(all(b), a[i].se)-b.begin();
    }
    debug(a);
    vi c(2*n);
    rep(i, n) c[a[i].fi] = c[a[i].se] = i;
    debug(c);
    graph<int, true, false> g(n);
    rep(i, n) {
        auto [x, y] = a[i];
        if (abs(x-y) == 1) continue;
        if (x < y) {
            int j = c[x+1];
            auto [X, Y] = a[j];
            if (x+1 == X) g.add_edge(j, i);
            else g.add_edge(i, j);
            j = c[y-1];
            X = a[j].fi; Y = a[j].se;
            if (y-1 == Y) g.add_edge(i, j);
            else g.add_edge(j, i);
            if (0<x) {
                j = c[x-1];
            X = a[j].fi; Y = a[j].se;
                if (X < Y )
            }
        } else {
            int j = c[x-1];
            auto [X, Y] = a[j];
            if (x-1 == X) g.add_edge(j, i);
            else g.add_edge(i, j);
            j = c[y+1];
            X = a[j].fi; Y = a[j].se;
            if (y+1 == Y) g.add_edge(i, j);
            else g.add_edge(j, i);
        }
    }
    vi ans;
    vvi s = scc(g);
    debug(s);
    if ((int)s.size() != n) No;
    else {
        Yes;
        rep(i, n) cout << s[i][0]+1 << sp;
    }
    cout << nl;
}