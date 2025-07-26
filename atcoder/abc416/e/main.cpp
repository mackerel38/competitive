#include "template"
#include "warshallfloyd"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n, m; cin >> n >> m;
    vvll g(n, vll(n, INF));
    rep(i, n) g[i][i] = 0;
    rep(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    ll k, t; cin >> k >> t;
    vi p(n); rep(i, k) { int x; cin >> x; x--; p[x] = 1; }
    rep(i, n) rep(j, n) if (i!=j && p[i] && p[j]) chmin(g[i][j], t);
    ll q; cin >> q;
    vvll d = g; rep(k, n) rep(i, n) rep(j, n) chmin(d[i][j], d[i][k] + d[k][j]);
    vll d2(n, INF);
    rep(i, n) rep(j, n) if (p[j] && d[i][j]!=INF) chmin(d2[i], d[i][j]);
    while (q--) {
        debug(d);
        ll x; cin >> x;
        if (x == 1) {
            ll a, b, c; cin >> a >> b >> c;
            --a; --b;
            if (c < d[a][b]) {
                d[a][b] = d[b][a] = c;
                rep(i, n) rep(j, n) chmin(d[i][j], d[i][a] + d[a][b] + d[b][j]);
                rep(i, n) rep(j, n) chmin(d[i][j], d[i][b] + d[b][a] + d[a][j]);
            }
        } elif (x == 2) {
            ll a; cin >> a;
            --a;
            p[a] = 1;
            rep(i, n) rep(j, n) if (p[j] && d[i][j]!=INF) chmin(d2[i], d[i][j]);
            rep(i, n) rep(j, n) chmin(d[i][j], d2[i] + t + d2[j]);
        } else {
            ll ans = 0;
            range(i, d) range(j, i) if (j < INF) ans += j;
            cout << ans << nl;
        }
    }
}