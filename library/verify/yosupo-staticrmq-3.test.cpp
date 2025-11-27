#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "template"
#include "lazysegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    lazysegtree<int, [](int x, int y){ return min(x, y); }, [](){ return numeric_limits<int>::max(); }, int, [](int x, int y){ return min(x, y); }, [](int x, int y){ return min(x, y); }, [](){ return numeric_limits<int>::max(); }> seg(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << seg.prod(l, r) << nl;
    }
}