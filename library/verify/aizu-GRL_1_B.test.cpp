#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"
#include "template"
#include "bellmanford"
#include "graphtemplate"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, s; cin >> n >> m >> s;
    graph<ll, true, true> g(n);
    g.read(m, 0);
    vll d = bellmanford(g, s);
    if (d[s] < 0) {
        cout << "NEGATIVE CYCLE" << nl;
    } else {
        for (int i=0; i<n; i++) {
            if (INF < d[i]) cout << "INF" << nl;
            else cout << d[i] << nl;
        }
    }
}