#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "template"
#include "scc"
#include "graphtemplate"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, true, false> g(n);
    g.read(m, 0);
    vvi h = scc(g);
    cout << h.size() << nl;
    range(i, h) {
        cout << i.size() << sp;
        cout << i;
    }
}