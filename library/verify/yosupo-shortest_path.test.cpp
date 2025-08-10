#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "template"
#include "graphtemplate"
#include "dijkstra"
#include "dijkstrarestore"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    vi a = dijkstrarestore(g, s, t);
    if (2 <= a.size()) {
        cout << dijkstra(g, s, t) << sp << a.size()-1 << nl;
        rep(i, a.size()-1) {
            cout << a[i] << sp << a[i+1] << nl;
        }
    } else {
        cout << -1 << nl;
    }
}