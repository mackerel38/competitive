#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"
#include "template"
#include "graphtemplate"
#include "dijkstra"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, s; cin >> n >> m >> s;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    vll d = dijkstra(g, s);
    range(i, d) {
        if (i == numeric_limits<ll>::max()) {
            cout << "INF" << nl;
        } else {
            cout << i << nl;
        }
    }
}