#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "template"
#include "dynamicUnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    dynamicUnionFind uf(n);
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            uf.merge(y, z);
        } else {
            cout << uf.same(y, z) << nl;
        }
    }
}