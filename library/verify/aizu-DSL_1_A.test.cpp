#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "template"
#include "UnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) uf.merge(u, v);
        else cout << uf.same(u, v) << endl;
    }
}