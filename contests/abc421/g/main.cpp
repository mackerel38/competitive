#include "template"
#include "atcoder/mincostflow"
using namespace atcoder;

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    vpi b(m); cin >> b;
    vll d(n); d[0] = a[0];
    rep1(i, n-1) d[i] = a[i] - a[i-1];
    int S = n+1, T = n+2;
    mcf_graph<int, ll> g(n+3);
    ll cn = 0;
    rep(i, n) {
        if (0 < d[i]) {
            g.add_edge(S, i, d[i], 0);
        } elif (d[i] < 0) {
            g.add_edge(i, T, -d[i], 0);
            cn += -d[i];
        }
    }
    range(i, b) {
        auto [l, r] = i; l--;
        g.add_edge(r, l, inf, 1);
    }
    g.add_edge(S, n, inf, 0);
    auto [f, cost] = g.flow(S, T, cn);
    cout << (f==cn ? cost : -1) << nl;
}