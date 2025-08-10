#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja"
#include "template"
#include "graphtemplate"
#include "kruskal"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, false, true> g(n);
    g.read(m, 0);
    cout << kruskal(g).sumcost << nl;
}