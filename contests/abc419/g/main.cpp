#include "template"
#include "graphtemplate"
#include "UnionFind"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, false, false> g(n); g.read(m);
}