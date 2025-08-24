#include "template"
#include "UnionFind"

int main() {
    IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    vi a(n);
    vi b(n, 1);
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y, z; cin >> y >> z; y--; z--;
            if (uf.same(y, z)) continue;
            int t = a[uf.root(y)] + a[uf.root(z)];
            uf.merge(y, z); a[uf.root(y)] = t;
        } elif (x == 2) {
            int y; cin >> y; y--;
            a[uf.root(y)] += b[y];
            b[y] *= -1;
        } else {
            int y; cin >> y; y--;
            YN(a[uf.root(y)]);
        }
        debug(a);
    }
}