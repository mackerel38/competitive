#define PROBLEM "https://judge.yosupo.jp/problem/minimum_steiner_tree"
#include "template"
#include "graphtemplate"
#include "minimumsteinertree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false, true> g(n);
    g.read(m, 0);
    int k; cin >> k;
    vi a(k); cin >> a;
    graph<ll, false, true> t = minimumsteinertree(g, a);
    cout << t.sumcost << sp << t._edges.size() << nl;
    range(e, t._edges) cout << e.id << sp;
    cout << nl;
}